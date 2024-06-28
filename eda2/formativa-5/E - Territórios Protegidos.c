#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

typedef struct {
    int *items;
    int front;
    int rear;
    int capacity;
} Queue;

void initQueue(Queue *q, int n) {
    q->items = (int *)malloc(n * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->capacity = n;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    return q->items[q->front++];
}

void freeQueue(Queue *q) {
    free(q->items);
}

void bfs(int start, int **adjList, int *adjSize, int *visited, int *or_result) {
    Queue q;
    initQueue(&q, MAX_N);
    enqueue(&q, start);
    visited[start] = 1;
    *or_result = start;

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adjList[node][i];
            if (!visited[neighbor]) {
                enqueue(&q, neighbor);
                visited[neighbor] = 1;
                *or_result |= neighbor;
            }
        }
    }

    freeQueue(&q);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **adjList = (int **)malloc((n + 1) * sizeof(int *));
    int *adjSize = (int *)calloc(n + 1, sizeof(int));
    int *adjCapacity = (int *)malloc((n + 1) * sizeof(int));
    int visited[MAX_N] = {0};

    for (int i = 0; i <= n; i++) {
        adjCapacity[i] = 2; // Inicializar a capacidade com um valor pequeno
        adjList[i] = (int *)malloc(adjCapacity[i] * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (adjSize[u] == adjCapacity[u]) {
            adjCapacity[u] *= 2;
            adjList[u] = (int *)realloc(adjList[u], adjCapacity[u] * sizeof(int));
        }
        adjList[u][adjSize[u]++] = v;

        if (adjSize[v] == adjCapacity[v]) {
            adjCapacity[v] *= 2;
            adjList[v] = (int *)realloc(adjList[v], adjCapacity[v] * sizeof(int));
        }
        adjList[v][adjSize[v]++] = u;
    }

    int total_xor = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int or_result = 0;
            bfs(i, adjList, adjSize, visited, &or_result);
            total_xor ^= or_result;
        }
    }

    printf("%d\n", total_xor);

    for (int i = 0; i <= n; i++) {
        free(adjList[i]);
    }
    free(adjList);
    free(adjSize);
    free(adjCapacity);

    return 0;
}
