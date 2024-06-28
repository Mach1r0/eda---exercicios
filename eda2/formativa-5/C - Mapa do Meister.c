#include <stdio.h>
#include <stdbool.h>

// Function to explore the map and determine if it leads to a chest
bool exploreMap(char map[100][100], int width, int height) {
    int x = 0, y = 0;
    bool visited[100][100] = {false};

    while (x >= 0 && x < width && y >= 0 && y < height) {
        if (visited[y][x]) return false;  // Loop detected
        visited[y][x] = true;

        switch (map[y][x]) {
            case '>': x++; break;
            case '<': x--; break;
            case 'v': y++; break;
            case '^': y--; break;
            case '*': return true;  // Chest found
            case '.': break;  // Empty space, continue
            default: return false;  // Invalid character
        }
    }
    return false;  // Out of bounds
}

int main() {
    int width, height;
    scanf("%d %d", &width, &height);
    char map[100][100];

    for (int i = 0; i < height; i++) {
        scanf("%s", map[i]);
    }

    if (exploreMap(map, width, height)) {
        printf("*\n");
    } else {
        printf("!\n");
    }
    return 0;
}
