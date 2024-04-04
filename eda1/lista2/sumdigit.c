#include <stdio.h>

// Function to convert a character digit to an integer
int charToDigit(char c) {
    return c - '0';
}

// Function to check sum of digits using recursion
int sum_of_digit(char* num_str, int index) {
    if (num_str[index] == '\0') {
        return 0; // End of the string, return 0
    }
    return charToDigit(num_str[index]) + sum_of_digit(num_str, index + 1);
}
 
int main()
{
    char num_str[100]; // Define a character array to store the input as a string
    scanf("%s", num_str); // Read the number as a string
    
    int result = sum_of_digit(num_str, 0);
    printf("%d", result);
    return 0;
}
