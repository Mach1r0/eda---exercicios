#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int root; 
    struct tree *left;
    struct tree *right;
} tree;

// This function calculates the height of a binary tree.
int height(){
    if (root == NULL) return 0; // empty tree, return 0
    int h_left, h_right;
    h_left = (root->left); // initialize left height to the height of the left subtree
    h_right = (root->right); // initialize right height to the height of the right subtree
    char *stack[500]; // declare stack
    int top = -1; // declare top of stack, -1 means empty stack
    stack[++top] = root; // push the root node onto the stack
    while (top != -1){ // run all the tree
        if (root->left != NULL){ // push the left child onto the stack (if it exists)
            stack[++top] = root->left;
            h_left++;
        }else if (root->right != NULL){ // push the right child onto the stack (if it exists)
            stack[++top] = root->right;
            h_right++;
        }
    }
    if (h_left > h_right) return 1 + h_left; // return the height of the left subtree plus one
    else return 1 + h_right; // return the height of the right subtree plus one
}