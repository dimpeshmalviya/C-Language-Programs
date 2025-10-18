/* tictactoe.c
   Simple CLI Tic-Tac-Toe for two players
   Compile: gcc -o tictactoe tic_tac_toe.c
   Run: ./tictactoe
*/

#include <stdio.h>
#include <stdlib.h>

void print_board(char b[3][3]) {
    puts("\nCurrent board:");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char c = b[i][j];
            if (c == ' ') {
                // show cell index to help players choose
                printf(" %d ", i*3 + j + 1);
            } else {
                printf(" %c ", c);
            }
            if (j < 2) printf("|");
        }
        putchar('\n');
        if (i < 2) printf("---+---+---\n");
    }
    putchar('\n');
}

int check_winner(char b[3][3]) {
    // returns 1 if X wins, -1 if O wins, 0 otherwise
    for (int i = 0; i < 3; ++i) {
        // rows
        if (b[i][0] != ' ' && b[i][0] == b[i][1] && b[i][1] == b[i][2])
            return (b[i][0] == 'X') ? 1 : -1;
        // cols
        if (b[0][i] != ' ' && b[0][i] == b[1][i] && b[1][i] == b[2][i])
            return (b[0][i] == 'X') ? 1 : -1;
    }
    // diagonals
    if (b[0][0] != ' ' && b[0][0] == b[1][1] && b[1][1] == b[2][2])
        return (b[0][0] == 'X') ? 1 : -1;
    if (b[0][2] != ' ' && b[0][2] == b[1][1] && b[1][1] == b[2][0])
        return (b[0][2] == 'X') ? 1 : -1;
    return 0;
}

int moves_left(char b[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (b[i][j] == ' ') return 1;
    return 0;
}

void clear_stdin(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { }
}

int main(void) {
    char board[3][3];
    char play_again = 'n';

    do {
        // initialize board
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = ' ';

        char player = 'X';
        int winner = 0;

        printf("Tic-Tac-Toe (CLI)\n");
        printf("Players: X and O\n");
        printf("Enter cell numbers 1-9 as shown on board to place your mark.\n");

        while (!winner && moves_left(board)) {
            print_board(board);
            int choice = 0;
            int ok = 0;

            while (!ok) {
                printf("Player %c, enter your move (1-9): ", player);
                if (scanf("%d", &choice) != 1) {
                    printf("Invalid input. Please enter a number 1-9.\n");
                    clear_stdin();
                    continue;
                }
                clear_stdin(); // remove trailing newline/extra chars

                if (choice < 1 || choice > 9) {
                    printf("Choose a number between 1 and 9.\n");
                    continue;
                }
                int r = (choice - 1) / 3;
                int c = (choice - 1) % 3;
                if (board[r][c] != ' ') {
                    printf("Cell already taken. Choose another.\n");
                    continue;
                }
                board[r][c] = player;
                ok = 1;
            }

            winner = check_winner(board);
            if (winner != 0) break;
            if (!moves_left(board)) break;
            player = (player == 'X') ? 'O' : 'X';
        }

        print_board(board);
        if (winner == 1) {
            puts("Player X wins! 🎉");
        } else if (winner == -1) {
            puts("Player O wins! 🎉");
        } else {
            puts("It's a draw! 🤝");
        }

        printf("Play again? (y/n): ");
        if (scanf(" %c", &play_again) != 1) {
            play_again = 'n';
        }
        clear_stdin();
    } while (play_again == 'y' || play_again == 'Y');

    puts("Thanks for playing! Goodbye.");
    return 0;
}
