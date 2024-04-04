#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desempilha(celula *p, int *y) {
    if (p->prox == NULL) {
        return 0; // Stack is empty
    }
    celula *temp = p->prox;
    *y = temp->dado; 
    p->prox = temp->prox;
    free(temp);
    return 1; // Successfully popped an item from the stack
}