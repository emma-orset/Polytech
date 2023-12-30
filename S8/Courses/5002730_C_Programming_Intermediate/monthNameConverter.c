#include <stdio.h>

/**
 * Lookup and display the name of a month based on its number.
 * @return int
 */
int main() {
    char name[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; // Array to store month names
    int month; // Variable to store the month number

    // Prompt the user to input a month number
    printf("Month: ");
    scanf("%d", &month);

    // Check if the input is a valid month number (between 1 and 12)
    if ((month >= 1) && (month <= 12)) {
        // Display the corresponding month name
        printf("Month number %d is %s.\n", month, name[month - 1]);
    }

    return 0; // Return 0 to indicate successful execution
}
