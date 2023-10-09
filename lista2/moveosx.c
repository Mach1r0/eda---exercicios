#include <stdio.h>
#include <string.h>

void moveX(char str[], int len) {
    int xCount = 0;
    int currentIndex = 0;

    // Count 'x' characters and skip them while copying
    for (int i = 0; i < len; i++) {
        if (str[i] != 'x') {
            str[currentIndex++] = str[i];
        } else {
            xCount++;
        }
    }
    
    // Fill the end of the string with 'x' characters
    for (int i = 0; i < xCount; i++) {
        str[currentIndex++] = 'x';
    }

    // Null-terminate the string
    str[currentIndex] = '\0';
}

int main() {
    char str[101];
    scanf("%s", str);

    int len = strlen(str);

    // Call the 'moveX' function
    moveX(str, len);

    printf("%s\n", str);

    return 0;
}
