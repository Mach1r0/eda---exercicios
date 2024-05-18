#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist{
    int dado; 
    struct linkedlist* prox;
} linkedlist; 

typedef struct hash{
    linkedlist* data; 
    int key; 
} hash;

hash *array;
int capacity = 0; 

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

int hashfunction(int x){
    return(x  % 13); 
}

linkedlist* insertion(int key, int x) {
    int index = hashfunction(key);
    linkedlist* new = malloc(sizeof(linkedlist));
    if (new == NULL) return NULL;
    new->dado = x;
    new->prox = NULL;

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
    initArray(13);  
    insertion(7, 7);
    insertion(7, 9);  

    for (int i = 0; i < capacity; i++) {
        if (array[i].data != NULL) {
            printf("%d -> ", array[i].key);
            linkedlist* current = array[i].data;
            while (current != NULL) {
                printf("%d -> ", current->dado);
                current = current->prox;
            }
            printf("\\\n");
        }
    }
    return 0;
}