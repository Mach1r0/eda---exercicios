#include <stdio.h>

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