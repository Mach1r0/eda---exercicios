#include <stdio.h>
#include<stdlib.h>

typedef struct linkedlist{
    int dado; 
    struct linkedlist* prox;
} linkedlist; 

typedef struct tree{
    linkedlist* root; 
    struct tree* left;
    struct tree* right; 
} tree;

tree* insertionTree(tree* t, int dado){
    if (t == NULL) {
        t = (tree*) malloc(sizeof(tree)); 
        if (t == NULL) return NULL; 
        t->root = (linkedlist*) malloc(sizeof(linkedlist));
        t->root->dado = dado; 
        t->left = NULL; 
        t->right = NULL;
    }
    else if (t->root->dado > dado){
        t->left = insertionTree(t->left, dado); 
    } else{
        t->right = insertionTree(t->right, dado);
    }
    return t;
}

void printTree(tree *t){
    if (t != NULL){
        printTree(t->left);
        printf("%d \n", t->root->dado); 
        printTree(t->right);        
    }
}

int main(void){
    tree *t = NULL;
    t = insertionTree(t, 40);
    t = insertionTree(t, 0);
    t = insertionTree(t, 30);
    t = insertionTree(t, 50);
    printTree(t); 

    return 0;
}