#include <stdio.h>
#include <string.h>

void moveXsRecursive(char *str, int start, int end) {
    if (start >= end) {
        return;
    }

    if (str[start] == 'x') {

        memmove(&str[start], &str[start + 1], end - start);
        str[end] = 'x';
        moveXsRecursive(str, start, end - 1);
    } else {
        moveXsRecursive(str, start + 1, end);
    }
}

int main() {
    char str[1000]; 

    scanf("%s", str);

    int len = strlen(str);

    moveXsRecursive(str, 0, len - 1);

    printf("%s\n", str);

    return 0;
}
