#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 9
#define DIGIT 4

/*
 * Generates a random grid of integers and allows the user to create a PIN by selecting
 * a starting cell and direction.
 * @return int
 */
int main(void) {
    int i, j, k, r, c, dir, row, col, tmp, num;
    int grid[N][N];
    char input[N];

    // Seed the random number generator with the current time.
    srand((unsigned int)time(NULL));

    // Populate the grid with random numbers between 0 and 9.
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            grid[i][j] = rand() % 10;
        }
    }

    // Display the grid with row and column numbers.
    printf(" |");
    for (i = 1; i <= N; i++) {
        printf("%2d|", i);
    }
    putchar('\n');
    printf("-+");
    for (i = 0; i < N; i++) {
        printf("--+");
    }
    putchar('\n');
    for (i = 0; i < N; i++) {
        printf("%d|", i + 1);
        for (j = 0; j < N; j++) {
            printf("%2d|", grid[i][j]);
        }
        putchar('\n');
    }

    // Prompt the user to enter the starting row, column, and direction.
    printf("Row? : ");
    fgets(input, N, stdin);
    row = atoi(input);
    printf("Column? : ");
    fgets(input, N, stdin);
    col = atoi(input);
    printf("Direction [1: up, 2: down, 3: left, 4: right]: ");
    fgets(input, N, stdin);
    dir = atoi(input);

    num = 0;
    for (i = 0; i < DIGIT; i++) {
        // Calculate the PIN by moving in the specified direction and concatenating digits.
        if (row >= 1 && row <= N && col >= 1 && col <= N) {
            num += grid[row - 1][col - 1] * (int)pow(10, DIGIT - i - 1);
        }
        if (dir == 1) {
            row--;
        } else if (dir == 2) {
            row++;
        } else if (dir == 3) {
            col--;
        } else if (dir == 4) {
            col++;
        }
        // Wrap around the grid if necessary.
        if (row < 1) {
            row = N;
        } else if (row > N) {
            row = 1;
        }
        if (col < 1) {
            col = N;
        } else if (col > N) {
            col = 1;
        }
    }

    // Display the generated PIN.
    printf("PIN is %04d\n", num);

    return 0;
}
