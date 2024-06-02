#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate the height of the tree and check if it is balanced
int Height(TreeNode* root) {
    if (root == NULL) return 0;
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}

// Function to check if the tree is balanced
bool isBalanced(TreeNode* root) {
    if (root == NULL) return true;
    if (Height(root) == -1) return false;
    return true;
}

// Function to create a new tree node
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Main function to parse input, build the tree, and check if it's balanced
int main() {
    int N;
    scanf("%d", &N);

    if (N == 0) {
        printf("Nao\n");
        return 0;
    }

    TreeNode** nodes = (TreeNode**)malloc((N + 1) * sizeof(TreeNode*));
    for (int i = 1; i <= N; i++) {
        nodes[i] = createNode(i);
    }

    for (int i = 2; i <= N; i++) {
        int parentIndex;
        scanf("%d", &parentIndex);
        if (nodes[parentIndex]->left == NULL) {
            nodes[parentIndex]->left = nodes[i];
        } else {
            nodes[parentIndex]->right = nodes[i];
        }
    }

    bool result = isBalanced(nodes[1]);
    if (result) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    // Free allocated memory
    for (int i = 1; i <= N; i++) {
        free(nodes[i]);
    }
    free(nodes);

    return 0;
}
