#include <stdio.h>

int main(void)
{
    float a, g, ra, rg; 
    
    scanf("%f %f %f %f", &a, &g, &ra, &rg); 

    float economicoalcol = a / ra; 
    float economicogasol = g / rg;
    
    if (economicoalcol < economicogasol)
        printf("A\n");
    else
        printf("G\n");
    
    return 0;
}
