// Multithreaded tree creation/traversal demo
// TODO: change this to use reader/writer locks

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_ {
	char *name;
	int num_children;
	struct Node_ *first_child;
	struct Node_ *next_child;
} Node;

typedef struct {
	Node *root;

	pthread_mutex_t lock;
} Tree;

Node *node_alloc(char *name)
{
	Node *node = malloc(sizeof(Node));
	node->name = name;
	node->num_children = 0;
	node->first_child = NULL;
	node->next_child = NULL;
	return node;
}

int read_count;
int write_count;
int debug;

static void *reader(void *arg) {
	Tree *tree = arg;

	char path[2048];

	for (int i = 0; i < read_count; i++) {
		pthread_mutex_lock(&tree->lock);

		Node *n = tree->root;
		strcpy(path, "");
		while (n->num_children > 0) {
			// Pick a random child
			int index = rand() % n->num_children;

			// Advance to that child
			n = n->first_child;
			for (int j = 0; j < index; j++) {
				n = n->next_child;
			}

			// Append the child's name to the path string
			strcat(path, "/");
			strcat(path, n->name);
		}

		if (debug) {
			printf("Reader: %s\n", path);
		}

		pthread_mutex_unlock(&tree->lock);
	}

	return NULL;
}

static void *writer(void *arg) {
	Tree *tree = arg;

	char path[2048];

	for (int i = 0; i < write_count; i++) {
		pthread_mutex_lock(&tree->lock);

		strcpy(path, "");

		Node *n = tree->root;

		// Repeatedly flip a coin.  Each time it comes up heads,
		// add a child to the current node and traverse into it.

		// Note that the first coin flip is rigged to always be heads.
		int flip = 1;

		while (flip != 0) {
	
			// Create a random name for the new node
			char *name = malloc(3);
			name[0] = "abcdefghijklmnopqrstuvwxyz"[rand() % 26];
			name[1] = "abcdefghijklmnopqrstuvwxyz"[rand() % 26];
			name[2] = '\0';
			//printf("name=%s\n", name);

			Node *child = n;
			Node *prev = NULL;

			// See if there is already a child with this name
			child = n->first_child;
			while (child != NULL) {
				if (strcmp(child->name, name) == 0) {
					// Found a node with the same name
					free(name);
					break;
				} else {
					// Advance to next node
					prev = child;
					child = child->next_child;
				}
			}

			if (child == NULL) {
				// Create a new child
				Node *new_child = node_alloc(name);

				// Append new child to end of list
				if (prev == NULL) {
					n->first_child = new_child;
				} else {
					prev->next_child = new_child;
				}

				child = new_child;

				n->num_children++;
			}

			// Append child's name to path
			strcat(path, "/");
			strcat(path, child->name);

			// Traverse into the child node
			n = child;

			// Next coin flip
			flip = (rand() >> 3) & 1;
		}

		pthread_mutex_unlock(&tree->lock);

		if (debug) {
			printf("Writer: %s\n", path);
		}
	}

	return NULL;
}

int main(int argc, char **argv) {
	if (argc < 3) {
		fprintf(stderr, "Usage: rwlock <num readers> <read count> [<debug>]\n");
		exit(1);
	}

	int num_readers = atoi(argv[1]);
	read_count = atoi(argv[2]);
	write_count = read_count / 10;

	if (argc > 3) {
		debug = atoi(argv[3]);
	}

	Tree *tree = malloc(sizeof(Tree));
	tree->root = node_alloc(strdup(""));
	pthread_mutex_init(&tree->lock, NULL);

	pthread_t writer_thread;
	pthread_t *reader_threads = malloc(num_readers * sizeof(pthread_t));

	// Create reader and writer threads
	pthread_create(&writer_thread, NULL, writer, tree);
	for (int i = 0; i < num_readers; i++) {
		pthread_create(&reader_threads[i], NULL, reader, tree);
	}

	// Wait for reader and writer threads to finish
	pthread_join(writer_thread, NULL);
	for (int i = 0; i < num_readers; i++) {
		pthread_join(reader_threads[i], NULL);
	}

	printf("Done\n");
	return 0;
	
	
}
