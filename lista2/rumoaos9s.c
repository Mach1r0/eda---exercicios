#include <stdio.h>
#include <ctype.h>

int main() {
    char number9s[1001];

    while (1) {
        // Read a string of digits from the user
        scanf("%s", number9s);
        
        // Check if '0' is the only character in the input, indicating the end of input
        if (number9s[0] == '0' && number9s[1] == '\0')
            break;
        
        int sum = 0;
        int degree = 0;
        
        // Calculate the sum of digits in the input string
        for (int i = 0; number9s[i] != '\0'; i++) {
            sum += number9s[i] - '0';
        }

        // Keep reducing the sum by summing its digits while it's a multiple of 9 and greater than 9
        while (sum % 9 == 0 && sum > 9) {
            int newSum = 0;
            // Calculate the new sum by summing the digits of the current sum
            while (sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
            degree++;
        }

        // Check the final value of the sum to determine if it's a multiple of 9
        if (sum == 9) {
            degree++;
            // Print the result if it's a multiple of 9
            printf("%s is a multiple of 9 and has 9-degree %d.\n", number9s, degree);
        } else {
            // Print the result if it's not a multiple of 9
            printf("%s is not a multiple of 9.\n", number9s);
        }
    }

    return 0;
}
