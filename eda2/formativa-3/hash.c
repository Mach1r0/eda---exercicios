#include<stdio.h>
#include<stdlib.h>

// creating linked list to store my data 
typedef struct linkedlist{
    int dado; 
    struct linkedlist* prox; 
}linkedlist; 

typedef struct hash{
    linkedlist* root; 
    int key; 
} hash; 

// creating function to hashing the data 
int hashing(int key, int size){
    return (key % size); 
}

// function to init the hash
hash* startHash(int size){
    hash * newhash = (hash*) malloc(size * sizeof(hash)); 
    if (newhash == NULL) return NULL; 
    for (int  i = 0; i < size; i++){
        newhash[i].root = NULL; 
        newhash[i].key = i; 
    }
    return newhash;
}

void insertionHash(hash* h, int size, int data){
    int index = hashing(data, size); 
    linkedlist* newnode = (linkedlist*) malloc(sizeof(linkedlist));
    newnode->dado = data;
    newnode->prox = h[index].root;
    h[index].root = newnode;
}
void printedHash(hash *h, int size){
    for (int i = 0; i < size; i++) {
        linkedlist* current = h[i].root; 
        while (current != NULL){ 
            printf("%d ", current->dado);
            current = current->prox;
        }
        printf("\n");
    }
}

int main(){
    int size = 30;
    hash* h = startHash(size);
    if (h == NULL) {
        printf("Failed to allocate memory for hash table\n");
        return 1;
    }
    insertionHash(h, size, 0); 
    insertionHash(h, size, 40); 
    insertionHash(h, size, 50); 
    insertionHash(h, size, 60); 
    printedHash(h, size);
    return 0;
}