#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int xm, ym, xr, yr;
    scanf("%d %d %d %d", &xm, &ym, &xr, &yr);
    int conta = abs(xm - xr) + abs(ym - yr); 
    printf("%d\n", conta);
    return 0;
}
