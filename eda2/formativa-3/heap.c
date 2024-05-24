#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertHeap(int data) {
    if (heapSize >= MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }

    heap[heapSize] = data;
    int currentIndex = heapSize;

    while (currentIndex != 0 && heap[currentIndex] > heap[(currentIndex - 1) / 2]) {
        swap(&heap[currentIndex], &heap[(currentIndex - 1) / 2]);
        currentIndex = (currentIndex - 1) / 2;
    }

    heapSize++;
}

void printHeap() {
    for (int i = 0; i < heapSize; i++) {
        printf("Index: %d, Value: %d\n", i, heap[i]);
    }
}

int main() {
    insertHeap(5);
    insertHeap(12);
    insertHeap(64);
    insertHeap(1);
    insertHeap(37);
    insertHeap(90);
    insertHeap(91);
    insertHeap(97);

    printHeap();

    return 0;
}