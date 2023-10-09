#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);

    int len = strlen(str); // Get the length of the string
    int x_found = 1;  // Flag to indicate if 'x' is found initially

    while (x_found) { // Loop until 'x' is not found
        x_found = 0;  // Reset the flag at the beginning of each loop

        for (int i = 0; i < len; i++) {
            if (str[i] == 'x') {
                // Shift characters to the left to overwrite 'x'
                for (int j = i; j < len - 1; j++) {
                    str[j] = str[j + 1];
                }

                // Place 'x' at the end
                str[len - 1] = 'x';

                // Update the length to account for the moved 'x'
                len--; 

                // Set the flag to indicate that 'x' was found in this iteration
                x_found = 1;  
            }
        }
    }

    printf("%s\n", str);
}
