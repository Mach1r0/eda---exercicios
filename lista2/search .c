#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula* prox;
} celula;

celula* busca(celula* le, int x) {
    while(le != NULL) {
        if (le->dado == x) {
            return le;
        }
        le = le->prox; 
    }
    return NULL;
}

celula* busca_rec(celula* le, int x) {
    while(le != NULL) {
        if (le->dado == x) {
            return le;
        }
        le = le->prox; 
    }
    return NULL;
}
int main() {
    celula *le, n1, n2, n3, n4;
    n1.dado = 0;
    n2.dado = 3;
    n3.dado = 4;
    n4.dado = 56;

    n1.prox = &n2;
    n2.prox = &n3;
    n3.prox = &n4;
    n4.prox = NULL;

    int x;
    scanf("%d", &x);
    celula* resultado = busca(&n1, x);
    if (resultado != NULL) {
        printf("Valor encontrado: %d\n", resultado->dado);
    } else {
        printf("Valor não encontrado\n");
    }
    return 0;
}
