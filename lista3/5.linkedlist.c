#include <stdlib.h>

typedef struct cell {
    int data;
    struct cell *prox;
} cell;

cell *queue(cell *f, int x) {
    cell *new_node = (cell*) malloc(sizeof(cell));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = x;
    new_node->prox = NULL;
    if (f == NULL) {
        return new_node;
    }
    cell *aux = f;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = new_node;
    return f;
}