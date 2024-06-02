#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *inserir(no *r, int x) {
    if (r == NULL) {
        r = (no*)malloc(sizeof(no));
        r->chave = x;
        r->esq = NULL;
        r->dir = NULL;
    } else if (x < r->chave) {
        r->esq = inserir(r->esq, x);
    } else if (x > r->chave) {
        r->dir = inserir(r->dir, x);
    }
    return r;
}