#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PATH ' '
#define SOLUTION '.'

typedef struct
{
    int row, col;
} Cell;

int rows, cols;
char **maze;

/* Direction vectors: N, S, E, W */
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

/* Initialize maze with all walls */
void initMaze()
{
    maze = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++)
    {
        maze[i] = malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++)
            maze[i][j] = WALL;
    }
}

/* Utility: shuffle directions */
void shuffle(int *arr, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

/* DFS Maze generator */
void generateMazeDFS(int r, int c)
{
    maze[r][c] = PATH;
    int dirs[4] = {0, 1, 2, 3};
    shuffle(dirs, 4);

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[dirs[i]] * 2;
        int nc = c + dc[dirs[i]] * 2;
        if (nr > 0 && nr < rows - 1 && nc > 0 && nc < cols - 1 && maze[nr][nc] == WALL)
        {
            maze[r + dr[dirs[i]]][c + dc[dirs[i]]] = PATH; // remove wall
            generateMazeDFS(nr, nc);
        }
    }
}

/* Print maze */
void printMaze()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%c", maze[i][j]);
        printf("\n");
    }
}

/* Solver using DFS */
int solveMaze(int r, int c, int er, int ec)
{
    if (r == er && c == ec)
        return 1; // reached end
    if (maze[r][c] != PATH)
        return 0;

    maze[r][c] = SOLUTION; // mark path
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (solveMaze(nr, nc, er, ec))
            return 1;
    }
    maze[r][c] = PATH; // backtrack
    return 0;
}

int main()
{
    srand(time(NULL));
    printf("Enter maze size (rows cols, odd numbers recommended): ");
    if (scanf("%d %d", &rows, &cols) != 2)
        return 1;

    initMaze();

    // Generate maze starting from (1,1)
    generateMazeDFS(1, 1);

    // Set entrance and exit
    maze[0][1] = PATH;
    maze[rows - 1][cols - 2] = PATH;

    printf("\nGenerated Maze:\n");
    printMaze();

    if (solveMaze(0, 1, rows - 1, cols - 2))
    {
        printf("\nSolved Maze:\n");
        printMaze();
    }
    else
    {
        printf("No solution found!\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++)
        free(maze[i]);
    free(maze);

    return 0;
}
