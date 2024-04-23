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
    int QTDPRODUTO, PAGINA, QTSPRDPAGINA; 
    scanf("%d %d %d", &QTDPRODUTO, &PAGINA, &QTSPRDPAGINA);
    int arr[QTDPRODUTO];
    for (int i = 0; i < QTDPRODUTO; i++){
        scanf("%d", &arr[i]);
    }
    int iniciopagina = PAGINA * QTSPRDPAGINA;
    int finalpagina = iniciopagina + QTSPRDPAGINA;

    if (finalpagina > QTDPRODUTO) {
        finalpagina = QTDPRODUTO;
    }

    quickselect(arr, 0, QTDPRODUTO - 1, iniciopagina);
    quickselect(arr, iniciopagina + 1, QTDPRODUTO - 1, finalpagina - 1);
    quicksortM3(arr, iniciopagina, finalpagina - 1);
    for (int i = iniciopagina; i < finalpagina && i < QTDPRODUTO; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}