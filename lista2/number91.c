#include <stdio.h>

int f91(int n) {
    if (n >= 101) {
        return n - 10;
    } else {
        return f91(f91(n + 11));
    }
}

int main() {
    int n;
    int number[1000]; // Declare an array
    int count = 0; // To save the position in the array
    
    while (1) {
        scanf("%d", &n); // Read the number from the user

        if (n == 0) {
            break; // Condition to stop the loop
        }

        int result = f91(n); // Calculate f91 for the input
        number[count] = result; // Store the result in the array    
        count++; // Increment the count
    }

    // Print the stored numbers
    for (int i = 0; i < count; i++) { // Loop through the array
        printf("f91(%d) = %d\n", number[i], number[i]); // Print the position of the array specified in the loop
    }

    return 0;
}