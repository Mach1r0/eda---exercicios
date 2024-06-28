#include <stdio.h>
#include <stdlib.h>

// Define constants for maximum nodes
#define MAX_NODES 500000

// Define node structure
typedef struct {
    int type; // 1 for green, 2 for red
    int left;
    int right;
} Node;

// Define queue structure for BFS
typedef struct {
    int node;
    int level;
} QueueNode;

int main() {
    int N;
    scanf("%d", &N);

    // Allocate memory for nodes
    Node* nodes = (Node*)malloc(N * sizeof(Node));

    // Read the root node
    int root, left, right;
    scanf("%d %d %d", &root, &left, &right);

    nodes[0].type = 0; // root
    nodes[0].left = left;
    nodes[0].right = right;

    // Read the remaining nodes
    for (int i = 1; i < N; i++) {
        int type, left, right;
        scanf("%d %d %d", &type, &left, &right);
        nodes[i].type = type;
        nodes[i].left = left;
        nodes[i].right = right;
    }

    // Allocate memory for queue
    QueueNode* queue = (QueueNode*)malloc(N * sizeof(QueueNode));
    int front = 0, rear = 0;

    // Enqueue the root node
    queue[rear++] = (QueueNode){0, 0};

    // Allocate memory for level counters
    int* greenCounts = (int*)calloc(N, sizeof(int));
    int* redCounts = (int*)calloc(N, sizeof(int));
    int maxLevel = 0;

    // Perform BFS
    while (front < rear) {
        QueueNode current = queue[front++];
        int currentNode = current.node;
        int currentLevel = current.level;

        // Update the counters
        if (nodes[currentNode].type == 1) {
            greenCounts[currentLevel]++;
        } else if (nodes[currentNode].type == 2) {
            redCounts[currentLevel]++;
        }

        // Enqueue children
        if (nodes[currentNode].left != 0) {
            queue[rear++] = (QueueNode){nodes[currentNode].left - 1, currentLevel + 1};
        }
        if (nodes[currentNode].right != 0) {
            queue[rear++] = (QueueNode){nodes[currentNode].right - 1, currentLevel + 1};
        }

        // Update max level
        if (currentLevel > maxLevel) {
            maxLevel = currentLevel;
        }
    }

    // Print results
    for (int i = 1; i <= maxLevel; i++) {
        printf("%d %d\n", greenCounts[i], redCounts[i]);
    }

    // Free allocated memory
    free(nodes);
    free(queue);
    free(greenCounts);
    free(redCounts);

    return 0;
}
