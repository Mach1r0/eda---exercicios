#include <stdio.h>
#include <string.h>

void constructPostfix(char *preorder, char *inorder, char *postfix, int *postfixIndex, int n) {
    if (n <= 0) return;

    char root = preorder[0];

    int rootIndex;
    for (rootIndex = 0; rootIndex < n; rootIndex++) {
        if (inorder[rootIndex] == root) break;
    }

    constructPostfix(preorder + 1, inorder, postfix, postfixIndex, rootIndex);

    constructPostfix(preorder + 1 + rootIndex, inorder + rootIndex + 1, postfix, postfixIndex, n - rootIndex - 1);

    postfix[(*postfixIndex)++] = root;
}

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N;
        scanf("%d", &N);

        char preorder[53], inorder[53], postfix[53];
        scanf("%s %s", preorder, inorder);

        int postfixIndex = 0;
        constructPostfix(preorder, inorder, postfix, &postfixIndex, N);

        postfix[postfixIndex] = '\0';

        printf("%s\n", postfix);
    }

    return 0;
}
