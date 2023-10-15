#include <stdio.h>
#include <stdlib.h>

// declarate the function
typedef struct celula {
    int dado;
    // call the function again, to pointer to prox 
    struct celula* prox;
} celula;

// call the function and pass the arguments, the first argument is the linked list
// and the second is the number to be searched
celula* busca(celula* le, int x) {
    // runing the list until the empyt
    while(le != NULL) {
        // when we find the number, we return to list
        if (le->dado == x) {
            return le;
        }// if the number of the list don't for the 'x' we passe to next value of the list
        le = le->prox; 
    }
    //if the number don't wa be on the list, return null
    return NULL;
}
// call the function
celula* busca_rec(celula* le, int x) {
    // Base case: End of the list reached (le is NULL)
    if (le == NULL) {
        return NULL;
    }
    // if the data of list for the 'x', we return to the list;
    if (le->dado == x) {
        return le; 
    }// else the call function again to the next value, until list to be empty 
    else {
        return busca_rec(le->prox, x);
    }
}
