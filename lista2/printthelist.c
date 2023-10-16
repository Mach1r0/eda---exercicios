#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le) {
    celula *temp = le;
    temp = temp->prox;
    while (temp != NULL){
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    if (temp == NULL){
        printf("NULL\n");
    }
}

void imprime_rec (celula *le) {
    celula *temp = le;
    if (temp == NULL){
        printf("NULL\n");
        return;
    }
    if (temp ->dado != 0){
        printf("%d -> ", temp->dado);
    }
    imprime_rec(temp->prox);    
}
