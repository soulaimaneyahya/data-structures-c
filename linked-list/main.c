#include <stdio.h>
#include <stdlib.h> // For malloc

// Define the Node structure
struct Node {
    int data;
    struct Node *next;
} *head = NULL; // Initialize head as NULL

// create a linked list from an array
void createNode(int A[], int n) {
    struct Node *nodeI, *nodeX;

    // Allocate memory for the head node and initialize it
    head = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    head->data = A[0];
    head->next = NULL;

    nodeI = head; // Point to the head node

    for (int i = 1; i < n; i++) {
        // Allocate memory for a new node
        nodeX = (struct Node *)malloc(sizeof(struct Node));

        if (nodeX == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        
        // Initialize the new node
        nodeX->data = A[i];
        nodeX->next = NULL;

        // Link the current node to the new node
        nodeI->next = nodeX;
        
        // Move the pointer to the new node
        nodeI = nodeX;
    }
}

// display the linked list
void displayList(struct Node *current) {
    printf("Linked List: ");

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    // Array to be converted into a linked list
    int A[] = {2, 3, 4, 5, 6};

    int length = sizeof(A) / sizeof(A[0]);

    // Create the linked list
    createNode(A, length);

    // Display the linked list
    displayList(head);

    return 0;
}
