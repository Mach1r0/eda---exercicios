#include<stdio.h>

#define MAX_SIZE 31

int main(){
    int size;
    char side;
    int count = 0;
    int left[MAX_SIZE] = {0}, right[MAX_SIZE] = {0};
// read the size while don't press ctrl+d or end of file
    while (scanf("%d %c", &size, &side) != EOF) {
        if (side == 'D') { 
            if (left[size - 30] > 0) { // if there is a left shoe of the same size
                left[size - 30]--; // remove it
                count++; // count a pair
            } else {
                right[size - 30]++; // else, add a right shoe of the same size
            }
        } else {
            if (right[size - 30] > 0) { // if the right shoe of the same size exists
                right[size - 30]--; // remove it
                count++; // count a pair
            } else {
                left[size - 30]++; // the same as above
            }
        }
    }

    printf("%d\n", count); // print the final result 
    return 0;
} uueee
