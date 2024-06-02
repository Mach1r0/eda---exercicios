#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct no {
    int dado; 
    struct no *esq, *dir; 
} no; 

struct Stack {
    int size;
    int top;
    no** array;
};

no* newNode(int dado)
{
    no* node = (no*)malloc(sizeof(no));
    node->dado = dado;
    node->esq = node->dir = NULL;
    return node;
}

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (no**)malloc(stack->size * sizeof(no*));
    return stack;
}

int isFull(struct Stack* stack)
{
    return stack->top - 1 == stack->size;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, no* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

no* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

no* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

void pos_ordem(no *raiz) {
    if (raiz == NULL)
        return;

    struct Stack* stack = createStack(MAX_SIZE);
    do {
        while (raiz) {
            if (raiz->dir)
                push(stack, raiz->dir);
            push(stack, raiz);
            raiz = raiz->esq;
        }

        raiz = pop(stack);

        if (raiz->dir && peek(stack) == raiz->dir) {
            pop(stack);
            push(stack, raiz);
            raiz = raiz->dir;
        }
        else {
            printf("%d ", raiz->dado);
            raiz = NULL;
        }
    } while (!isEmpty(stack));
}