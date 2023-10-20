#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
typedef struct celula {
    int dado;           // Integer data stored in the node
    struct celula *prox;  // Pointer to the next node
} celula;

// Function to remove the node after a given node 'p' in the linked list
int remove_depois(celula *p) {
    if (p != NULL && p->prox != NULL) {
        celula *temp = p->prox;  // Store a reference to the node to be removed
        p->prox = temp->prox;    // Update the 'prox' pointer to skip the node to be removed
        free(temp);              // Free the memory of the removed node
        return 1;                // Indicate that the removal was successful
    }
    return 0;                    // Indicate that the removal was not possible
}

// Function to remove the first occurrence of an element 'x' from the linked list
void remove_elemento(celula *le, int x) {
    celula *prev = le;      // Initialize a pointer to the list's head
    celula *current = le->prox;  // Initialize a pointer to the first node in the list

    if (current == NULL) {
        return;  // Return if the list is empty
    }

    if (current->dado == x) {
        le->prox = current->prox;  // Update the head's 'prox' pointer to skip the matching node
        free(current);             // Free the memory of the removed node
        return;
    }

    // Traverse the list to find the node containing the element 'x'
    while (current != NULL && current->dado != x) {
        prev = current;
        current = current->prox;
    }

    if (current != NULL) {
        prev->prox = current->prox;  // Update the previous node's 'prox' pointer to skip the matching node
        free(current);               // Free the memory of the removed node
    }
}

// Function to remove all occurrences of an element 'x' from the linked list
void remove_todos_elementos(celula *le, int x) {
    celula *prev = le;      // Initialize a pointer to the list's head
    celula *current = le->prox;  // Initialize a pointer to the first node in the list

    while (current != NULL) {
        if (current->dado == x) {
            prev->prox = current->prox;  // Update the previous node's 'prox' pointer to skip the matching node
            celula *temp = current;      // Store a reference to the node to be removed
            current = current->prox;    // Move to the next node
            free(temp);                  // Free the memory of the removed node
        } else {
            prev = current;             // Move the 'prev' pointer
            current = current->prox;    // Move to the next node
        }
    }
}
