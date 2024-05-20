#include<stdio.h>
#include<stdlib.h>

//create struct for linked list
typedef struct linkedlist{
    int dado; 
    linkedlist* prox;
} linkedlist; 

// struct for hash values
typedef struct hash{
    linkedlist* data; 
    int key; 
} hash;

// the array is array of struct of hash
hash *array;
int capacity = 0; 

//function to init the hashmap
void initArray(int size){
    capacity = size; 
    array = (hash*) malloc(capacity * sizeof(hash));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    for (int i = 0; i < capacity; i++){
        array[i].key = 0; 
        array[i].data = NULL; 
    }
}

//function to hashing the number 
int hashfunction(int key){
    return key % capacity; 
}
// function to insert node into a hash table
linkedlist* insertion(int key, int x) {
    int index = hashfunction(key);
    linkedlist* new = malloc(sizeof(linkedlist)); // alocate memory for the new node
    if (new == NULL) return NULL;
    new->dado = x; 
    new->prox = NULL;

    //if the index of array is ocupated
    if (array[index].data != NULL){
        linkedlist* current = array[index].data;
        //find the last node of linked list collision
        while (current->prox != NULL){
            current = current->prox;
        } 
        current->prox = new; // add new node on the end of list
    } else {
        // If no collision or key doesn't exist
        array[index].data = new;
        array[index].key = key;
    }

    return new;
}

int main(){
    int N; 
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        int M, C; 
        scanf("%d %d", &M, &C);
        initArray(M);  // initialize the hash table with M base addresses
        for (int j = 0; j < C; j++){  // insert C number of values into the hash table
            int temp;
            scanf("%d", &temp);
            insertion(temp, temp); 
        }

        for (int i = 0; i < capacity; i++) { //print the hash table 
            printf("%d -> ", i);
            linkedlist* current = array[i].data;
            while (current != NULL) {
                printf("%d -> ", current->dado);
                current = current->prox;
            }
            printf("\\\n");
        }
        printf("\n");   
        // Free the memory allocated for the hash table
        for (int i = 0; i < capacity; i++) {
            linkedlist* current = array[i].data;
            while (current != NULL) {
                linkedlist* temp = current;
                current = current->prox;
                free(temp);
            }
        }
        free(array);
    }
    return 0;
}