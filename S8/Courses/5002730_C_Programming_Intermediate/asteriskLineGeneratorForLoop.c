#include <stdio.h>
#include <stdlib.h>

/**
 * Print a row of asterisks based on the user-provided number 'a'.
 * @return int
 */
int main() {
    int a;  // Variable to store the number of asterisks to print
    int i;  // Loop counter variable

    // Prompt the user to enter a number
    printf("Enter a number\na=");
    scanf("%d", &a);

    // Loop to print 'a' number of asterisks
    for (i = 1; i <= a; i++) {
        printf("*");
    }

    printf("\n");  // Move to the next line for readability

    return 0;
}
