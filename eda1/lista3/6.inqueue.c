#include <stdio.h>
#include <stdlib.h>

struct fila {
    int *dado;
    int N, p, u;
};

void resize(struct fila *f) {
    f->N *= 2;
    int *novo;
    novo = (int *)malloc(f->N * sizeof(int));
    for (int i = f->p; i < f->u; i++)
        novo[i] = f->dado[i];
    free(f->dado);
    f->dado = novo;
}

int enfileira(struct fila *f, int x) {
    if (f == NULL)
        return 0;
    if (f->u == f->N) {
        resize(f);
        if (f->dado == NULL) {
            return 0;
        }
    }
    f->dado[f->u] = x;
    f->u++;
    return 1;
}
