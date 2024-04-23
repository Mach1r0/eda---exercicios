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

item quickselect(item *v, int left, int right, int k){
    if (left == right) return v[left];
    int pivot = partition(v, left, right);
    if (k == pivot) return v[pivot];
    else if (k < pivot)
        return quickselect(v, left, pivot - 1, k);
    else
        return quickselect(v, pivot + 1, right, k);
}

void quicksortM3(item *v, int left, int right){
    int meio = (left + right) / 2; 
    cmpexch(v[left], v[right]);
    cmpexch(v[[left], v[meio]]);
    cmpexch(v[right], v[meio]);
    int pivo = partition(v, left, right); 
    quicksortM3(v, left, pivo -1);    
    quicksortM3(v, pivo + 1, right);    
}