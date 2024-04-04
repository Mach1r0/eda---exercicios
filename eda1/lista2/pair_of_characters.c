#include <stdio.h>

// Recursive function to count pairs of characters in a string
int countPairs(char* str, char prev, char prevPrev) {
    if (str[0] == '\0') {
        return 0; // Base case: if the string is empty, return 0
    }

    if (str[0] == prevPrev) {
        // If the current character forms a pair with the character two positions back
        // and it's different from the previous character, count it and continue the search
        return 1 + countPairs(str + 1, str[0], prev);
    }

    // If no pair is found, continue the search with updated character positions
    return countPairs(str + 1, str[0], prev);
}

int main(void) {
    char a[201];
    scanf("%s", a); 
    int result = countPairs(a, '\0', '\0');
    printf("%d\n", result); 

    return 0;
}
