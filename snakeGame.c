#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 20

// Snake head coordinates
int x, y;

// Fruit coordinates
int fruitX, fruitY;

// Score and tail details
int score;
int tailX[100], tailY[100];
int nTail;

// Game control flags
int gameover;

// Direction enumeration
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir, prevDir;

// Setup initial game state
void setup() {
    gameover = 0;
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    nTail = 0;
}

// Draw the game area
void draw() {
    system("cls"); // Clear screen

    // Top boundary
    for (int i = 0; i < WIDTH + 2; i++) printf("##");
    printf("\n");

    // Main grid
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) printf("##"); // Left boundary

            if (i == y && j == x)
                printf("[]"); // Snake head
            else if (i == fruitY && j == fruitX)
                printf("**"); // Food
            else {
                int printed = 0;

                // Draw the tail
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("oo");
                        printed = 1;
                        break;
                    }
                }

                if (!printed) printf("  "); // Empty space
            }

            if (j == WIDTH - 1) printf("##"); // Right boundary
        }
        printf("\n");
    }

    // Bottom boundary
    for (int i = 0; i < WIDTH + 2; i++) printf("##");
    printf("\n");

    // Display score
    printf("Score: %d\t(Press 'q' to quit)\n", score);
}

// Handle user input
void input() {
    if (_kbhit()) {
        int first = _getch();

        // Check if it's an arrow key
        if (first == 0 || first == 224) {
            int ch = _getch();
            switch (ch) {
                case 72: if (prevDir != DOWN) dir = UP; break;    // Up arrow
                case 80: if (prevDir != UP) dir = DOWN; break;    // Down arrow
                case 75: if (prevDir != RIGHT) dir = LEFT; break; // Left arrow
                case 77: if (prevDir != LEFT) dir = RIGHT; break; // Right arrow
            }
        } 
        else if (first == 'q' || first == 'Q') {
            gameover = 1; // Quit the game
        }
    }
}

// Game logic (movement, collision, growth)
void logic() {
    prevDir = dir;

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    // Move tail
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Move head
    switch (dir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
        default: break;
    }

    // Wrap around screen edges
    if (x >= WIDTH) x = 0;
    else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0;
    else if (y < 0) y = HEIGHT - 1;

    // If snake eats fruit
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }

    // Check for collision with tail
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameover = 1;
    }
}

int main() {
    setup();

    // Game loop
    while (!gameover) {
        draw();
        input();
        logic();
        Sleep(100); // Control speed
    }

    system("cls");
    printf("\n\tGAME OVER!\n\tYour Score: %d\n", score);
    printf("\n\tPress any key to exit...\n");
    getch();

    return 0;
}
