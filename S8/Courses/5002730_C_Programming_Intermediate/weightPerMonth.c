#include <stdio.h>

/**
 * This program allows the user to input a month (1-12) and displays the corresponding
 * weight recorded in the year 2022. It uses an array to store the weight data for each month.
 */
int main(void) {
    // Declare an array 'w' to store weights for each month in 2022
    int w[12] = {60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49};

    int month;

    // Prompt the user to input a month
    printf("Month:");

    // Read and store the input month in the 'month' variable
    scanf("%d", &month);

    // Check if the input month is within a valid range (1 to 12)
    if ((month >= 1) && (month <= 12)) {
        // Display the weight for the specified month in 2022
        printf("\nYour weight in month %d in 2022 was %dkg\n", month, w[month - 1]);
    }

    // Exit the program with a status code of 0 to indicate success
    return 0;
}
