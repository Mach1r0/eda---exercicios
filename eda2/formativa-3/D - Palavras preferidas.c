#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct linkedlist{
    char data[50]; 
    int count; 
    struct linkedlist* prox;
} linkedlist;
    
typedef struct hash{
    linkedlist * node;
    int key;  
}hash;

int hashing(char *str) {
    int hash = 0;
    int c;

    while (c = *str++)
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash & (256 - 1);
}

void insertionhash(hash* h, char *word){
    int index = hashing(word);
    linkedlist *node = h[index].node;
    while (node != NULL){
        if (strcmp(node->data, word) == 0){
            node->count++;
            return;
        }
        node = node->prox;
    }

    linkedlist * newnode = (linkedlist*) malloc(sizeof(linkedlist)); 
    strcpy(newnode->data, word);
    newnode->count = 1;
    newnode->prox = h[index].node;
    h[index].node = newnode;
}

hash* initHashing(int size){
    hash* newhashing = (hash*) malloc(size * sizeof(hash));
    for (int i = 0; i < size; i++){
        newhashing[i].node = NULL;
    }
    return newhashing;
}

int searchHash(hash *h, char *word){
    int index = hashing(word);
    linkedlist *node = h[index].node;
    while (node != NULL){
        if (strcmp(node->data, word) == 0){
            return node->count;
        }
        node = node->prox;
    }
    return 0;   
}

void deletionhashing(hash *h, char *word){
    int index = hashing(word);
    linkedlist *node = h[index].node;
    linkedlist *prev = NULL;
    while (node != NULL){
        if (strcmp(node->data, word) == 0){
            if (prev == NULL){
                h[index].node = node->prox;
            } else {
                prev->prox = node->prox;
            }
            free(node);
            return;
        }
        prev = node;
        node = node->prox;
    }
}

void solve(){
    int n = 256; // ASCII range
    char word [50];
    hash* h = initHashing(n); 
    int command;
    while (scanf("%d %s", &command, word) != EOF){
        if (command == 1){
            insertionhash(h, word);
        }else if (command == 2){
            printf("%d\n", searchHash(h, word)); 
        }else if(command == 3){
            deletionhashing(h, word);
        }   
    }   
}

int main(){
    solve(); 
    return 0; 
}