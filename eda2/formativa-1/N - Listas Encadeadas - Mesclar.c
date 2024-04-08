#include<stdio.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *temp1 = l1->prox; // Skip the head node
    celula *temp2 = l2->prox; // Skip the head node
    celula *temp3 = l3;       // Start at the head node

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->dado < temp2->dado) { // if the element of l1 is smaller than l2 
            temp3->prox = temp1; // update the next of l3 list to point to the current node of l1 list
            temp1 = temp1->prox; // move to the next node of l1 list
        } else { // if the element of l2 is smaller or equal
            temp3->prox = temp2; // update the next of l3 list to point to the current node of l2 list
            temp2 = temp2->prox; // move to the next node of l2 list
        } 
        temp3 = temp3->prox; // move to the next node of l3
    }

    // If there are remaining nodes in either list, append them to l3
    if (temp1 != NULL) {
        temp3->prox = temp1; // append remaining nodes of l1 to l3
    } else {
        temp3->prox = temp2; // append remaining nodes of l2 to l3
    }
}