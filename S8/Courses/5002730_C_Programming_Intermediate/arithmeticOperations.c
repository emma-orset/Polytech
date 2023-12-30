#include <stdio.h>

/*
 *    This program performs basic arithmetic operations on two numbers
 *    based on the user's choice of operator (+, -, *, /).
 *
 *    @return int
 */
int main(void) {
    int a, b, Enzanshi; // Variables to store two numbers and the operator choice.

    printf("a="); // Prompt the user to enter the first number.
    scanf("%d", &a); // Read and store the first number.

    printf("b="); // Prompt the user to enter the second number.
    scanf("%d", &b); // Read and store the second number.

    printf("Enzanshi (1=+ ; 2=- ; 3=* ; 4=/) ="); // Prompt the user to choose an operator.
    scanf("%d", &Enzanshi); // Read and store the operator choice.

    switch (Enzanshi) {
        case 1:
            printf("a+b=%d\n", a + b); // Addition
            break;

        case 2:
            printf("a-b=%d\n", a - b); // Subtraction
            break;

        case 3:
            printf("a*b=%d\n", a * b); // Multiplication
            break;

        case 4:
            if (b != 0)
                printf("a/b=%lf\n", (double)a / b); // Division, with a check for division by zero.
            else
                printf("Division by 0 is not possible.\n");
            break;

        default:
            printf("Operators are not properly numbered.\n"); // Default case for an invalid operator choice.
    }

    return 0;
}
