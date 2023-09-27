#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
 
    scanf("%d", &N);

    int *v = (int *)malloc(N * sizeof(int));
    if (v == NULL) {
        fprintf(stderr, "Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
        if (v[i] % 2 == 0) {
            printf("%d ", v[i]);
        }
    }
    
    printf("\n");

    for (int j = 0; j < N; j++) {
        if (v[j] % 2 != 0) {
            printf("%d ", v[j]);
        }
    }

    printf("\n");
    free(v); 
    return 0;
}
