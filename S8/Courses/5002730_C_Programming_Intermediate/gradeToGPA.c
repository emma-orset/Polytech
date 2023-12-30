#include <stdio.h>

/*
 * Description: This program takes a numeric grade as input and converts it to a GPA based on predefined grade ranges.
 */
int main(void) {

    int num;

    // Prompt the user to enter a grade between 0 and 100.
    printf("Enter your grade (0 to 100):\n");
    scanf("%d", &num);

    // Check if the entered grade is greater than 100.
    if (num > 100) {
        printf("Please enter a grade between 0 and 100.\n");
    }

    // Check if the grade is greater than or equal to 90.
    else if (num >= 90) {
        printf("Your GPA is 4.\n");
    }

    // Check if the grade is greater than or equal to 80.
    else if (num >= 80) {
        printf("Your GPA is 3.\n");
    }

    // Check if the grade is greater than or equal to 70.
    else if (num >= 70) {
        printf("Your GPA is 2.\n");
    }

    // Check if the grade is greater than or equal to 60.
    else if (num >= 60) {
        printf("Your GPA is 1.\n");
    }

    // If none of the above conditions are met, the grade is below 60.
    else {
        printf("Your GPA is 0.\n");
    }

    return 0;
}
