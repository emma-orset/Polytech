#include <stdio.h>

/**
 * Swap the values of two integers 'a' and 'b'.
 * @return int
 */
int main(void) {
    int a, b, tmp;  // Declare integer variables 'a', 'b', and 'tmp'

    // Prompt the user to input values for 'a' and 'b'
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    // Swap the values of 'a' and 'b' using a temporary variable 'tmp'
    int tempb = b;
    b = a;
    a = tempb;

    // Display the values of 'a' and 'b' after swapping
    printf("===== After =====\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0; // Return 0 to indicate successful execution
}
