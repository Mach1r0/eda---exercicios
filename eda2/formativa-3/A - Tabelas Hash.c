#include<stdio.h>
#include<stdlib.h>
typedef int item;  

typedef struct linkedlist{
    int dado; 
    linkedlist* prox;
} linkedlist; 

typedef struct hash{
    int data; 
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
        array[i].data = 0; 
    }
};
int hashfunction(int x){
    return(x  % 13); 
};
int key = 13; 
int insertion(int key, int x){
    
    int index = hashfunction(key);
    item* novo  = malloc(sizeof(item));
    if (novo == NULL) return;     
    if (array[index].data == 0){
        array[index].data = x; 
        array[index].key = key;
        capacity++;
    }
    else if(array[index].key == key){
        array[index].data = x; 
    }
    else {
        array[index].data->prox = x;  
    }
};
