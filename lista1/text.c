#include <stdio.h>

int main() {
    int teste = 1;
    int resultado[100];
    int numero;
    char operando;

    while (1) {
        int M;
        scanf("%d", &M);

        if (M == 0) {
            break;
        }

        scanf("%d", &numero);
        resultado[teste - 1] = numero; 

        for (int i = 1; i < M; i++) {
            scanf(" %c %d", &operando, &numero);

            if (operando == '+') {
                resultado[teste - 1] += numero; 
            } else {
                resultado[teste - 1] -= numero; 
            }
        }

        teste++;
    }

    for (int i = 0; i < teste - 1; i++) {
        printf("Teste %d\n", i + 1);
        printf("%d\n\n", resultado[i]);
    }
    return 0;
}
