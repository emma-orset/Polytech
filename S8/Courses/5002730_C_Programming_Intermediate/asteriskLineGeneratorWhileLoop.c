#include <stdio.h>
#include <stdlib.h>

/**
 * Print a row of asterisks using a while loop based on the user-provided number 'a'.
 * @return int
 */
int main() {
    int a;      // Variable to store the number of asterisks to print
    int i = 1;  // Loop counter variable

    // Prompt the user to enter a number
    printf("a=");
    scanf("%d", &a);

    // Use a while loop to print 'a' number of asterisks
    while (i <= a) {
        printf("*");
        i++;
    }

    printf("\n");  // Move to the next line for readability

    return 0;
}
