#include <stdio.h>

void changex(char *str, int index) {
    //base case, if the string is empty, return 0 
    if (str[index] == '\0') {
        return;
    }
    // if x swap to y
    if (str[index] == 'x') {
        str[index] = 'y';
    }
    // call the function again, until the string is empty
    changex(str, index + 1);
}

int main() {
    char swapxy[100];

    scanf("%s", swapxy);
    changex(swapxy, 0);

    printf("%s\n", swapxy);
    
    return 0;
}
