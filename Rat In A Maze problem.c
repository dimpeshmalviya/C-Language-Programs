#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10       
#define MAXPATHS 1000 
#define MAXLEN 100    

int n;
int ansCount = 0;
char ans[MAXPATHS][MAXLEN];

void pushing(int x, int y, int maze[MAXN][MAXN], char temp[MAXLEN], int vis[MAXN][MAXN]);

void pushing(int x, int y, int maze[MAXN][MAXN], char temp[MAXLEN], int vis[MAXN][MAXN]) {
    if (x == n - 1 && y == n - 1) {
        strcpy(ans[ansCount++], temp);
        return;
    }

    // Move Right
    if (y + 1 < n && maze[x][y + 1] && !vis[x][y + 1]) {
        vis[x][y + 1] = 1;
        int len = strlen(temp);
        temp[len] = 'R'; temp[len + 1] = '\0';
        pushing(x, y + 1, maze, temp, vis);
        temp[len] = '\0';
        vis[x][y + 1] = 0;
    }

    // Move Left
    if (y - 1 >= 0 && maze[x][y - 1] && !vis[x][y - 1]) {
        vis[x][y - 1] = 1;
        int len = strlen(temp);
        temp[len] = 'L'; temp[len + 1] = '\0';
        pushing(x, y - 1, maze, temp, vis);
        temp[len] = '\0';
        vis[x][y - 1] = 0;
    }

    // Move Down
    if (x + 1 < n && maze[x + 1][y] && !vis[x + 1][y]) {
        vis[x + 1][y] = 1;
        int len = strlen(temp);
        temp[len] = 'D'; temp[len + 1] = '\0';
        pushing(x + 1, y, maze, temp, vis);
        temp[len] = '\0';
        vis[x + 1][y] = 0;
    }

    // Move Up
    if (x - 1 >= 0 && maze[x - 1][y] && !vis[x - 1][y]) {
        vis[x - 1][y] = 1;
        int len = strlen(temp);
        temp[len] = 'U'; temp[len + 1] = '\0';
        pushing(x - 1, y, maze, temp, vis);
        temp[len] = '\0';
        vis[x - 1][y] = 0;
    }
}

void ratInMaze(int maze[MAXN][MAXN]) {
    int vis[MAXN][MAXN] = {0};
    char temp[MAXLEN] = "";
    ansCount = 0;
    vis[0][0] = 1;

    pushing(0, 0, maze, temp, vis);

    if (ansCount == 0) {
        printf("No paths found.\n");
        return;
    }

    for (int i = 0; i < ansCount - 1; i++) {
        for (int j = i + 1; j < ansCount; j++) {
            if (strcmp(ans[i], ans[j]) > 0) {
                char tempStr[MAXLEN];
                strcpy(tempStr, ans[i]);
                strcpy(ans[i], ans[j]);
                strcpy(ans[j], tempStr);
            }
        }
    }

    printf("Possible paths:\n");
    for (int i = 0; i < ansCount; i++) {
        printf("%s\n", ans[i]);
    }
}

int main() {
    printf("Enter size of maze (n): ");
    scanf("%d", &n);

    int maze[MAXN][MAXN];
    printf("Enter the maze (%dx%d matrix of 0s and 1s):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    if (maze[0][0] == 0) {
        printf("No path possible: starting cell is blocked.\n");
        return 0;
    }

    ratInMaze(maze);
    return 0;
}
