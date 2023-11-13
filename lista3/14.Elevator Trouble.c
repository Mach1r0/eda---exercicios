#include<stdio.h>
#include<stdlib.h>

// Define a struct node with two properties: position and stepsTaken
struct node{
    int position;
    int stepsTaken;
};

// Define a new type Node for the struct node
typedef struct node Node;

// Function to create a new Node with given position and steps
Node newState(int position, int steps){
    Node n;  // Declare a new Node variable
    n.position = position;  // Set the position of the Node
    n.stepsTaken = steps;  // Set the number of steps taken to reach this Node
    return n;  // Return the newly created Node
}

int main(){
    int floors, start, goal, up, down, steps = -1;
    // Read the input values
    scanf("%d %d %d %d %d", &floors, &start, &goal, &up, &down);
    
    // Initialize an array to keep track of visited positions
    int* visited = (int*)calloc(floors+1, sizeof(int));
    
    // Initialize a queue to keep track of nodes to be visited
    Node* queue = (Node*)malloc((floors+1)*sizeof(Node));
    
    int front = 0;
    int rear = 0;
    
    // Add the start position to the queue
    queue[rear++] = newState(start,0);
    
    // While there are nodes in the queue
    while(front != rear){
        // Get the next node from the queue
        Node current = queue[front++];
        
        // If the current position is the goal, update steps and break the loop
        if(current.position == goal){
            steps = current.stepsTaken;
            break;
        }
        
        // If moving up is within bounds and the new position hasn't been visited
        if(current.position + up <= floors && !visited[current.position + up]){
            // Mark the new position as visited
            visited[current.position + up] = 1;
            
            // Add the new position to the queue
            queue[rear++] = newState(current.position + up, current.stepsTaken + 1);
        }
        
        // If moving down is within bounds and the new position hasn't been visited
        if(current.position - down >= 1 && !visited[current.position - down]){
            // Mark the new position as visited
            visited[current.position - down] = 1;
            
            // Add the new position to the queue
            queue[rear++] = newState(current.position - down, current.stepsTaken + 1);
        }
    }
    
    // If steps is still -1, print "use the stairs"
    if(steps == -1) printf("use the stairs");
    // Otherwise, print the number of steps
    else printf("%d", steps);
    
    // Free the memory allocated for visited and queue
    free(visited);
    free(queue);
    
    return 0;
}