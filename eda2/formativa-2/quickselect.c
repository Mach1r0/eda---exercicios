#include<stdio.h>
#define item int
#define less(a, b) (a < b)
#define swap(a, b) { item t = *a; *a = *b; *b = t; }
#define cmpexch(a, b) { if (less(b, a)) swap(a, b); }

int partition(item *v, int left, int right){
    item pivo = v[right]; 
    int k = left - 1; 
    for (int i = left; i < right; i++){
        if (less(v[i], pivo)){
            k++;
            swap(&v[i], &v[k]); 
        }
    }
    swap(&v[k+1], &v[right]);
    return k + 1;    
}

void quickselect(item *v, int left, int right, int k){
    if (left >= right) return;
    int pivot = partition(v, left, right);
    if(pivot > k){
        quickselect(v, left, pivot - 1, k);
    }
    else if(pivot < k){
        quickselect(v, pivot + 1, right, k);
    }
}

void quicksortM3(item *v, int left, int right){
    if (right <= left) return; 
    int meio = (left + right) / 2; 
    cmpexch(&v[left], &v[meio]); 
    cmpexch(&v[left], &v[right]);
    cmpexch(&v[meio], &v[right]);
    int pivo = partition(v, left, right);
    quicksortM3(v, left, pivo -1);
    quicksortM3(v, pivo + 1, right);
}   

int main(){
    int n, p, x;
    scanf(" %d %d %d", &n, &p, &x);
    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf(" %d", v + i);

    int startPage = min(n-1, p*x);
    int endPage = min(n-1, (p+1)*x-1);

    quickselect(v, 0, n-1, startPage);
    quickselect(v, 0, n-1, endPage);
    quicksortM3(v, startPage, endPage);

    for (int i = startPage; i < min(n, (p+1)*x); i++)
        printf("%d z\n", v[i]);

    free(v);
    return 0;
}