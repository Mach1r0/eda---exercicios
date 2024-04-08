#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    double soma = 0;
    scanf("%d", &N);
    int v[N];
    for (int i = 0; i < N; i++){
        scanf("%d", &v[i]);
        soma += v[i];
    }
    double media = soma/N;
    
    int printed = 0;
    for (int i = 0; i < N; i++){
        if (v[i] > media){
            printf("%d ", v[i]);
            printed = 1;
        }       
    }
    if (!printed) printf("0");
    printf("\n");
    return 0;
}