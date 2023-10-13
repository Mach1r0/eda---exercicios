#include <stdio.h>

void stringiverse(char* str, int i, int f) {
    if (i >= f) return; // if initial index is greater than final index, return
    
    // function to swap two characters
    char temp = str[i];
    str[i] = str[f];
    str[f] = temp;

    //recursive call
    stringiverse(str, i + 1, f - 1);
}

int main() {
    char str[501];
    scanf("%s", str);

    int len = strlen(str);
    stringiverse(str, 0, len - 1); 

    printf("%s\n", str);
    return 0;
}
