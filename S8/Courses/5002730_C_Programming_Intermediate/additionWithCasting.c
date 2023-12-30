#include <stdio.h>
#include <stdlib.h>

/**
 * Perform addition of two integers and display the result as both an integer and a double.
 * @return int
 */
int main() {
    int a, b;  // Variables to store two integers

    // Prompt the user to enter values for a and b
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);

    // Calculate and display the result of a+b as an integer
    printf("a+b=%d\n", a + b);

    // Calculate and display the result of a+b as a double
    printf("a+b=%lf\n", (double)a + (double)b);

    return 0;
}
