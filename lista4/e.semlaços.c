#include<stdio.h>

#define Item int
#define exch(a, b) { Item t = a; a = b; b = t; }

void shift_element(Item *v, int i) {
    if (i <= 0)
        return;

    if (v[i] < v[i - 1]) {
        exch(v[i], v[i - 1]);
        shift_element(v, i - 1);    
    }
}

void ordena(Item *v, int n) {
    if (n <= 1)
        return;

    ordena(v, n - 1);

    shift_element(v, n - 1);
}