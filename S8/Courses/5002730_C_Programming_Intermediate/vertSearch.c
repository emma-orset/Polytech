#include <stdio.h>
#define N 9

int a[N][N] = {
    {0, 1, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 1, 0}
};

int flag[N] = {0};

/*
 *    Depth-first search function to explore and print vertices in the graph.
 *
 *    @param i Vertex to start the search from.
 */
void VertSearch(int i) {
    int j;
    flag[i] = 1;
    printf("%d\n", i); // Print the current vertex.
    for (j = 0; j < N; j++) {
        if (a[i][j] == 1 && flag[j] == 0) {
            VertSearch(j); // Recursively search adjacent vertices.
        }
    }
}

int main(void) {
    printf("%d\n", 0); // Print the starting vertex.
    VertSearch(0); // Start depth-first search from vertex 0.
    return 0;
}
