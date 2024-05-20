#include<stdio.h>
#include<stdlib.h>
typedef int item;

typedef struct Tree{
    int dado; 
    tree *left; 
    tree *right; 
} tree; 

void inorder (tree *Tree){
    if (Tree == NULL) return; 
    inorder(Tree->left);
    printf("%d ", Tree->dado); 
    inorder(Tree->right); 
}

void posorder(tree *tree){
    if (tree == NULL) return;
    posorder(tree->left);
    posorder(tree->right);
    printf("%d", tree->dado);
}

void preorder(tree *Tree){
    if (Tree == NULL) return; 
    printf("%d", Tree->dado);
    preorder(Tree->left);
    preorder(Tree->right);
}