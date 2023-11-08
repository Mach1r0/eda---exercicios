#include<stdio.h>
#include<stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

int empilha(celula *p, int x){
    celula *temp = malloc(sizeof(celula));
    if (temp == NULL){
        return 0;
    }
    temp->dado = x;
    temp->prox = p->prox;
    p->prox = temp;
    return 1;
}