#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
} tree;

int leaf_number(tree *root){
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    int count = leaf_number(root->left);
    int count2 = leaf_number(root->right);
    return count + count2;
}