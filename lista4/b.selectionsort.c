#include<stdio.h>
#include<stdlib.h>

void selectionsort(int array[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++)
            if (array[j] < array[min_index])
                min_index = j;

        int temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
}

int main(void){
    int n = 0;
    int array[1001];
    while (scanf("%d", &array[n]) != EOF){
        n++;
    }
    selectionsort(array, n);
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}