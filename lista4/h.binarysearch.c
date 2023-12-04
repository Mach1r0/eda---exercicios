#include <stdio.h>
#include <stdlib.h>

int binarysearch(int *v, int n, int x)
{
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (v[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
int main(void)
{
    int N, Q, J;
    scanf("%d %d", &N, &Q);
    int v[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &J);
        int resultado = binarysearch(v, N, J);
        printf("%d\n", resultado);
    }
    return 0;
}