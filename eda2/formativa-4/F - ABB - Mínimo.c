#include <stdio.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *minimo(no *r) {
    if (r == NULL)
        return NULL;
    else if (r->esq == NULL)
        return r;
    else
        return minimo(r->esq);
}