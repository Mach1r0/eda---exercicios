#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1111

int main() {
    int a[MAX_SIZE], n;
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        int k = 0, i = 0;
        int st[MAX_SIZE];
        int top = -1;
        while (i < n) {
            while (top >= 0 && st[top] == k + 1) k++, top--;
            if (a[i] != k + 1) st[++top] = a[i];
            else k++;
            i++;
        }
        while (top >= 0 && st[top] == k + 1) k++, top--;
        if (k == n) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
