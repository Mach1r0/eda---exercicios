#include <stdio.h>
#include <stdlib.h>

#define Item int  // Define a macro for the item type
#define less(a, b) (a < b)  // Define a macro for comparing two items

// Define a macro for swapping two items
#define exch(a, b) { Item t = a; a = b; b = t; }

// Function to perform insertion sort on an array
void insertionsort(int v[], int l, int r) {
    // For each element in the array, starting from the second one
    for (int i = l + 1; i <= r; i++) {
        // Store the current element
        Item current = v[i];
        // Initialize a pointer to the previous element
        int j = i - 1;
        // While the pointer is not out of bounds and the current element is less than the element at the pointer
        while (j >= l && less(current, v[j])) {
            // Shift the element at the pointer to the right
            v[j + 1] = v[j];
            // Move the pointer to the left
            j--;
        }
        // Insert the current element at the correct position
        v[j + 1] = current;
    }
}

// Main function
int main(void) {
    int n = 0;  // Initialize a counter for the number of elements
    Item array[100000];  // Declare an array of items

    // While the end of file (EOF) is not reached
    while (scanf("%d", &array[n]) != EOF) {
        // Read an integer from the input and store it in the array at index n
        // Then increment the counter
        n++;
    }

    // Sort the array using insertion sort
    insertionsort(array, 0, n-1); 

    // Print the sorted array
    for (int i = 0; i < n; i++) { 
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;  // End of the program
}