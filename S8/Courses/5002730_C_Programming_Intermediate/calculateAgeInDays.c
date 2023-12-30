#include <stdio.h>

/*
 * Description: This program calculates and prints the approximate number of days a person has lived based on their age in years.
 */
int main(void) {

    int age;
    // Prompt the user to enter their age.
    printf("What's your age?\n");
    scanf("%d", &age);

    // Calculate and print the approximate number of days lived.
    printf("\nSo you have at least %d days.\n", age * 365);

    return 0;
}
