#include<stdio.h>
#include<stdlib.h>

typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;

void pre_ordem(no *raiz) {
    while (raiz != NULL) {
        if (raiz->esq == NULL) {
            printf("%d ", raiz->dado);
            raiz = raiz->dir;
        } else {
            no* current = raiz->esq;
            while (current->dir != NULL && current->dir != raiz) {
                current = current->dir;
            }

            if (current->dir == raiz) {
                current->dir = NULL;
                raiz = raiz->dir;
            } else {
                printf("%d ", raiz->dado);
                current->dir = raiz;
                raiz = raiz->esq;
            }
        }
    }
}