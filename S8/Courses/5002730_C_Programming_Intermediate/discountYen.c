#include <stdio.h>

/**
 * This program calculates discounts based on the input price in yen and
 * displays the discounted price to the user.
 */
int main(void) {
    // Declare and initialize a variable to store the price in yen
    int price;

    // Prompt the user to input the price in yen
    printf("What's the price(yen)?\n");

    // Read and store the input price in the 'price' variable
    scanf("%d", &price);

    // Check if the price is greater than or equal to 10,000 yen
    if (price >= 10000) {
        // Apply a 20% discount to the price
        price = price - price * 0.20;

        // Display a message with the discounted price
        printf("\nYou have a 20 percent discount, the new price is %d yen.\n", price);
    }
    // If not, check if the price is greater than or equal to 5,000 yen
    else if (price >= 5000) {
        // Apply a 10% discount to the price
        price = price - price * 0.10;

        // Display a message with the discounted price
        printf("\nYou have a 10 percent discount, the new price is %d yen.\n", price);
    }
    // If not, check if the price is greater than or equal to 1,000 yen
    else if (price >= 1000) {
        // Apply a 5% discount to the price
        price = price - price * 0.05;

        // Display a message with the discounted price
        printf("\nYou have a 5 percent discount, the new price is %d yen.\n", price);
    }
    // If none of the previous conditions are met, the price is less than 1,000 yen
    else {
        // Display a message indicating no discount is applicable
        printf("\nYou can't have any discount because it's under 1,000 yen. The price is %d yen.\n", price);
    }

    // Exit the program with a status code of 0 to indicate success
    return 0;
}
