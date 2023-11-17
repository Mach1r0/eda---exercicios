#include<stdio.h>

void bubblesort(int array[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (array[j] > array[j+1]){
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
    while(scanf("%d", &array[n]) != EOF) {
        n++;
    }
    bubblesort(array, n);
    for(int i=0; i < n; i++) {
        printf("%d", array[i]);
        if(i < n-1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}