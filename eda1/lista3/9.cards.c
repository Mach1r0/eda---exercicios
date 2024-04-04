#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

void dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return;

    struct Node* temp = queue->front;

    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
}

int front(struct Queue* queue) {
    if (queue->front == NULL)
        return -1;

    return queue->front->data;
}

int main() {
    int n;
    struct Queue* myqueue = createQueue();
    while (scanf("%d", &n) == 1) {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            enqueue(myqueue, i + 1);
        }
        int i = n;
        printf("Cartas descartadas: ");
        while (i != 1) {
            int dis = front(myqueue);
            printf("%d", dis);
            if (i > 2) {
                printf(", ");
            }
            dequeue(myqueue);
            i--;
            int top = front(myqueue);
            enqueue(myqueue, top);
            dequeue(myqueue);
        }
        printf("\nCarta restante: %d\n", front(myqueue));
        myqueue = createQueue();
    }
    return 0;
}

