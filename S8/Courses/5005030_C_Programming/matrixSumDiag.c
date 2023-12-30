#include <stdio.h>
#include <stdlib.h>

/*
 *   This program defines a 5x5 matrix, prints its elements, and calculates the sum of the diagonal elements.
 *   @return int
 */
int main() {
    int n = 5; // Size of the square matrix.

    int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int i, j, sum = 0;

    // Print the elements of the matrix with appropriate formatting.
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i][j] < 10) {
                printf("%d  ", arr[i][j]);
            } else {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }

    // Calculate the sum of the diagonal elements of the matrix.
    for (i = 0; i < 5; i++) {
        sum += arr[i][i];
    }

    printf("sum = %d", sum); // Print the sum of the diagonal elements.

    return 0;
}
