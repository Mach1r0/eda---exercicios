#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void enfileira (celula **f, int x){
    celula *temp = malloc(sizeof(celula));
    temp->prox = (*f)->prox;
    (*f)->prox = temp;
    (*f)->dado = x;
    (*f) = temp;
}

int desenfileira(celula *f, int *y){
    celula *temp = f->prox;
    *y = temp->dado;
    if  (f->prox == f)
     return 0;

    else
         f->prox = temp->prox;
    return 1;
}