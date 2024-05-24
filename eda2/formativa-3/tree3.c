#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist{
    int dado; 
    struct linkedlist* prox; 
} linkedlist; 

typedef struct tree{
    linkedlist root; 
    struct tree* left; 
    struct tree* right; 
} tree; 

void starTree(tree *tr){
    tree* newTree = (tree*) malloc(sizeof(tree)); 
    if (newTree == NULL) return NULL; 
    linkedlist* newnode = (newnode*) malloc(sizeof(linkedlist)); 
    newTree->root.dado = NULL; 
    newTree->left = NULL; 
    newTree->right = NULL; 
} 

void insertionTree(tree *t , int data, int key){
    tree * newnode = (tree*) malloc(sizeof(tree));
    int index =  
    if (newnode == NULL) return NULL; 
    if (newnode->root.dado == NULL){
         newnode->root.dado = data;
    }
    
    
} 
