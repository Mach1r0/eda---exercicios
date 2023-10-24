#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void pos_ordem(no *raiz) {
    if (raiz == NULL) //empty tree
        return; 

    no *stack1[500]; // Stack 1 for post-order traversal
    no *stack2[500]; // Stack 2 to reverse the order

    int top1 = -1; // Top of stack 1
    int top2 = -1; // Top of stack 2

    stack1[++top1] = raiz; // Push the root onto stack 1

    while (top1 != -1) {
        no *current = stack1[top1--]; // Pop from stack 1
        stack2[++top2] = current;     // Push to stack 2
    // stack the values on the stack, then print them in reverse order 
        if (current->esq) // Push left child first
            stack1[++top1] = current->esq;
        if (current->dir) // Push right child
            stack1[++top1] = current->dir;
    }
    //unstack the values from stack 2 and print them
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->dado); // Pop and print from stack 2 (reversed order)
    }
}