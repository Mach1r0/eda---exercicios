#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void em_ordem(no *raiz) {
    if (raiz == NULL) // Empty tree
        return;

    no *stack[500]; // Declare the stack.
    int top = -1; // Declare the top of the stack, -1 means an empty stack.

    no *current = raiz; // Use a temporary variable to traverse the stack.

    while (current != NULL || top != -1) { // While the tree is not empty, or our current is not null.
        while (current != NULL) { // Traverse the tree.
            stack[++top] = current; // Add the current node to the top of the stack.
            current = current->esq; // Move the current pointer to the left.
        }
        current = stack[top--]; // Decrement the top if we have traversed all nodes to the left.
        printf("%d ", current->dado); // Print the value of the current node.
        current = current->dir; // Move the pointer to traverse the right side.
    }
}
