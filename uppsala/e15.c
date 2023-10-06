#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a doubly linked list node
struct Node {
    char *name;
    struct Node *prev;
    struct Node *next;
    char birthdate[11]; // Assuming birthdate format: YYYY-MM-DD
};

// Function to create a new node
struct Node *createNode(char *name, char *birthdate) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        perror("Memory allocation failed");

        exit(EXIT_FAILURE);
    }
    
    newNode->name = strdup(name);

    if (newNode->name == NULL) {
        perror("Memory allocation failed");

        exit(EXIT_FAILURE);
    }
    
    strncpy(newNode->birthdate, birthdate, sizeof(newNode->birthdate));

    newNode->birthdate[sizeof(newNode->birthdate) - 1] = '\0';

    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a node into the sorted list
void insertNode(struct Node **head, struct Node *newNode) {
    if (*head == NULL || strcmp((*head)->name, newNode->name) > 0) {
        newNode->next = *head;

        newNode->prev = NULL;

        if (*head != NULL) {
            (*head)->prev = newNode;
        }

        *head = newNode;
    } else {
        struct Node *current = *head;

        while (current->next != NULL && strcmp(current->next->name, newNode->name) < 0) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }

        current->next = newNode;
    }
}

// Function to print the list
void printList(struct Node *head) {
    struct Node *current = head;

    printf("Sorted List:\n");

    while (current != NULL) {
        printf("Name: %s, Birthdate: %s\n", current->name, current->birthdate);
        
        current = current->next;
    }
}

// Function to free memory allocated for the list
void freeList(struct Node *head) {
    struct Node *current = head;

    while (current != NULL) {
        struct Node *temp = current;

        current = current->next;

        free(temp->name);
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;
    char name[21];
    char birthdate[11];
    
    printf("Enter names and birthdates (YYYY-MM-DD) and enter 'Q' to quit:\n");
    
    while (1) {
        printf("Name: ");
        scanf("%20s", name);
        
        if (strcmp(name, "Q") == 0) {
            break;
        }
        
        printf("Birthdate (YYYY-MM-DD): ");
        scanf("%10s", birthdate);
        
        struct Node *newNode = createNode(name, birthdate);
        insertNode(&head, newNode);
    }
    
    printList(head);
    freeList(head);
    
    return 0;
}