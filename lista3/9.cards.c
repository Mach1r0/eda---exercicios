#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define a structure for a queue using linked list
typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

// Function to initialize an empty queue
Queue *initializeQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to enqueue (push) a new element into the queue
void enqueue(Queue *q, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue (pop) an element from the queue
int dequeue(Queue *q) {
    if (q->front == NULL) {
        // Queue is empty
        return -1; // Assuming -1 represents an invalid value
    }
    
    int data = q->front->data;
    Node *temp = q->front;
    
    q->front = q->front->next;
    free(temp);
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    return data;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == NULL;
}

int main() {
    int numPlayers, i, card, roundCount = 0;
    Queue *cardQueue;

    cardQueue = initializeQueue();

    do {
        // Input the number of players
        scanf("%d", &numPlayers);

        if (numPlayers) {
            roundCount = numPlayers;

            // Initialize the queue with cards
            for (i = 1; i <= numPlayers; i++) {
                enqueue(cardQueue, i);
            }

            // Display discarded cards
            printf("Discarded cards:");

            while (roundCount != 1) {
                printf(" %d", dequeue(cardQueue));
                enqueue(cardQueue, dequeue(cardQueue));

                if (roundCount != 2)
                    printf(",");
                roundCount--;
            }

            // Display remaining card
            if (!isEmpty(cardQueue))
                printf("\nRemaining card: %d\n", dequeue(cardQueue));
        }
    } while (numPlayers != 0);

    return 0;
}
