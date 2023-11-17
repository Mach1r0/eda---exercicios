#include<stdio.h>

void bubblesort(int array[], int n){ // declarate the array and size of the array
    for (int i = 0; i < n-1; i++){  // loop for reach all the elements of the array
        for (int j = 0; j < n - i - 1; j++){ // loop for compare the elements of the array
            if (array[j] > array[j+1]){ // if the element is bigger than the next element, swap them
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }    
}

int main() {
    int array[1000]; 
    int n = 0;
    while(scanf("%d", &array[n]) != EOF) { //read the input until the end of the file
        n++; // count the number of elements
    }
    bubblesort(array, n); // call the function  
    for(int i=0; i < n; i++) { // print the array sorted
        printf("%d ", array[i]); // print the element
    }
    printf("\n");
    return 0;
}