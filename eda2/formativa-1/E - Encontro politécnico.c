#include <stdio.h>

int main() {
    int N, M, P;
    scanf("%d %d", &N, &M); // Reading the dimensions of the campus
    scanf("%d", &P); // Reading the number of steps

    int PA_x = 1, PA_y = 1; // Initial position of Professor PA
    int PB_x = N, PB_y = M; // Initial position of Professor PB

    for (int i = 1; i <= P; i++) {
        int dir_PA, dir_PB;
        scanf("%d %d", &dir_PA, &dir_PB); // Reading the direction of movement for both professors

        // Movement of Professor PA
        switch (dir_PA) {
            case 1: PA_y++; break; // North
            case 2: PA_y--; break; // South
            case 3: PA_x++; break; // East
            case 4: PA_x--; break; // West
        }

        // Movement of Professor PB
        switch (dir_PB) {
            case 1: PB_y++; break; // North
            case 2: PB_y--; break; // South
            case 3: PB_x++; break; // East
            case 4: PB_x--; break; // West
        }

        // Checking if the professors have met
        if (PA_x == PB_x && PA_y == PB_y) {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", PA_x, PA_y, i);
            return 0;
        }

        // Checking if any professor has left the campus
        if (PA_x < 1 || PA_x > N || PA_y < 1 || PA_y > M) {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", PA_x, PA_y, i);
            return 0;
        }
        if (PB_x < 1 || PB_x > N || PB_y < 1 || PB_y > M) {
            printf("PB saiu na posicao (%d,%d) no passo %d\n", PB_x, PB_y, i);
            return 0;
        }
    }

    printf("Nao se encontraram\n");

    return 0;
}
