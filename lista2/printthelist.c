#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    while (le != NULL) {
        printf("%d ", le->dado); // Print the data in the current node
        le = le->prox; // Move to the next node
    }
}

void imprime_rec(celula *le) {
    if (le == NULL) {
        return;
    }

    printf("%d ", le->dado);
    imprime_rec(le->prox);
}


