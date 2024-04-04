#include<stdio.h>
#include<stdlib.h>

typedef struct fila {
int *dados;
int N, p, u;
} fila;

int desenfileira (fila *f, int *y){ //take the argument of the queue and the value to be removed
    if (f->p == f->u){ // if the first elemente is equal to last element the queue is empty
        if(f->p == NULL) return 0; // if the first element if null the queue is empty

        *y = f->dados[f->p]; // the value of the first element is the value of the argument
        free(f->dados); // free the memory of the queue
        f->p = f->u = NULL; // change the pointer of the first and last element to null
    } else{ // if the queue is not empty
        *y = f->dados[f->p]; // the value of the first element is the value of the argument
        f->p = (f->p + 1) % f->N; // change the pointer of the first element to the next element
    }
    return 1; // return 1 if the element was removed
}

