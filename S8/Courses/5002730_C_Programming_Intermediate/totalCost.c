#include <stdio.h>

/*
 *    This program calculates the total cost based on the price per item and
 *    the quantity purchased. It offers discounts for buying multiple items.
 *
 *    @return int
 */
int main(void) {
    int money, num; // Variables to store the price per item and the quantity purchased.

    printf("How much money?\n"); // Prompt the user for the price per item.
    scanf("%d", &money); // Read and store the price per item.

    printf("Quantity?\n"); // Prompt the user for the quantity purchased.
    scanf("%d", &num); // Read and store the quantity.

    if (num == 2) {
        printf("Discount 40 percent. Total is: %d yen\n", num * money * 6 / 10); // Apply a 40% discount for buying 2 items.
    } else if (num >= 3) {
        printf("Discount 50 percent. Total is: %d yen\n", num * money / 2); // Apply a 50% discount for buying 3 or more items.
    } else {
        printf("No discount. Total is: %d yen\n", num * money); // No discount for buying less than 2 items.
    }

    return 0;
}
