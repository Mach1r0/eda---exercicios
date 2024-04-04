#include<stdio.h>
#include<stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

void resize(fila *f, int new size){
    if (new size <= 0)
        return;

    int *new_v = malloc(new size * sizeof(int));
    if (new_v == NULL)
        return;

        int i = f->p;
    int j = 0;

    while (i != (f->u + 1) % f->N) {
        new_v[j] = f->dados[i];
        i = (i + 1) % f->N;
        j++;
    }

    free(f->dados);
    f->dados = new_v;
    f->N = new_size;
    f->p = 0;
    f->u = j - 1;
}

int enfileira(fila *f, int x) {
    if (f->u == f->N - 1) {
        int new_size = (f->N == 0) ? 1 : f->N * 2; 
        resize(f, new_size);
    }

    f->dados[(f->u + 1) % f->N] = x;
    f->u = (f->u + 1) % f->N;
    return 1;
}

