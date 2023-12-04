#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

int hash_table[MAX];

void createHashTable(int *v, int n) {
    memset(hash_table, -1, sizeof(hash_table));
    for (int i = 0; i < n; i++) {
        hash_table[v[i]] = i;
    }
}

int main(void)
{
    int N, Q, J;
    
    scanf("%d %d", &N, &Q);
    
    int v[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    createHashTable(v, N);

    for (int i = 0; i < Q; i++) {
        scanf("%d", &J);
        printf("%d\n", hash_table[J]);
    }

    return 0;
}