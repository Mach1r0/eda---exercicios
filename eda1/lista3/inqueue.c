#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enqueue(celula *queue, int data) {
    celula *new_node = (celula *)malloc(sizeof(celula));

    if (new_node == NULL) {
        // Memory allocation failed
        return queue; // Return the original queue unchanged
    }
    //init the queue
    new_node->dado = data;
    new_node->prox = NULL;

    //if the queue is empty, the new node return;
    if (queue == NULL) {
        // If the queue is empty, the new node becomes the head
        return new_node;
    }

    // Find the last node in the queue
    celula *current = queue;
    while (current->prox != NULL) {
        current = current->prox;
    }
    // Add the new node to the end of the queue
    current->prox = new_node;
    return queue; // Return the original head of the queue
}
