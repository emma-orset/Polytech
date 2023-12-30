#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

/*
 * Generates a random table with values in the range [0, 9].
 * @param table The 2D array to be filled with random values.
 */
void generateRandomTable(int table[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            table[i][j] = rand() % 10; // Generates random values between 0 and 9.
        }
    }
}

/*
 * Prints the 2D table in a tabular format.
 * @param table The 2D array to be printed.
 */
void printTable(int table[ROW][COL]) {
    int i, j;
    printf(" | 1| 2| 3| 4| 5| 6| 7| 8| 9|\n");
    printf("-+--+--+--+--+--+--+--+--+--+\n");
    for (i = 0; i < ROW; i++) {
        printf("%d|", i + 1);
        for (j = 0; j < COL; j++) {
            printf("%2d|", table[i][j]); // Prints each value with leading spaces.
        }
        printf("\n");
    }
}

/*
 * Generates a PIN code based on user input and the generated table.
 * @param table The 2D array used to generate the PIN code.
 */
void getPIN(int table[ROW][COL]) {
    int row, col, direction, i, j;
    printf("Row? :");
    scanf("%d", &row);
    printf("Column? :");
    scanf("%d", &col);
    printf("Direction [1:right, 2:down]:");
    scanf("%d", &direction);
    if (direction == 1) {
        if (col + 3 >= COL) {
            printf("PIN cannot be generated\n");
            return;
        }
        printf("PIN is ");
        for (i = row - 1; i < row; i++) {
            for (j = col - 1; j < col + 3; j++) {
                printf("%d", table[i][j]);
            }
        }
    } else if (direction == 2) {
        if (row + 3 >= ROW) {
            printf("PIN cannot be generated\n");
            return;
        }
        printf("PIN is ");
        for (i = row - 1; i < row + 3; i++) {
            for (j = col - 1; j < col; j++) {
                printf("%d", table[i][j]);
            }
        }
    } else {
        printf("Please specify the correct orientation\n");
    }
}

int main() {
    int table[ROW][COL];
    srand((unsigned int)time(NULL));
    generateRandomTable(table);
    printTable(table);
    getPIN(table);

    return 0;
}
