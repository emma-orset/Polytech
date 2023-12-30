#include <stdio.h>

/**
 * Draw a pattern of asterisks based on user input.
 *
 * This program prompts the user to enter a value 'n' and then
 * prints a pattern of asterisks in the shape of a right-angled
 * triangle with 'n' rows.
 *
 * @return int
 */
int main() {
    int i, j, n;

    // Prompt the user for input
    printf("Enter the value of n: ");
    scanf("%d", &n);

    i = 0;
    while (i < n) {
        j = 0;
        while (j < i + 1) {
            // Print an asterisk for each value of j
            printf("*");
            j++;
        }
        // Move to the next line after each row of asterisks
        printf("\n");
        i++;
    }

    return 0;
}
