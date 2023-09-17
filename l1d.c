#include<stdio.h>
#include<math.h>

int main(void)
{
    int a, b, c; 
    int x, y, z;

    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &x, &y, &z);
    
    int calcontainerlar = floor(x / a);
    int calcontainercom = floor(y / b);
    int calcontaineralt = floor(z / c);
    int conta = calcontainerlar * calcontainercom * calcontaineralt;

    printf("%d\n", conta);
    return 0;
}