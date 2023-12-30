#include <stdio.h>

/*
 *    Calculate the sum of numbers from 1 to n.
 *   @param n The upper limit for the summation.
 *   @return The sum of numbers from 1 to n.
 */
int sum(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return total;
}

/*
 *    Main function to find the smallest m such that the sum of numbers from 1 to m is greater than or equal to n.
 *   @return 0 indicating successful execution.
 */
int main() {
    int n, m = 1;
    printf("n: ");
    scanf("%d", &n);

    while (sum(m) < n) {
        m++;
    }

    printf("The smallest value of m such that the sum of numbers from 1 to m is greater than or equal to %d is %d.\n", n, m);
    return 0;
}
