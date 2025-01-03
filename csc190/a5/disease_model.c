/* 
 * Ignacio Poggi, 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <string.h>

#include "disease_model.h"

static struct graph *create_graph(FILE *input_file);

struct graph *read_file(char *filename) {
     FILE *pop_data = fopen(filename, "r");
    
    if (pop_data == NULL) {
        perror("Cannot read graph input file.\n");
        
        exit(EXIT_FAILURE);
    }
    
    struct graph *g = create_graph(pop_data);
    
    fclose(pop_data);
    
    return g; 
}

static struct graph *create_graph(FILE *input_file) {
    /* Variables to hold the current line and actual size */
    char last_line[80] = {0};  /* Buffer to store the last line read */
    int max_id = -1;

    /* Read the file line by line up to 79 characters or until a newline is encountered */
    while (fscanf(input_file, "%79[^\n]\n", last_line) == 1) {
        /* The last_line buffer is updated with each new line */
    }

    /* Now, we extract the first number from the last line */
    sscanf(last_line, "%d", &max_id);
    
    /* Reset input file pointer */
    rewind(input_file);
    
    int graph_n = max_id + 1;
    
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    
    if (g == NULL) {
        perror("Cannot allocate memory for new graph.\n");
        
        exit(EXIT_FAILURE);
    }
    
    g->n = graph_n;
    
    /* Allocate a 1 x grid_size array to hold pointers to more arrays */
    g->connections = (int **)calloc(graph_n, sizeof(int *));
    
    if (g->connections == NULL) {
        perror("Cannot allocate memory for new array.");
        
        exit(EXIT_FAILURE);
    }
    
    /* Allocate each row in that column */
    for (int i = 0; i < graph_n; i++) {
        g->connections[i] = (int *)calloc(graph_n, sizeof(int));
        
        if (g->connections[i] == NULL) {
            perror("Cannot allocate memory for new array row.");
        
            exit(EXIT_FAILURE);
        }
    }
    
    int row = -1;
    int col = -1;
    
    /* Read the file line by line to set connections array relevant positions with 1 */
    while (fscanf(input_file, "%d, %d", &row, &col) == 2) {
        if (row >= 0 && row < graph_n && col >= 0 && col < graph_n) {
            g->connections[row][col] = 1;
        }
    }
    
    /* Set the remaining positions to 0 (no connection) */
    for (int i = 0; i < graph_n; i++) {
        for (int j = 0; j < graph_n; j++) {
            if (g->connections[i][j] != 1) {
                g->connections[i][j] = 0;
            }
        }
    }
    
    /* Set persons nodes array */
    g->nodes = (struct person **)malloc(sizeof(struct person *) * graph_n);
    
    if (g->nodes == NULL) {
        perror("Cannot allocate memory for new nodes array.");
        
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < graph_n; i++) {
        g->nodes[i] = (struct person *)malloc(sizeof(struct person));
        
        if (g->nodes[i] == NULL) {
            perror("Cannot allocate memory for new person.");
        
            exit(EXIT_FAILURE);
        }
        
         g->nodes[i]->id = i;
         g->nodes[i]->infect_count = -1;
         g->nodes[i]->status = 'S';
    }
    
    return g;
}

void print_stats(struct graph *pop) {
    int gn = pop->n;
    
    int s_count = 0;
    int i_count = 0;
    int v_count = 0;
    
    for (int i = 0; i < gn; i++) {
        switch (pop->nodes[i]->status) {
            case 'S':
                ++s_count;
                
                break;
            case 'I':
                ++i_count;
                
                break;
            case 'V':
                ++v_count;
                
                break;
            default:
                break;
        }
    }
    
    double s_percentage = (s_count * 100.0) / gn;
    double i_percentage = (i_count * 100.0) / gn;
    double v_percentage = (v_count * 100.0) / gn;
    
    printf("STATS: S %.1lf%, I %.1lf%, V %.1lf%; n = %d.\n", s_percentage, i_percentage, v_percentage, gn);
}

void print_graph(struct graph *pop) {
    int gn = pop->n;
    
    for (int j = 0; j < gn; j++) { 
        printf((j == gn - 1) ? "%d\t\tstatus\n" : (j == 0) ? "\t%d," : "%d,", j);
    }
    
    for (int i = 0; i < gn; i++) {
        printf("%d\t", i);
        
        for (int j = 0; j < gn; j++) { 
            printf((j == gn - 1) ? "%d\t" : "%d,", pop->connections[i][j]);
        }
        
        if (pop->nodes[i]->status == 'I') {
            printf("\t%c (%d)\n", pop->nodes[i]->status, pop->nodes[i]->infect_count);
        } else {
            printf("\t%c\n", pop->nodes[i]->status);
        }
    }
    
    printf("%s\n", "===============");
}

void seed_graph(struct graph **pop, int person_id) {
    if (pop != NULL) {
        int max_id = (*pop)->n - 1;
        
        if (0 <= person_id && person_id <= max_id) {
            struct person *p = (*pop)->nodes[person_id];
            
            if (p->status != 'I') {
                p->status = 'I';
                p->infect_count++;
            }
        }
    }
}

void propagate_once(struct graph **pop, double p_transmit) {
    if (pop != NULL) {
        int gn = (*pop)->n;
        
        for (int i = 0; i < gn; i++) {
            struct person *p = (*pop)->nodes[i];
            
            if (p->status == 'I') {
            
                int *p_connections = (*pop)->connections[i];
                
                 for (int j = 0; j < gn; j++) {
                    // Ensure we don't try to infect the person with themselves
                    if (i != j && p_connections[j] == 1) {
                        struct person *partner = (*pop)->nodes[j];
                        
                        // Only propagate the disease to susceptible people
                        if (partner->status == 'S') {
                            double prob_inf = (double)rand() / RAND_MAX;  // Random number between 0 and 1
                            
                            // Infect if the random value is less than the transmission probability
                            if (prob_inf < p_transmit) {
                                partner->status = 'I';
                            }
                        }
                    }
                }
               
                ++p->infect_count;
            }
        }
    }
}

void propagate_n_times(struct graph **pop, int n, double p_transmit) {
    if (pop != NULL) {
        for (int i = 0; i < n; i++) {
            propagate_once(pop, p_transmit);
            
            printf("%d - ", i);
            print_stats(*pop);
        }
    }
}

void remove_all(struct graph **pop) {
    if (pop != NULL) {
        int gn = (*pop)->n;
        
        for (int i = 0; i < gn; i++) {
            free((*pop)->nodes[i]);
            (*pop)->nodes[i] = NULL;
            
            free((*pop)->connections[i]);
            (*pop)->connections[i] = NULL;
        }
        
        free((*pop)->nodes);
        (*pop)->nodes = NULL;
        
        free((*pop)->connections);
        (*pop)->connections = NULL;
        
        free(*pop);
        *pop = NULL;
    }
}



void propagate_with_recovery(struct graph **pop, int n, double p_transmit, int time_to_recover) {
}


/*
 * It's a helper method for lab 10! (You won't need this for lab 9.)
 * Elizabeth has adapted this from
 * http://stackoverflow.com/questions/6127503/shuffle-array-in-c
 */
void shuffle(int *array, int size) {
	/* 
	 * shuffles an array of integers in place
	 * PRE: none
	 * POST: array is shuffled
     */
	if (size > 1) {
        for (int i = 0; i < size - 1; i++) {
		    int j = i + rand() / (RAND_MAX / (size - i) + 1);
		    
		    int t = array[j];
		    
		    array[j] = array[i];
		    array[i] = t;
		}
	}
}