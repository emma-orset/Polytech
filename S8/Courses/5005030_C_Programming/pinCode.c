#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

/*
 * Initializes the 2D array with random numbers between 0000 and 9999.
 * @param nums The 2D array to be initialized.
 */
void initialize(int nums[][COL]) {
    srand((unsigned)time(NULL));
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            nums[i][j] = rand() % 10000; // Generates a random 4-digit number.
        }
    }
}

/*
 * Prints the 2D array in a tabular format.
 * @param nums The 2D array to be printed.
 */
void print_table(int nums[][COL]) {
    printf(" |   1|   2|   3|   4|   5|   6|   7|   8|   9|\n");
    printf("-+----+----+----+----+----+----+----+----+----+\n");
    for(int i = 0; i < ROW; i++) {
        printf("%d|", i + 1);
        for(int j = 0; j < COL; j++) {
            printf("%04d|", nums[i][j]); // Prints each number with leading zeros.
        }
        printf("\n");
    }
}

int main() {
    int nums[ROW][COL];
    initialize(nums);
    print_table(nums);

    int row, col;
    printf("Row? :");
    scanf("%d", &row);
    printf("Column? :");
    scanf("%d", &col);

    printf("Pin code: %04d\n", nums[row - 1][col - 1]); // Print the selected pin code.

    return 0;
}
