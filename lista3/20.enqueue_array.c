#include <stdio.h>
#include <stdlib.h>

// Define a struct for the stack
typedef struct pilha {
    int *dados; // Pointer to the stack data
    int N;      // Current size of the stack
    int topo;   // Current top position of the stack
} pilha;

// Function to resize the stack
int resize(pilha *p) {
    int new_size = p->N * 2;  // Double the current size
    int *new_data = (int *)realloc(p->dados, new_size * sizeof(int)); // Allocate new space for the stack
    if (new_data == NULL) {
        return 0; // Allocation failed
    }
    p->dados = new_data; // Update the data pointer to the new space
    p->N = new_size;     // Update the size of the stack
    return 1; // Successfully resized the stack
}

// Function to push an item onto the stack
int empilha(pilha *p, int x) {
    if (p->topo == p->N) {
        if (!resize(p)) {
            return 0; // Resize failed
        }
    }
    p->dados[p->topo] = x; // Assign the value 'x' to the current top position
    p->topo++; // Increment the top position
    return 1; // Successfully pushed an item onto the stack
}
