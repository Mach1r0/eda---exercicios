#include <stdio.h>

int main() {
    int N;
    int v[N]; 

    scanf("%d", &N); 


    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    int menorElemento = v[0];
    int indiceMenor = 0;

    for (int i = 1; i < N; i++) {
        if (v[i] < menorElemento) {
            menorElemento = v[i];
            indiceMenor = i;
        }
    }

    printf("%d\n", indiceMenor);

    return 0;
}
