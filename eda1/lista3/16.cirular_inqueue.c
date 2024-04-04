#include<stdio.h>
#include<stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y) {
    if (f->p == f->u) return 0; //empty list 
    *y = f->dados[f->p]; //saving first data to variable y 
    f->p = (f->p + 1) % f->N; // increment fist data to next position
    return 1;  
}
