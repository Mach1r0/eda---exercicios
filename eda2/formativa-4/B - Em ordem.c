#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int dado; 
    struct no *esq, *dir; 
} no;

void em_ordem(no *raiz) {
    no *current, *pre;

    if (raiz == NULL)
        return;

    current = raiz;
    while (current != NULL) {
        if (current->esq == NULL) {
            printf("%d ", current->dado);
            current = current->dir;
        } else {
            pre = current->esq;
            while (pre->dir != NULL && pre->dir != current)
                pre = pre->dir;

            if (pre->dir == NULL) {
                pre->dir = current;
                current = current->esq;
            } else {
                pre->dir = NULL;
                printf("%d ", current->dado);
                current = current->dir;
            }
        }
    }
}