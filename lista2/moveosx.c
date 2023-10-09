#include <stdio.h>

void move_xs(char *str, int i, int j) {
    // Caso base: se o caractere atual for nulo, terminamos a recursão
    if (str[i] == '\0') {
        // Adicione os caracteres 'x' no final
        for (int k = 0; k < j; k++) {
            putchar('x');
        }
        putchar('\n');
        return;
    }

    // Se o caractere atual não é 'x', imprima-o
    if (str[i] != 'x') {
        putchar(str[i]);
    } else {
        // Se o caractere atual é 'x', aumente o contador 'j'
        j++;
    }

    // Chame a função recursivamente para o próximo caractere
    move_xs(str, i + 1, j);
}

int main() {
    char string[1001]; // Suponhamos que a entrada terá no máximo 1000 caracteres

    // Receba a entrada do usuário
    scanf("%s", string);

    // Chame a função recursiva para mover os 'x'
    move_xs(string, 0, 0);

    return 0;
}
