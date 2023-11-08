#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void empilha(celula *p, int x) {
    celula *new_node = malloc(sizeof(celula));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->dado = x;
    new_node->prox = p->prox;
    p->prox = new_node;
}

int desempilha(celula *p, int *y) {
    if (p->prox == NULL) {
        return 0;
    }
    celula *temp = p->prox;
    *y = temp->dado;
    p->prox = temp->prox;
    free(temp);
    return 1;
}