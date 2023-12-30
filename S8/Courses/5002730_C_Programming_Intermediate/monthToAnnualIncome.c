#include <stdio.h>

/*
 *    This program calculates the annual income based on the user's
 *    monthly income and displays the result.
 *
 *    @return int
 */
int main(void) {
    int n; // Variable to store the monthly income.

    printf("What is your monthly income? "); // Prompt the user for input.
    scanf("%d", &n); // Read the user's monthly income and store it in the 'n' variable.

    printf("So your annual income is %d.", n * 12); // Calculate and display the annual income.

    return 0;
}
