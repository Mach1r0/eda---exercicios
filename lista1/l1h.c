#include <stdio.h>

int main() {
    int R; 
    int caso = 1; 

    while (1) {
        scanf("%d", &R);

        if (R == 0) {
            break; 
        }

        int Aldo = 0;
        int Beto = 0;

        for (int i = 0; i < R; i++) {
            int A, B;
            scanf("%d %d", &A, &B);

            Aldo += A;
            Beto += B;
        }

        printf("Teste %d\n", caso);
        if (Aldo > Beto) {
            printf("Aldo\n");
        } else {
            printf("Beto\n");
        }
        printf("\n");

        caso++;
    }

    return 0;
}