#include <stdio.h>

/*
 *    This program prints a multiplication table from 1 to 9.
 *
 *    @return int
 */
int main(void) {
    int i, j;

    printf("     1  2  3  4  5  6  7  8  9\n\n");

    for (i = 1; i <= 9; i++) {
        printf("%3d", i); // Print the row number.

        for (j = 1; j <= 9; j++) {
            printf("%3d", i * j); // Print the product of i and j, aligned in columns.
        }

        printf("\n"); // Move to the next line for the next row.
    }

    return 0;
}
