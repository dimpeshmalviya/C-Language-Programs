#include <stdio.h>

#define ROWS 8
#define COLS 8

void floodFill(int screen[ROWS][COLS], int x, int y, int prevC, int newC) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS)
        return;
    if (screen[x][y] != prevC)
        return;

    screen[x][y] = newC;

    floodFill(screen, x+1, y, prevC, newC);
    floodFill(screen, x-1, y, prevC, newC);
    floodFill(screen, x, y+1, prevC, newC);
    floodFill(screen, x, y-1, prevC, newC);
}

void printScreen(int screen[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%d ", screen[i][j]);
        printf("\n");
    }
}

int main() {
    int screen[ROWS][COLS] = {
        {1, 1, 1, 2, 2, 2, 3, 3},
        {1, 2, 2, 2, 3, 3, 3, 1},
        {1, 2, 3, 3, 1, 1, 3, 1},
        {1, 2, 2, 3, 3, 3, 1, 1},
        {2, 2, 3, 3, 1, 1, 3, 2},
        {2, 2, 1, 1, 1, 2, 2, 2},
        {1, 1, 2, 1, 1, 2, 2, 3},
        {3, 2, 1, 2, 3, 3, 1, 1}
    };
    int x = 4, y = 4, newC = 9;
    int prevC = screen[x][y];
    floodFill(screen, x, y, prevC, newC);
    printScreen(screen);
    return 0;
}
