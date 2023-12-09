#include<stdio.h>

#define Item int  // Define a macro for the item type

// Define a macro for swapping two items
#define exch(a, b) { Item t = a; a = b; b = t; }

// Function to shift an element to its correct position in a sorted part of the array
void shift_element(Item *v, int i) {
    // If the index is not valid (less than or equal to 0), return
    if (i <= 0)
        return;

    // If the current element is less than the previous one
    if (v[i] < v[i - 1]) {
        // Swap the current element with the previous one
        exch(v[i], v[i - 1]);

        // Recursively call the function for the previous index
        shift_element(v, i - 1);    
    }
}