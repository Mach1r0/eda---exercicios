#include<stdio.h>
#include<stdlib.h>
#define item int
#define less(a,b) (a < b) 
#define swap(a, b) (item temp = a; a = b; b = temp)
#define cmpexch(if less(a, b){swap(a , b)})

int partition(item *v, int left, int right){
    int pivo = v[right];
    int k = left - 1;
    for (int j = left; j < right; j++){
        if (v[j] < pivo){
            k++; 
            swap(v[j], v[k]);
        }
    }
    swap(&v[k + 1], &v[right]);
    return v[k + 1];
}