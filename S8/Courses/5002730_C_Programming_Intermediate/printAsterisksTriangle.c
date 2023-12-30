#include <stdio.h>

/**
 * Generate and print a triangle pattern using asterisks.
 * @return int
 */
int main() {
    int i, j, n; // Variables for loops and user input

    // Prompt the user to enter the number of rows for the triangle
    printf("n=");
    scanf("%d", &n);

    // Loop to print each row of the triangle
    for (i = 0; i < n; i++) {
        // Inner loop to print asterisks in each row
        for (j = 0; j < i + 1; j++) {
            printf("*");
        }
        printf("\n"); // Move to the next line for the next row
    }

    return 0; // Return 0 to indicate successful execution
}
