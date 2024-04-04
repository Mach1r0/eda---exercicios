#include <stdio.h>

int main(void)
{
    int l, d, k, p;
    int custototal;

    scanf("%d %d", &l, &d);  
    scanf("%d %d", &k, &p);
    
    custototal = (l * k) + (l / d * p);
    printf("%d\n", custototal);
}
