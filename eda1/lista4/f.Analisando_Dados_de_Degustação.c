#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a struct to hold the output data
typedef struct Output{
    int count;
    int position;
    char character;
} Output;

// Merge function for merge sort
void merge(Output *array, int left, int mid, int right){
    Output *tempArray = malloc(sizeof(Output)*(right - left + 1));
    int tempIndex = 0;
    int i = left;
    int j = mid + 1;

    // Merge two sorted subarrays in array into tempArray
    while(i <= mid && j <= right){
        if(array[i].count < array[j].count){
            tempArray[tempIndex++] = array[i++];
        } else {
            tempArray[tempIndex++] = array[j++];
        }
    }

    // Copy any remaining elements on the left side
    while(i <= mid) tempArray[tempIndex++] = array[i++];

    // Copy any remaining elements on the right side
    while(j <= right) tempArray[tempIndex++] = array[j++];

    // Copy sorted tempArray back into the main array
    tempIndex = 0;
    for(i = left; i <= right; i++){
        array[i] = tempArray[tempIndex++];
    }

    free(tempArray);
}

// Merge sort function
void mergeSort(Output *array, int left, int right){
    if(left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

int main(){
    char phrase[100001];
    scanf("%s", phrase);
    int currentIndex = 0;
    int outputIndex = 0;
    Output outputArray[strlen(phrase)];
    outputArray[outputIndex].count = 0;

    for(int i = 0; i < strlen(phrase); i++){
        if(phrase[currentIndex] != phrase[i]){
            currentIndex = i;
            outputIndex++;
            outputArray[outputIndex].count = 0;
        }
        outputArray[outputIndex].count++;
        outputArray[outputIndex].position = currentIndex;
        outputArray[outputIndex].character = phrase[currentIndex];
    }

    mergeSort(outputArray, 0, outputIndex);

    for(int i = outputIndex; i >= 0; i--){
        printf(" %d %c %d\n", outputArray[i].count, outputArray[i].character, outputArray[i].position);
    }

    return 0;
}