#include<stdio.h>
#include<stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int resize(fila* f) {
    int new_size = f->N * 2;  // Double the current size
    int* new_data = (int*)realloc(f->dados, new_size * sizeof(int)); //allocate new space for new list
    if (new_data == NULL) { 
        return 0; // Allocation failed
}
}

int enqueue(fila *f, int x) {
    if (f->u == f->N) { // when the list if full call the function resize, to duplicate the size of list original
        if (!resize(f)) {
            return 0; // Resize failed
        }
    }

    f->dados[f->u] = x; //add the value to last position 
    f->u++;
    return 1; // Enqueue successful
}
