#include<stdio.h>
#include<stdlib.h>

typedef struct no {
int dado;
struct no *esq, *dir;
} no;

void pre_ordem (no *raiz) {
    if (raiz == NULL) return; // empty tree, do nothing

    no *stack[500]; // declare stack.
    int top = -1; // declare top of stack, -1 means empty stack
    
    stack[++top] = raiz; // push the root node onto the stack.

    while (top != -1) { // run all the tree 
        no *current = stack[top--]; // pop the top node from the stack.
        printf("%d ", current->dado); // process the current node.
        if (current->dir != NULL) { // push the right child onto the stack (if it exists).
            stack[++top] = current->dir;
        }
        if (current->esq != NULL) { // push the left child onto the stack (if it exists).
            stack[++top] = current->esq;
        }
    }
}
