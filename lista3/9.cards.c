#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v; // Vetor que representa a pilha
    int topo; // Índice do topo da pilha
    int N; // Tamanho da pilha
} pilha;

void inicializa_pilha(pilha *p, int N) {
    p->v = (int *) malloc(N * sizeof(int));
    p->topo = -1;
    p->N = N;
}

void empilha(pilha *p, int x) {
    p->topo++;
    p->v[p->topo] = x;
}

int desempilha(pilha *p) {
    int x = p->v[p->topo];
    p->topo--;
    return x;
}

int main() {
    int N;
    scanf("%d", &N);

    pilha p;
    inicializa_pilha(&p, N);

    // Empilha as cartas na ordem inversa
    for (int i = N; i >= 1; i--) {
        empilha(&p, i);
    }

    int descartadas[100]; // Array para armazenar as cartas descartadas
    int descartadas_count = 0; // Contador de cartas descartadas

    printf("Cartas descartadas: ");
    while (p.topo > 0) {
        // Descarta a carta do topo
        descartadas[descartadas_count] = desempilha(&p);
        descartadas_count++;

        // Move a próxima carta para a base da pilha
        empilha(&p, desempilha(&p));
    }

    // Imprime a sequência de cartas descartadas
    for (int i = 0; i < descartadas_count - 1; i++) {
        printf("%d, ", descartadas[i]);
    }
    printf("%d\n", descartadas[descartadas_count - 1]);

    // A última carta é a única que sobrou na pilha
    printf("Carta restante: %d\n", p.v[0]);

    free(p.v);

    return 0;
}
