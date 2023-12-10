#include <stdio.h>
#include <stdlib.h>

// Define a pair to hold an element and its position
typedef struct {
    int element;
    int pos;
} Pair;

// Compare function for qsort
int compare(const void *a, const void *b) {
    return ((Pair *)a)->element - ((Pair *)b)->element;
}

// Binary search function
int binary_search(Pair *array, int left, int right, int query) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid].element == query)
            return array[mid].pos;
        if (array[mid].element < query)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n, q, i;
    scanf("%d %d", &n, &q);  // Read the size of the array and the number of queries

    Pair array[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &array[i].element);  // Read the elements of the array
        array[i].pos = i;  // Store the original positions of the elements
    }

    // Sort the array of pairs by element
    qsort(array, n, sizeof(Pair), compare);

    for(i = 0; i < q; i++) {
        int query;
        scanf("%d", &query);  // Read the query

        // Print the original position of the query in the array, or -1 if it is not found
        printf("%d\n", binary_search(array, 0, n - 1, query));
    }

    return 0;
}