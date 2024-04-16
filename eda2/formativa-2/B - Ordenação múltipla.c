#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double score;
    int member;
    int position;
} Problem;

void swap(Problem* a, Problem* b) {
    Problem t = *a;
    *a = *b;
    *b = t;
}

Problem medianOfThree(Problem arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid].score < arr[low].score) {
        swap(&arr[mid], &arr[low]);
    }
    if (arr[high].score < arr[low].score) {
        swap(&arr[high], &arr[low]);
    }
    if (arr[mid].score < arr[high].score) {
        swap(&arr[mid], &arr[high]);
    }
    return arr[high];
}

int partition(Problem arr[], int low, int high) {
    Problem pivot = medianOfThree(arr, low, high);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].score > pivot.score || (arr[j].score == pivot.score && arr[j].member < pivot.member) || (arr[j].score == pivot.score && arr[j].member == pivot.member && arr[j].position < pivot.position)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Problem arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        Problem* problems = (Problem*)malloc(n * m * sizeof(Problem));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%lf", &problems[i * m + j].score);
                problems[i * m + j].member = i + 1;
                problems[i * m + j].position = j + 1;
            }
        }

        quickSort(problems, 0, n * m - 1);

        for (int i = 0; i < n * m; i++) {
            printf("%d,%d ", problems[i].member, problems[i].position);
        }
        printf("\n");

        free(problems);
    }

    return 0;
}