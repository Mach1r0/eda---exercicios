#include<stdio.h>

int main(){
    int N, M; //number of lines of park 
    scanf("%d %d", &M, &N);
    int X, Y; // coordinate of microphone
    scanf("%d %d", &X, &Y);
    int K; //number of squares the men passed
    scanf("%d ", &K);
    int mens_x = 0,  mens_y = 0 ; 
    int direction ;
    int captured = 0;
    for (int i = 0; i < K; i++){
        scanf(" %d", &direction); 
        // Update the men's position based on the direction
        switch (direction){
        case 1 : mens_y++; break; // move right
        case 2 : mens_y--; break; // move left 
        case 3 : mens_x++; break; // move down 
        case 4 : mens_x--; break; // move up
    }
    // If the men are within a 1-square range of the microphone, increment the number of minutes of conversation captured
        if (mens_x >= X - 1 && mens_x <= X + 1 && mens_y >= Y - 1 && mens_y <= Y + 1){
            captured ++;
        }
    }
    printf("%d\n", captured);

    return 0;
}