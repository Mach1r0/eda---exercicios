#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *v; // Vetor que contem os elementos da pilha
    int N; // Tamanho de v
    int topo; // Indicador do topo
} pilha;

int resize(pilha *p) {
    int new_size = p->N * 2;  // Double the current size
    int *new_data = (int *) realloc(p->v, new_size * sizeof(int)); // Allocate new space for new list
    if (new_data == NULL) {
        return 0; // Allocation failed
    }
    p->v = new_data;
    p->N = new_size;
    return 1; // Successfully resized the stack
}

int empilha(pilha *p, int x) {
    if (p->topo == p->N) {
        if (!resize(p)) {
            return 0; // Resize failed
        }
    }
    p->v[p->topo] = x;
    p->topo++;
    return 1; // Successfully pushed an item onto the stack
}

int desempilha(pilha *p, int *y) {
    if (p->topo == 0 || p->v == NULL) {
        return 0; // Stack is empty or invalid
    }
    p->topo--;
    *y = p->v[p->topo];
    return 1; // Successfully popped an item from the stack
}