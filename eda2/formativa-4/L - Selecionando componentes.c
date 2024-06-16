#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->data = (int*) malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapifyUp(MinHeap *heap, int index) {
    int parent = (index - 1) / 2;
    if (index && heap->data[parent] > heap->data[index]) {
        swap(&heap->data[parent], &heap->data[index]);
        heapifyUp(heap, parent);
    }
}

void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;

    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->data[smallest], &heap->data[index]);
        heapifyDown(heap, smallest);
    }
}

void insertHeap(MinHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int*) realloc(heap->data, sizeof(int) * heap->capacity);
    }
    heap->data[heap->size++] = value;
    heapifyUp(heap, heap->size - 1);
}

int extractMin(MinHeap *heap) {
    int root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    MinHeap *Ta = createHeap(N);
    MinHeap *Tb = createHeap(N);

    for (int i = 0; i < N; i++) {
        int Ai;
        scanf("%d", &Ai);
        insertHeap(Ta, Ai);
    }

    int combinedCount = 0;
    int *combinedResults = (int*) malloc(sizeof(int) * N);

    while (Ta->size > 0) {
        int minA = extractMin(Ta);

        if (Tb->size > 0) {
            int maxB = -extractMin(Tb);
            if (minA - maxB > 0 && minA - maxB <= X) {
                int combinedValue = minA + maxB;
                combinedResults[combinedCount++] = combinedValue;
            } else {
                insertHeap(Tb, -maxB);
                insertHeap(Tb, -minA);
            }
        } else {
            insertHeap(Tb, -minA);
        }
    }

    printf("%d\n", combinedCount);
    for (int i = 0; i < combinedCount; i++) {
        printf("%d ", combinedResults[i]);
    }
    printf("\n");

    free(Ta->data);
    free(Ta);
    free(Tb->data);
    free(Tb);
    free(combinedResults);

    return 0;
}
