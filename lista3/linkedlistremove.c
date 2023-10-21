#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;            
    struct celula *prox; 
} celula;

int desenfileira(celula *f, int *y) {     
    // Check if the queue is empty 
    if (f->prox == NULL) { 
        return 0;  // Queue is empty, no elements to dequeue.
    }

    celula *temp = f->prox; // Create a temporary pointer to the first cell in the queue.
    *y = temp->dado; // Save the data of the cell to be removed in the variable y.

    f->prox = temp->prox; // Update the front of the queue to point to the next cell.
    free(temp); // Free the memory of the cell being removed.

    return 1; // Return 1 to indicate that the removal was successful.
}