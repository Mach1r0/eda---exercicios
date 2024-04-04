#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int mapa1[N][N];
    int mapa2[N][N];
    int resultado[N][N];

    // Ler o primeiro mapa de chuva
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mapa1[i][j]);
        }
    }

    // Ler o segundo mapa de chuva
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mapa2[i][j]);
        }
    }

    // Calcular o resultado somando os mapas
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = mapa1[i][j] + mapa2[i][j];
        }
    }

    // Imprimir o resultado
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", resultado[i][j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
