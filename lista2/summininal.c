#include <stdio.h>

void print_last_values(int *vet, int index, int lim, int soma, int cont) {
    if (index == cont) return;
    soma += vet[index];
    if (soma > lim) {
        print_last_values(vet, index+1, lim, 0, cont);
        printf("%d\n", vet[index]);
    } else {
        print_last_values(vet, index+1, lim, soma, cont);
    }
}

int main() {
    int num, vet[150000], cont = 0;
    while (scanf("%d", &num) && num != 0) vet[cont++] = num;
    scanf("%d", &num);
    print_last_values(vet, 0, num, 0, cont);
    return 0;
}