#include <stdio.h>

int main(void)
{
    int n1, n2, n3, n4, n5; 
    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);

    if (n2 >= n1 && n3 >= n2 && n4 >= n3 && n5 >= n4 )
        printf("C\n");
    else if(n1  < n2 && n2 < n3 && n3 < n4 && n4 < n5)
        printf("D\n");
    else
        printf("N\n");    
    return 0;
    
}