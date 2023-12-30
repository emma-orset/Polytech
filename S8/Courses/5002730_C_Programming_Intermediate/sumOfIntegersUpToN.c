#include <stdio.h>
#include <stdlib.h>

/**
 * Calculate and display the sum of integers from 1 to 'n'.
 * @return int
 */
int main() {
    int n;    // Variable to store the upper limit 'n'
    int i;    // Loop counter variable
    int sum = 0;  // Variable to store the sum

    // Prompt the user to enter the value of 'n'
    printf("n=");
    scanf("%d", &n);

    // Calculate the sum of integers from 1 to 'n'
    for (i = 1; i <= n; i++) {
        sum += i;
    }

    // Display the calculated sum
    printf("Sum from 1 to %d = %d\n", n, sum);

    return 0;
}
