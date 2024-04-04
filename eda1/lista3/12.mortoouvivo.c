#include <stdio.h>  

int main() { 
    int participants, lines, teste = 1;  
    while (scanf("%d%d", &participants, &lines)) {  // Read the number of participants and lines until EOF
        if (!lines) {  // If the number of lines is zero, end the program
            return 0;
        }
        int i, ordem, number, j, part;  // Declare more variables
        int v[participants];  // Declare an array to hold the participants
        for (i = 0; i < participants; i++) {  // For each participant
            scanf("%d", &v[i]);  // Read the participant's number
        }
        while (lines--) {  // For each line
            scanf("%d%d", &number, &ordem);  // Read the number of participants and the order
            for (i = 0, j = 0; i < number; i++, j++) {  // For each participant in the order
                scanf("%d", &part);  // Read the participant's number
                if (v[j]) {  // If the participant is still in the game
                    if (ordem != part) {  // If the order does not match the participant's number
                        v[j] = 0;  // Eliminate the participant
                    }
                } else {  // If the participant is already eliminated
                    for (; j < participants; j++) {  // Skip to the next participant
                        if (v[j]) {  // If the next participant is still in the game
                            if (ordem != part) {  // If the order does not match the participant's number
                                v[j] = 0;  // Eliminate the participant
                            }
                            break;  
                        }
                    }
                }
            }
        }
        int *p = v;  // Declare a pointer to the start of the array
        for (i = 0; i < participants; i++, p++) {  // For each participant
            if (*p) {  // If the participant is still in the game
                printf("Teste %d\n%d\n", teste++, *p);  // Print the test case number and the participant's number
                break;
            }
        }
    }
}  