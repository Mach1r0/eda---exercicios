#include <stdio.h>
#include <stdlib.h>

#define Item int
#define less(a, b) (a < b)
#define exch(a, b) { Item t = a; a = b; b = t; }

void insertionsort(int v[], int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        Item current = v[i];
        int j = i - 1;
        while (j >= l && less(current, v[j])) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = current;
    }
}

int main(void) {
    int n = 0;
    Item array[100000];
    while (scanf("%d", &array[n]) != EOF) {
        n++;
    }
    insertionsort(array, 0, n-1); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}