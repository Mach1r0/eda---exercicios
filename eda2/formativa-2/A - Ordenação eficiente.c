#include<stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int medianOfThree(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] < arr[left]) {
        swap(&arr[mid], &arr[left]);
    }
    if (arr[right] < arr[left]) {
        swap(&arr[right], &arr[left]);
    }
    if (arr[mid] < arr[right]) {
        swap(&arr[mid], &arr[right]);
    }
    return arr[right];
}

int partition (int arr[], int left, int right) {
    int pivot = medianOfThree(arr, left, right); 
    int i = (left - 1); 

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}