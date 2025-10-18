/*
=====================================================
PROGRAM: Minesweeper (Console) in C
=====================================================

PROBLEM STATEMENT:
Implement a console-based Minesweeper game in C. The program
creates an MxN board with a number of randomly placed mines.
The player opens cells or places flags. Opening a mined cell
ends the game (loss). Opening a cell with zero adjacent mines
reveals neighboring cells recursively (flood-fill). The player
wins if all non-mine cells are revealed.

INPUT / OUTPUT EXAMPLES:

Example flow (user inputs shown after prompts):
------------------------------------------------
Choose difficulty: 1) Easy 2) Medium 3) Hard : 1
Board:
  0 1 2 3 4
0 _ _ _ _ _
1 _ _ _ _ _
2 _ _ _ _ _
...
Enter action (o = open, f = flag) and row col (e.g. o 1 3): o 1 3

If opened cell has adjacent mines:
You opened (1,3) - Adjacent mines: 2

If opened cell is zero, many cells reveal automatically.

If mine opened:
BOOM! You hit a mine at (2,4). Game Over.

If all safe cells revealed:
CONGRATULATIONS! You cleared the board!

COMPLEXITY:
- Time per move: O(1) for most moves; O(M*N) potential in worst-case for flood-fill.
- Space: O(M*N) for boards.

AUTHOR: Rik Maity (2025)

Build:
  gcc minesweeper.c -o minesweeper
Run:
  ./minesweeper
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define COLOR_RED    "\x1b[31m"
#define COLOR_GREEN  "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_CYAN   "\x1b[36m"
#define COLOR_RESET  "\x1b[0m"

typedef enum { HIDDEN = 0, REVEALED = 1, FLAGGED = 2 } CellState;

typedef struct {
    int rows;
    int cols;
    int mines;
    char *mineBoard;     // 'M' for mine, '0'..'8' for number counts
    CellState *state;    // HIDDEN/REVEALED/FLAGGED
    int revealedCount;   // number of non-mine cells revealed
} Board;

// Utility to access 2D as 1D
static inline int idx(const Board *b, int r, int c) {
    return r * b->cols + c;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printInstructions() {
    printf(COLOR_CYAN "Controls:\n" COLOR_RESET);
    printf(" - To open a cell:    o row col   (e.g. o 1 3)\n");
    printf(" - To place/remove a flag: f row col   (e.g. f 2 4)\n");
    printf(" - Rows and cols are 0-indexed in prompts.\n\n");
}

// Print visible board for player
void printBoard(const Board *b, int revealAll) {
    // Column header
    printf("    ");
    for (int c = 0; c < b->cols; c++) {
        printf("%2d ", c);
    }
    printf("\n   ");
    for (int c = 0; c < b->cols; c++) printf("---");
    printf("\n");

    for (int r = 0; r < b->rows; r++) {
        printf("%2d |", r);
        for (int c = 0; c < b->cols; c++) {
            int id = idx(b, r, c);
            if (revealAll) {
                // Show mines and numbers
                if (b->mineBoard[id] == 'M') {
                    printf(" %s*%s ", COLOR_RED, COLOR_RESET);
                } else if (b->mineBoard[id] == '0') {
                    printf("  . ");
                } else {
                    // show number in yellow
                    printf(" %s%c%s ", COLOR_YELLOW, b->mineBoard[id], COLOR_RESET);
                }
            } else {
                if (b->state[id] == REVEALED) {
                    if (b->mineBoard[id] == '0') printf("  . ");
                    else printf(" %s%c%s ", COLOR_YELLOW, b->mineBoard[id], COLOR_RESET);
                } else if (b->state[id] == FLAGGED) {
                    printf(" %sF%s ", COLOR_CYAN, COLOR_RESET);
                } else {
                    printf(" _  ");
                }
            }
        }
        printf("|\n");
    }
    printf("   ");
    for (int c = 0; c < b->cols; c++) printf("---");
    printf("\n");
}

// Place mines randomly (first naive placement)
void placeMines(Board *b, int safeR, int safeC) {
    int placed = 0;
    int total = b->rows * b->cols;
    while (placed < b->mines) {
        int pos = rand() % total;
        // avoid placing on same cell or on the initial safe cell or its neighbors
        if (b->mineBoard[pos] == 'M') continue;
        int r = pos / b->cols;
        int c = pos % b->cols;
        // avoid immediate first-open area (safeR,safeC and neighbors)
        if (abs(r - safeR) <= 1 && abs(c - safeC) <= 1) continue;
        b->mineBoard[pos] = 'M';
        placed++;
    }
}

// Count adjacent mines and fill mineBoard with char digits
void computeAdjacency(Board *b) {
    for (int r = 0; r < b->rows; r++) {
        for (int c = 0; c < b->cols; c++) {
            int id = idx(b, r, c);
            if (b->mineBoard[id] == 'M') continue;
            int count = 0;
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0) continue;
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < b->rows && nc >= 0 && nc < b->cols) {
                        if (b->mineBoard[idx(b, nr, nc)] == 'M') count++;
                    }
                }
            }
            b->mineBoard[id] = '0' + count;
        }
    }
}

// Flood-fill reveal for zero cells (recursive)
void revealDFS(Board *b, int r, int c) {
    if (r < 0 || r >= b->rows || c < 0 || c >= b->cols) return;
    int id = idx(b, r, c);
    if (b->state[id] == REVEALED || b->state[id] == FLAGGED) return;
    b->state[id] = REVEALED;
    // increment revealedCount only for non-mine cells (checked earlier)
    b->revealedCount++;
    if (b->mineBoard[id] == '0') {
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue;
                revealDFS(b, r + dr, c + dc);
            }
        }
    }
}

// Initialize board structure memory
Board *createBoard(int rows, int cols, int mines) {
    Board *b = malloc(sizeof(Board));
    b->rows = rows;
    b->cols = cols;
    b->mines = mines;
    b->mineBoard = malloc(rows * cols * sizeof(char));
    b->state = malloc(rows * cols * sizeof(CellState));
    b->revealedCount = 0;
    // init
    for (int i = 0; i < rows * cols; i++) {
        b->mineBoard[i] = '0';
        b->state[i] = HIDDEN;
    }
    return b;
}

void freeBoard(Board *b) {
    if (!b) return;
    free(b->mineBoard);
    free(b->state);
    free(b);
}

int inBounds(const Board *b, int r, int c) {
    return r >= 0 && r < b->rows && c >= 0 && c < b->cols;
}

void showHelpAndLegend() {
    printf(COLOR_GREEN "Legend:\n" COLOR_RESET);
    printf("%s*%s = Mine (only visible when revealed or game over)\n", COLOR_RED, COLOR_RESET);
    printf("%sF%s = Flag\n", COLOR_CYAN, COLOR_RESET);
    printf(" .  = Revealed empty (0 adjacent mines)\n");
    printf(COLOR_YELLOW "1-8" COLOR_RESET " = number of adjacent mines\n\n");
}

// Main interactive play loop
void playMinesweeper() {
    clearScreen();
    printf("Choose difficulty:\n");
    printf(" 1) Easy   (9x9, 10 mines)\n");
    printf(" 2) Medium (16x16, 40 mines)\n");
    printf(" 3) Hard   (16x30, 99 mines)\n");
    printf("Enter choice (1-3): ");
    int choice = 1;
    if (scanf("%d", &choice) != 1) return;
    int rows, cols, mines;
    if (choice == 1) { rows = 9; cols = 9; mines = 10; }
    else if (choice == 2) { rows = 16; cols = 16; mines = 40; }
    else { rows = 16; cols = 30; mines = 99; }

    Board *b = createBoard(rows, cols, mines);

    // We'll postpone mine placement until first open so first move is safe
    int firstMove = 1;
    int gameOver = 0;
    int win = 0;
    int totalSafe = rows * cols - mines;

    clearScreen();
    printInstructions();
    showHelpAndLegend();

    // main loop
    while (!gameOver) {
        printBoard(b, 0);
        printf("\nRevealed: %d / %d safe cells\n", b->revealedCount, totalSafe);
        printf("Enter action (o = open, f = flag) and row col: ");
        char action;
        int r, c;
        if (scanf(" %c %d %d", &action, &r, &c) != 3) {
            // invalid input flush
            printf("Invalid input. Example: o 2 3\n");
            while (getchar() != '\n');
            continue;
        }
        if (!inBounds(b, r, c)) {
            printf(COLOR_YELLOW "Coordinates out of bounds. Try again.\n" COLOR_RESET);
            continue;
        }
        int id = idx(b, r, c);
        if (action == 'o' || action == 'O') {
            if (b->state[id] == REVEALED) {
                printf("Cell already revealed.\n");
                continue;
            }
            if (b->state[id] == FLAGGED) {
                printf("Cell is flagged. Unflag it before opening.\n");
                continue;
            }
            if (firstMove) {
                // safe first move: place mines avoiding (r,c) neighborhood
                placeMines(b, r, c);
                computeAdjacency(b);
                firstMove = 0;
            }
            if (b->mineBoard[id] == 'M') {
                // hit mine -> game over
                clearScreen();
                printf(COLOR_RED "BOOM! You hit a mine at (%d,%d). Game Over.\n" COLOR_RESET, r, c);
                printBoard(b, 1); // reveal all
                gameOver = 1;
                win = 0;
                break;
            } else {
                // reveal (and flood if zero)
                if (b->state[id] != REVEALED) {
                    revealDFS(b, r, c);
                }
                if (b->revealedCount >= totalSafe) {
                    clearScreen();
                    printf(COLOR_GREEN "CONGRATULATIONS! You cleared all safe cells!\n" COLOR_RESET);
                    printBoard(b, 1);
                    gameOver = 1;
                    win = 1;
                    break;
                }
            }
        } else if (action == 'f' || action == 'F') {
            if (b->state[id] == REVEALED) {
                printf("Cannot flag a revealed cell.\n");
                continue;
            }
            if (b->state[id] == FLAGGED) {
                b->state[id] = HIDDEN;
                printf("Flag removed at (%d,%d).\n", r, c);
            } else {
                b->state[id] = FLAGGED;
                printf("Flag placed at (%d,%d).\n", r, c);
            }
        } else {
            printf("Unknown action '%c'. Use 'o' to open or 'f' to flag.\n", action);
            continue;
        }
    }

    // ask replay
    char reply = 'n';
    printf("\nWould you like to play again? (y/n): ");
    scanf(" %c", &reply);
    freeBoard(b);
    if (reply == 'y' || reply == 'Y') {
        playMinesweeper(); // restart
    } else {
        printf("\nThanks for playing Minesweeper. Goodbye!\n");
    }
}

int main() {
    srand((unsigned int)time(NULL));
    playMinesweeper();
    return 0;
}
