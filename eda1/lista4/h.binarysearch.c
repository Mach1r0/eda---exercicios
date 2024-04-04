#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search on an array
int binarysearch(int *v, int n, int x){
    int left = 0, right = n;  // Initialize left and right pointers

    // While the search space is not exhausted
    while (left < right) {
        int mid = left + (right - left) / 2;  // Calculate the mid index

        // If the element at mid index is less than the target, discard the left half
        if (v[mid] < x) {
            left = mid + 1;
        } 
        // Else, discard the right half
        else {
            right = mid;
        }
    }

    // Return the left pointer which points to the position where the target should be
    return left;
}

// Main function
int main(void)
{
    int N, Q, J;  // Declare variables for the number of elements (N), number of queries (Q), and the element to search for (J)
    scanf("%d %d", &N, &Q);  // Read N and Q from the input

    int v[N];  // Declare an array v of size N

    // Read the N elements of the array from the input
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    // For each query
    for (int i = 0; i < Q; i++) {
        scanf("%d", &J);  // Read the element to search for from the input

        // Perform a binary search for J in the array v
        int resultado = binarysearch(v, N, J);

        // Print the result of the binary search
        printf("%d\n", resultado);
    }

    return 0;  // End of the program
}