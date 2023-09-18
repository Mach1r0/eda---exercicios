#include <stdio.h>
#include <string.h>

int main() {
    int teste = 1;
    int resultados[100];
    char vencedores[100][10]; 

    while (1) {
        int R;
        scanf("%d", &R);

        if (R == 0) {
            break;
        }

        int figaldo = 0;
        int figbeto = 0;

         for (int i = 0; i < R; i++) {
            scanf("%d %d", &figaldo, &figbeto);

            if (figaldo > figbeto) 
                figaldo += 1;
             else if (figbeto > figaldo) 
                figbeto += 1;
            
        }

        if (figaldo > figbeto) {
            strcpy(vencedores[teste - 1], "Aldo");
        } else {
            strcpy(vencedores[teste - 1], "Beto");
        }

        resultados[teste - 1] = R;
        teste++;
    }

    for (int i = 0; i < teste - 1; i++) {
        printf("Teste %d\n", i + 1);
        printf("%s\n\n",vencedores[i]);
    }

    return 0;
}