#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        int order[1000];
        for (int i = 0; i < n; i++) {
            scanf("%d", &order[i]);
        }

        int expected_order = 1;  // The expected order of the next love mobile
        int stack[1000];         // Use an array as a stack to simulate the side street
        int stack_size = 0;

        int possible = 1;  // 1 represents "yes," and 0 represents "no"

        for (int i = 0; i < n; i++) {
            // If the current love mobile is in the expected order, simply move to the next expected order.
            while (stack_size > 0 && stack[stack_size - 1] == expected_order) {
                expected_order++;
                stack_size--;
            }

            if (order[i] == expected_order) {
                expected_order++;
            } else {
                // Otherwise, push the love mobile onto the side street.
                stack[stack_size] = order[i];
                stack_size++;
            }
        }

        // After processing all love mobiles in the approach street, check if there are any love mobiles left in the side street.
        while (stack_size > 0) {
            if (stack[stack_size - 1] == expected_order) {
                expected_order++;
                stack_size--;
            } else {
                possible = 0;
                break;
            }
        }

        if (possible) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
