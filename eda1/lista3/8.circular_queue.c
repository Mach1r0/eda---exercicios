#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v; // Array representing the queue
    int N; // Size of the queue
    int inicio, fim; // Pointers to the beginning and end of the queue
} fila;

// Enqueue an element x into the circular queue f. Returns 1 if successful, or 0 if the queue is full.
int enfileira(fila *f, int x) {
    if ((f->fim + 1) % f->N == f->inicio) return 0; // Queue is full
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;
    return 1;
}

// Dequeue an element from the circular queue f.
// Returns the dequeued element in y and 1 if the dequeue was successful, or 0 if the queue is empty.
int desenfileira(fila *f, int *y) {
    if (f->inicio == f->fim) return 0; // Queue is empty
    *y = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % f->N;
    return 1;
}
