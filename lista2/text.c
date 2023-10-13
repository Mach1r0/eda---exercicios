#include <stdio.h>

int somaDosDigitos(int num) {
    if (num == 0) {
        return 0;  // Caso base: nenhum dígito, retorno 0.
    } else {
        return num % 10 + somaDosDigitos(num / 10);  // Soma o último dígito com a soma dos restantes.
    }
}

int main() {
    int numero;
    scanf("%d", &numero);

    int resultado = somaDosDigitos(numero);
    printf("%d\n", resultado);

    return 0;
}
