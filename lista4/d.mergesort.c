#include<stdio.h>
#include<stdlib.h>

//function to merge two subarrays
void merge(int array[], int l, int m, int r){ 
    int left_length = m - l + 1; // this is the length of the left subarray
    int right_length = r - m; // this is the length of the right subarray

    int left[left_length];  // create a temporary array for the left subarray
    int right[right_length];// create a temporary array for the rightsubarray
    
    for (int i = 0; i < left_length; i++){ // copy the left subarray to the temporary array
        left[i] = array[l + i];
    }
    for (int i = 0; i < right_length; i++){ //copy the right subarray to the temporary array    
        right[i] = array[m + 1 + i];
    }
    int i = 0, j = 0, k = l; // definition variables to iterate over the temporary arrays
    while (i < left_length && j < right_length) { // merge the temporary arrays back into the original array
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    // copy the remaining elements of left[], if there are any
    while (i < left_length) {
        array[k] = left[i];
        i++;
        k++;
    }
    // copy the remaining elements of right[], if there are any
    while (j < right_length) {
        array[k] = right[j];
        j++;
        k++;
    }
    free(leaf);
    free(right);
}

void mergesort(int array[], int l, int r ){// l is for left index and r is right index of the sub-array of array to be sorted
    if (l < r) { // base case: if l >= r, the sub-array is considered already sorted
        int mid = l + (r - l) / 2; // find the middle point
        mergesort(array, l, mid); // sort the first and second halves
        mergesort(array, mid + 1, r); // sort the first and second halves
        merge(array, l, mid, r); // merge the sorted halves
    }
} 

int main(void){
    int n; 
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    mergesort(array, 0, n-1);
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
} 