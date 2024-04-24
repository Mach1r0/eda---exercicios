#include <stdio.h>
#include <stdlib.h>

typedef struct {
  long long key;
  int value;
} Item;

#define less(a, b) (a.value == b.value ? a.key < b.key : a.value < b.value)
#define swap(a, b) { Item temp = *a; *a = *b; *b = temp; }
#define cpmexch(a, b) { if (less(a, b)) swap(a,b); }

int medianOfThree(Item *v, int left, int right) {
  int mid = (left + right) / 2;
  cpmexch(&v[left], &v[mid]);
  cpmexch(&v[left], &v[right]);
  cpmexch(&v[mid], &v[right]);
  return mid;
}

int partition(Item *v, int left, int right) {
  int pivotIndex = medianOfThree(v, left, right);
  Item pivot = v[pivotIndex];
  swap(&v[pivotIndex], &v[right]);
  int j = left - 1;
  for (int k = left; k < right; k++) {
    if (less(v[k], pivot)) {
      j++;
      swap(&v[j], &v[k]);
    }
  }
  swap(&v[j + 1], &v[right]);
  return j + 1;
}

void insertionsort(Item *v, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        Item key = v[i];
        int j = i - 1;
        while (j >= left && less(key, v[j])) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}
void quicksort(Item *v, int left, int right) {
  if (right - left <= 32) {
    insertionsort(v, left, right);
    return;
  }
  if (left >= right) return;
  int pivo = partition(v, left, right);
  quicksort(v, left, pivo - 1);
  quicksort(v, pivo + 1, right);
}

void quickselect(Item *v, int left, int right, int k) {
  int pivo = partition(v, left, right);
  if (pivo == k) return;
  if (pivo > k) {
    quickselect(v, left, pivo - 1, k);
  } else {
    quickselect(v, pivo + 1, right, k);
  }
}

int main() {
    int k;
    scanf("%d", &k);

    Item *items = malloc(10000000 * sizeof(Item));

    if (items == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int n;
    for (n = 0; scanf("%d %d", &items[n].key, &items[n].value) == 2; n++);

    quickselect(items, 0, n - 1, k - 1);
    quicksort(items, 0, k - 1);

    for (int i = 0; i < k; i++)
        printf("%d %d\n", items[i].key, items[i].value);

    free(items);

    return 0;
}
