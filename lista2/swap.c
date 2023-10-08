#include<stdio.h>

void swap(int *a, int *b) { // Function definition
    int temp = *a; // Store the value of a in temp
    *a = *b;       // Assign the value of b to a
    *b = temp;     // Assign the value of temp to b
}