#include <stdio.h>
#include <stdlib.h>

/**
 * Calculate and display the result of various arithmetic operations between two integers.
 * @param a The first integer.
 * @param b The second integer.
 * @return void
 */
void calculs(int a, int b)
{
    // Addition
    printf("a+b=%d\n", a + b);

    // Subtraction
    printf("a-b=%d\n", a - b);

    // Multiplication
    printf("a*b=%d\n", a * b);

    // Division with float cast for correct result
    printf("a/b=%f\n", (float)a / b);
}

/**
 * Main function.
 * @return int
 */
int main()
{
    int a = 3;
    int b = 5;
    printf("a=%d\nb=%d\n\n", a, b);
    calculs(a, b);
    return 0;
}
