#include<stdio.h>

int main(){
    int execedeu, n, c, s, e, pesototal = 0;

    scanf("%d %d", &n, &c);

    for (int i = 0; i < n; i++)
    {
    scanf("%d %d", &s, &e);
    pesototal += e - s;

    if (pesototal > c){
     execedeu = 1;
    }}

    if (execedeu == 1)
        printf("S\n");

    else
        printf("N\n");

    return 0;
}