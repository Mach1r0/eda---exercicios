#include<stdio.h>

#define Item int
#define exch(a, b) { Item t = a; a = b; b = t; }

int ordena(Item *v, int n) {
      for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1]) {
            swap(arr, i, i + 1);
        }
    }
 
    if (n - 1 > 1) {
        bubbleSort(arr, n - 1);
    }

}