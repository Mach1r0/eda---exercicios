#include <stdio.h>
#include <stdlib.h>

#define less(A,B) (A.num < B.num)

typedef struct {
    int num;
    char instruct[15];
} Item;

void merge(Item *v, int l, int meio, int r) {
    Item *v2 = malloc(sizeof(Item) * (r - l + 1));
    int i = l, j = meio + 1, k = 0;

    while (i <= meio && j <= r) {
        if (less(v[i], v[j])) {
            v2[k++] = v[i++];
        } else {
            v2[k++] = v[j++];
        }
    }

    while (i <= meio) {
        v2[k++] = v[i++];
    }

    while (j <= r) {
        v2[k++] = v[j++];
    }

    k = 0;
    for (i = l; i <= r; i++) {
        v[i] = v2[k++];
    }

    free(v2);
}

void mergesort(Item *v, int l, int r) {
    if (l < r) {
        int meio = (l + r) / 2;
        mergesort(v, l, meio);
        mergesort(v, meio + 1, r);
        merge(v, l, meio, r);
    }
}

int bb(Item *vetor, int l, int r, int b) {
    while (l <= r) {
        int meio = (l + r) / 2;
        if (vetor[meio].num == b) {
            printf("%s\n", vetor[meio].instruct);
            return meio;
        } else if (vetor[meio].num < b) {
            l = meio + 1;
        } else {
            r = meio - 1;
        }
    }
    printf("undefined\n");
    return -1;
}

int main() {
    int n;
    int quant = 0;
    int cod_instruct[1000000];

    scanf("%d", &n);
    Item inst[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &inst[i].num, inst[i].instruct);
    }

    mergesort(inst, 0, n - 1);

    while (quant < 1000000 && scanf("%d", &cod_instruct[quant]) != EOF) {
        quant++;
    }

    for (int i = 0; i < quant; i++) {
        bb(inst, 0, n - 1, cod_instruct[i]);
    }

    return 0;
}