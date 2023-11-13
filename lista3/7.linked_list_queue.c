#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira(celula **f, int x) {
    celula *temp = (celula*)malloc(sizeof(celula));
    if(temp == NULL) {
        return;
    }
    temp->dado = x;
    temp->prox = (*f == NULL) ? temp : (*f)->prox;
    if(*f != NULL) {
        (*f)->prox = temp;
    }
    *f = temp; // The new node is now the rear of the queue.
}

int desenfileira(celula **f, int *y) {
    if(*f == NULL) {
        return 0; // The queue is empty.
    }
    celula *front = (*f)->prox;
    *y = front->dado;
    (*f)->prox = (front == *f) ? NULL : front->prox;
    free(front);
    return 1; // The dequeue operation was successful.
}