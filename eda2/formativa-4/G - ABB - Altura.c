#include <stdio.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

int altura(no *r) {
    if (r == NULL)
        return 0; 
    else {
        int he = altura(r->esq);
        int hd = altura(r->dir);
        if (he < hd) return hd + 1;
        else return he + 1;
    }
}