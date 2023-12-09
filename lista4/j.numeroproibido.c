#include <stdio.h>
#include <stdlib.h>

#define Item int  // Define Item as an alias for int
#define key(x) (x)  // Define key as a function to get the key of an item

// Function to perform binary search on an array
int search(Item *array, int arraySize, int target)
{
    int left = 0, right = arraySize - 1;
    // While the search space is not empty
    while (left <= right)
    {
        // Calculate the middle index
        int middle = (left + right) / 2;
        // If the target is found
        if (key(array[middle]) == target)
            return 1;
        // If the target is greater than the middle element
        else if (key(array[middle]) < target)
            left = middle + 1;  // Narrow the search space to the right half
        // If the target is less than the middle element
        else
            right = middle - 1;  // Narrow the search space to the left half
    }
    // If the target is not found
    return 0;
}

// Function to merge two sorted arrays into one
void merge(Item *array1, int size1, Item *array2, int size2)
{
    // Allocate memory for the temporary array
    Item *tempArray = (Item *)malloc((size1 + size2) * sizeof(Item));
    int i = 0, j = 0, k = 0;
    // While there are elements in both arrays
    for (; i < size1 && j < size2; k++)
    {
        // If the current element in array1 is less than or equal to the current element in array2
        if (key(array1[i]) <= key(array2[j]))
            tempArray[k] = array1[i++];  // Copy the element from array1 to the temporary array
        else
            tempArray[k] = array2[j++];  // Copy the element from array2 to the temporary array
    }

    // Copy the remaining elements from array1, if any
    while (i < size1)
        tempArray[k++] = array1[i++];
    // Copy the remaining elements from array2, if any
    while (j < size2)
        tempArray[k++] = array2[j++];

    // Copy the sorted elements from the temporary array back to array1
    for (k = 0, i = 0; i < (size1 + size2); i++, k++)
        array1[i] = tempArray[k];

    // Free the memory allocated for the temporary array
    free(tempArray);
}

// Function to perform merge sort on an array
void mergesort(Item *array, int arraySize)
{
    // If the array has less than 2 elements, it is already sorted
    if (arraySize < 2) return;
    // Calculate the middle index
    int middle = arraySize / 2;
    // Recursively sort the left half of the array
    mergesort(array, middle);
    // Recursively sort the right half of the array
    mergesort(&array[middle], arraySize - middle);
    // Merge the two sorted halves
    merge(array, middle, array + middle, arraySize - middle);
}

int main()
{
    int arraySize;
    // Read the size of the array from the input
    scanf("%d", &arraySize);
    // Allocate memory for the array
    Item *array = (Item *)malloc(arraySize * sizeof(Item));
    // Read the elements of the array from the input
    for (int i = 0; i < arraySize; i++)
        scanf(" %d", &array[i]);

    // Sort the array
    mergesort(array, arraySize);

    // For each number in the input
    for (int number; scanf(" %d", &number) == 1;)
    {
        // Print "sim" if the number is in the array, "nao" otherwise
        printf("%s\n", search(array, arraySize, number) ? "sim" : "nao");
    }

    return 0;
}