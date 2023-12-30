#include <stdio.h>

/*
 *    This program calculates the discounted price of a product based on the
 *    total amount entered by the user. If the amount is over 5,000 yen, a 20%
 *    discount is applied.
 *
 *    @return int
 */
int main(void) {
    int money; // Variable to store the total amount.

    printf("What is the total amount? "); // Prompt the user for input.
    scanf("%d", &money); // Save the user-entered amount in the 'money' variable.

    // If the amount is over 5,000 yen, apply a 20% discount.
    if (money >= 5000) {
        printf("It is 20 percent cheaper and costs %d yen.\n", money * 8 / 10);
    }
    // If the amount is under 5,000 yen, inform the user about the discount.
    else {
        printf("The amount is %d. If the price is over ¥5,000, the price will be 20 percent cheaper, but is this still acceptable?\n", money);
    }

    return 0;
}
