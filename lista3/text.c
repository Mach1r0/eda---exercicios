#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y) {
    if (f->p == f->u) {
        if (f->p == NULL) {
            return 0;
        }
        *y = f->dados[f->p];
        free(f->dados);
        f->p = f->u = NULL;
    } else {
        *y = f->dados[f->p];
        f->p = (f->p + 1) % f->N;
    }
    return 1;
}
