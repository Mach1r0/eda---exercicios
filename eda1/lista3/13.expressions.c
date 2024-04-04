#include <stdio.h>
#include <string.h>

int MAX = 1000001;

int main(void)
{
    char stack[MAX];
    char input[MAX], inverse;
    int test_cases, length, index, position, error;

    scanf("%d", &test_cases);

    while (test_cases--) {
        scanf("%s", input);
        length = strlen(input);

        position = error = 0;

        for (index = 0; index < length; index++) 
        {
            // Check if the character is an opening bracket
            if (strchr("([{", input[index])) {
                // Push the opening bracket onto the stack
                stack[position++] = input[index];
            } else {
                // Determine the corresponding opening bracket for the current closing bracket
                inverse = (input[index] == ')' ? '(' : (input[index] == ']' ? '[' : '{'));
                // Check for matching brackets
                if ((position == 0) || (stack[--position] != inverse)) {
                    error = 1; // Set error flag if brackets do not match
                    break;
                }
            }
        }
        // Check for any remaining brackets on the stack or errors
        if ((position > 0) || error) {
            puts("N");
        } else {
            puts("S"); 
        }
    }

    return 0;
}
