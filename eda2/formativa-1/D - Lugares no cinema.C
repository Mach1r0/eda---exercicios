#include <stdio.h>
#include <stdlib.h>

int main(){
    int fila, lugar, numLugar; 
    char letra ; 

    scanf("%d %d", &fila, &lugar);

    char **salaCinema = (char **)malloc(fila * sizeof(char *));
    for(int i = 0; i < fila; i++){
        salaCinema[i] = (char *)malloc(lugar * sizeof(char));
    }

    for(int i = 0; i < fila; i ++){
        for(int j = 0; j < lugar ; j++){
            salaCinema[i][j] = '-';  
        }   
    }

    while(scanf(" %c%d", &letra, &numLugar) == 2){
        int f = letra - 'A';
        int l = numLugar - 1;
        if (f >= 0 && f < fila && l >= 0 && l < lugar) {
            salaCinema[f][l] = 'X';
        }
    }

    printf("   "); 
    for(int i = 0; i < lugar ; i++){
        printf("%02d ", i+1);
    }
    printf("\n");
    for(int i = fila -1; i >= 0; i--){
        printf("%c ", 'A' + i);
        for(int j = 0; j < lugar ; j++){
            printf(" %c%c",salaCinema[i][j],salaCinema[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < fila; i++){
        free(salaCinema[i]);
    }
    free(salaCinema);

    return 0 ; 
}