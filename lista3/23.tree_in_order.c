#include<stdio.h>
#include<stdlib.h>

typedef struct no {
int dado;
struct no *esq, *dir;
} no;

void em_ordem(no *raiz) {
    if (raiz == NULL) //empty list
        return;

    no *stack[500]; // declarate stack.
    int top = -1; // declarate top of stack, -1 mean empty stack
 
    no *current = raiz; //using temp variable to run the stack 

    while (current != NULL || top != -1) { // while the list not be empty or our current dont be null; 
        while (current != NULL) { // run all the list 
            stack[++top] = current; //add current at the top of stack 
            current = current->esq; // move the current to the left 
        }
        current = stack[top--]; // decrement of the top  if run all the left
        printf("%d ", current->dado); // print the value of current;
        current = current->dir;  //move the pointer to run the right side; 
    }
}
