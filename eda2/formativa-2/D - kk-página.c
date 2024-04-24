#define item int
#define less(a, b) (a < b)
#define swap(a, b) { item t = *a; *a = *b; *b = t; }
#define cmpexch(a, b) { if (less(b, a)) swap(a, b); }
#define min(a, b) ((a) < (b) ? (a) : (b))

int medianOfThree(item *v, int left, int right) {
    int mid = left + (right - left) / 2;
    cmpexch(&v[left], &v[mid]);
    cmpexch(&v[mid], &v[right]);
    cmpexch(&v[left], &v[mid]);
    return mid;
}

int partition(item *v, int left, int right){
    int pivotIndex = medianOfThree(v, left, right);
    item pivot = v[pivotIndex];
    swap(&v[pivotIndex], &v[right]);
    int i = left;
    for (int j = left; j < right; j++){
        if (less(v[j], pivot)){
            swap(&v[i], &v[j]);
            i++;
        }
    }
    swap(&v[i], &v[right]);
    return i;    
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

void insertionsort(item *v, int left, int right){
    for (int i = left + 1; i <= right; i++){
        int j = i;
        item tmp = v[j];
        while (j > left && less(tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}

void quicksortM3(item *v, int left, int right){
    if (right - left <= 32){
        insertionsort(v, left, right);
        return;
    }
    int pivot = partition(v, left, right);
    quicksortM3(v, left, pivot -1);
    quicksortM3(v, pivot + 1, right);
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
        printf("%d \n", v[i]);

    free(v);
    return 0;
}