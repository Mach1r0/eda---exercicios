#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *maximo(no *r) {
    if (r == NULL)
        return NULL;
    else if (r->dir == NULL)
        return r;
    else
        return maximo(r->dir);
}

no *remover(no *r, int x) {
    if (r == NULL)
        return NULL;
    else if (x < r->chave)
        r->esq = remover(r->esq, x);
    else if (x > r->chave)
        r->dir = remover(r->dir, x);
    else {
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            r = NULL;
        } else if (r->esq == NULL) {
            no *temp = r;
            r = r->dir;
            free(temp);
        } else if (r->dir == NULL) {
            no *temp = r;
            r = r->esq;
            free(temp);
        } else {
            no *temp = maximo(r->esq);
            r->chave = temp->chave;
            r->esq = remover(r->esq, temp->chave);
        }
    }
    return r;
}