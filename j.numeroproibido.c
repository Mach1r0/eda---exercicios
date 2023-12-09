#include <stdio.h>
#include <stdlib.h>

int busca(int vet[], int tam, int n) {
    int init = 0, fim = tam - 1, meio;
    while (init <= fim) {  // Binary search
        meio = (init + fim) / 2;
        if (n == vet[meio]) return 1;
        else if (n < vet[meio]) fim = meio - 1;
        else init = meio + 1;
    }
    return 0;
}

void ord(int *vet, int tam) {
    int aux;
    for (int i = tam - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

int main() {
    long long p;
    int n, vet[140000], res;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    qsort(vet, n, sizeof(int), compare);  // You need to define a compare function for qsort

    while (scanf("%lld", &p) != EOF) {
        res = busca(vet, n, p);

        if (res == 1) printf("sim\n");
        else printf("nao\n");
    }

    return 0;
}