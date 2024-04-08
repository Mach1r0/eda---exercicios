#include<stdio.h>
#include<stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    celula *temp = le->prox;
    while (temp != NULL && temp->dado != NULL){
        if (temp->dado == x ){
            return temp;
        }else{
          temp = temp->prox;
        }
    }
    return NULL;
}

celula *busca_rec (celula *le, int x){
    if(le == NULL) return NULL;
    if(le->dado == x) return le;
    else busca_rec(le->prox, x);
}