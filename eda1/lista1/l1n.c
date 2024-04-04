#include <stdio.h>

int main() {
    int N, n1;

    scanf("%d", &N);

    int v[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    scanf("%d", &n1);

    int pertence = 0; 

    for (int j = 0; j < N; j++) {
        if (v[j] == n1) {
            pertence = 1;
            break;
        }
    }

    if (pertence) {
        printf("pertence\n");
    } else {
        printf("nao pertence\n");
    }

    return 0;
}
