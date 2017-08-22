#include<stdio.h>
#include <stdlib.h>

#define N 9
#define M 7
int parent[N * M];
int path[N][M];


void printPath(int mv[N][M], int o) {

    if (o == -1) {
        return;
    }
    int s = o / M;
    int f = o % M;
    path[s][f] = 1;

    printPath(mv, parent[o]);

    printf("-->%d ", o);


}

void Maze(int maze[N][M], int q, int r) {
    int u = (q * M) + r;
    printf("%d,%d=%d  ", q, r, u);

    parent[0] = -1;
    int mm[(N * M) + M];

    if (u == (N * M) - 1) {
        path[N - 1][M - 1] = 1;
        printf("\nFound Solution!!!!!\n");
        printPath(maze, parent[u]);
        printf("-->%d\n", (N * M) - 1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("%d  ", path[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    mm[u + 1] = maze[q][r + 1];
    mm[u + M] = maze[q + 1][r];

    if (mm[u + 1] == 1 && u % M != (M - 1)) {
        parent[u + 1] = u;
        Maze(maze, q, r + 1);
    } else if (mm[u + M] == 1 && u + M <= (N * M) - 1) {
        parent[u + M] = u;
        Maze(maze, q + 1, r);
    } else {
        maze[q][r] = 0;
        if (maze[0][0] == 0) {
            printf("\nNo Solution!!!!");
            exit(0);
        }
        u = parent[u];
        q = u / M;
        r = u % M;
        Maze(maze, q, r);

    }


}

void main() {

    /*int maze[N][M] = {
            {1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 0},
            {0, 1, 1, 0, 1, 0, 1},
            {1, 1, 1, 1, 0, 1, 0},
            {0, 1, 0, 1, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 0},
            {0, 0, 1, 0, 1, 1, 1},
            {0, 0, 1, 1, 1, 1, 1}
    };*/
    int maze[N][M] = {
            {1, 1, 1, 1, 1, 1, 1},
            {1, 1, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1},
            {1, 1, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1}
    };
    Maze(maze, 0, 0);


}