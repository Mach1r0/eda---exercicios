#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Add this line

void merge(int* a, int* b, int n, int m) {
    int* temp = malloc((n + m) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = b[j++];
        }
    }

    while (i < n) {
        temp[k++] = a[i++];
    }

    while (j < m) {
        temp[k++] = b[j++];
    }

    for (i = 0; i < n + m; i++) {
        a[i] = temp[i];
    }

    free(temp);
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d%c", array[i], (i == size - 1 ? '\n' : ' '));
    }
}

int main() {
    int mergedSubmissions[800008], regionSubmissions[100001];
    int totalSubmissions = 0;

    for (int regionIndex = 0; regionIndex < 8; regionIndex++) {
        int regionSize = 0;
        scanf("%d", &regionSize);
        for (int submissionIndex = 0; submissionIndex < regionSize; submissionIndex++) {
            scanf("%d", &regionSubmissions[submissionIndex]);
        }
        merge(mergedSubmissions, regionSubmissions, totalSubmissions, regionSize);
        totalSubmissions += regionSize;
    }

    printArray(mergedSubmissions, totalSubmissions);

    return 0;
}