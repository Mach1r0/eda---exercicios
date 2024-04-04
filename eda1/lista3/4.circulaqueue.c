#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x) {
    if (f->u == f->N) { // If the end of the queue reaches the end of the array
        if (f->p > 0) { // If there's space at the start of the queue
            f->u = 0; // Move the end of the queue to the start of the array
        } else { // If there's no space at the start of the queue
            int new_size = f->N * 2; // Quadruple the size
            int *new_data = (int *) realloc(f->dados, new_size * sizeof(int));
            if (new_data == NULL) {
                return 0;
            }
            f->dados = new_data;
            f->N = new_size;
        }
    }
    f->dados[f->u] = x;
    f->u = (f->u + 1) % f->N;
    return 1;
}