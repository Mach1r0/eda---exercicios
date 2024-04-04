#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string in-place using recursion
void reverse(char *str, int start, int end) {
    // Base case: if the start index is greater than or equal to the end index, return
    if (start >= end) {
        return;
    }
    // Swap characters at the start and end positions
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    // Recursively call reverse on the remaining substring
    reverse(str, start + 1, end - 1);
}

int main() {
    char string[1001];  // Declare a character array to store the input string
    scanf("%s", string); // Read a string from the user (without spaces)
    int n = strlen(string); // Calculate the length of the input string

    // Call the reverse function to reverse the input string in-place
    reverse(string, 0, n - 1);

    // Print the reversed string followed by a newline character
    printf("%s\n", string);

    return 0; // Exit the program with a status code of 0
}
