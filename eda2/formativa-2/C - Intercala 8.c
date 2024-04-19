#include<stdio.h>
#include<stdlib.h>

#define item int
#define less(a, b) (a < b)
#define swap(a, b) { item t = *a; *a = *b; *b = t; }
#define cmpexch(a, b) if (less(b, a)) swap(a, b)

int partition(item *v, int left, int right){
    item pivot = v[right];
    int i = left - 1;
    for (int j = left; j < right; j++){
        if (v[j] <= pivot){
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[right]);
    return (i + 1);
}

void quicksortM3(item v[], int left, int right){
    if (left >= right) return;

    int mid = (left + right) / 2;
    swap(&v[mid], &v[right - 1]);
    cmpexch(&v[left], &v[right - 1]);
    cmpexch(&v[left], &v[right]);
    cmpexch(&v[right - 1], &v[right]);
    
    int pivot = partition(v, left, right);
    quicksortM3(v, left, pivot - 1);
    quicksortM3(v, pivot + 1, right);
}

int quickselect(item *v, int left, int right, int k){
    if (left > right){
        return -1; 
    }
    int pivo = partition(v, left, right);
    if (k < pivo){
        return quickselect(v, left, pivo - 1, k);
    } else if (k > pivo){
        return quickselect(v, pivo + 1, right, k);
    } else {
        return v[pivo];
    }
}

int main(void){
    int N, P, X; 
    scanf("%d %d %d", &N, &P, &X);
    int v[10000];
    for (int i = 0; i < N; i++){
        scanf("%d", &v[i]);
    }
    int inicioP = X*P; 
    int fimp = inicioP + X; 
    quickselect(v, 0, N-1, inicioP);
    quicksortM3(v, inicioP + 1, fimp);
    quicksortM3(v, inicioP, fimp);
    for (int i = 0; i < N; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}