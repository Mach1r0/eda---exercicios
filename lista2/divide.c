#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2) {
    celula *current = l->prox;  // starting of the first, ignorat of head link
    celula *current_l1 = l1;   // stay on the last node in l1 
    celula *current_l2 = l2;   // stay on the last node in l2 

    // start both list 
    l1->prox = NULL;
    l2->prox = NULL;

    // while list does not be empty
    while (current != NULL) {
        celula *temp = current->prox;  // save the value before of modificate
        if (current->dado % 2 == 0) {  // if for the pair numbers 
            current_l2->prox = current; // modify the pointer to pointer to the new node
            current_l2 = current; // add node in list l1
            current->prox = NULL;  // the last node of l1 pointer to NULL
        } else {  // number odd 
            current_l1->prox = current; // modify the pointer to new node
            current_l1 = current; // add new node to list l1 
            current->prox = NULL;  // O último nó de l1 aponta para NULL
        }
        current = temp;  // advance to the next in
    }
}
