#include <stdio.h>

int main() {
    int N, C;
    scanf("%d %d", &N, &C);

    int capacidade_atual = 0;
    int excedeu = 0;

    for (int i = 0; i < N; i++) {
        int S, E;
        scanf("%d %d", &S, &E);
        capacidade_atual += E - S;

        if (capacidade_atual > C) {
            excedeu = 1;
            break;
        }
    }

    if (excedeu) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}
