#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    if (p != NULL && p->prox != NULL) {
        celula *temp = p->prox;
        p->prox = temp->prox;
        free(temp);
        return 1;  // Indica que a remoção foi bem-sucedida.
    }
    return 0;  // Indica que a remoção não foi possível.
}

void remove_elemento(celula *le, int x) {
    celula *prev = le;
    celula *current = le->prox;

    if (current == NULL) {
        return;  
    }

    if (current->dado == x) {
        le->prox = current->prox;
        free(current);
        return;
    }

    while (current != NULL && current->dado != x) {
        prev = current;
        current = current->prox;
    }

    if (current != NULL) {
        prev->prox = current->prox;
        free(current);
    }
}


void remove_todos_elementos(celula *le, int x) {
    celula *prev = le;
    celula *current = le->prox;

    while (current != NULL) {
        if (current->dado == x) {
            prev->prox = current->prox;
            celula *temp = current;
            current = current->prox;
            free(temp);
        } else {
            prev = current;
            current = current->prox;
        }
    }
}
