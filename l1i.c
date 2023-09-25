#include <stdio.h>

int main() {
    int N, C;
    scanf("%d %d", &N, &C);

    int ocupacao = 0;
    int excedeu = 0; 

    for (int i = 0; i < N; i++) {
        int S, E;
        scanf("%d %d", &S, &E);

        ocupacao = ocupacao - S + E;

        if (ocupacao > C) {
            excedeu = 1;
        }
    }

    if (excedeu) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}
