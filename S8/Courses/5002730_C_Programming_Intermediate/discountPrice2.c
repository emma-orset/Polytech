#include <stdio.h>

/*
 *    This program calculates the discounted price of clothes based on the
 *    total amount and the number of clothes bought by the user. If the user
 *    buys 2 or more pieces, a 40% discount is applied.
 *
 *    @return int
 */
int main(void) {
    int money, piece; // Variables to store the total amount and the number of clothes bought.

    printf("How many clothes did you buy? "); // Prompt the user for the number of clothes.
    scanf("%d", &piece); // Save the user-entered number of clothes in the 'piece' variable.

    printf("What is the total amount? "); // Prompt the user for the total amount.
    scanf("%d", &money); // Save the user-entered total amount in the 'money' variable.

    // If the user buys 2 or more pieces, apply a 40% discount.
    if (piece >= 2) {
        printf("It is 40 percent cheaper and costs %d yen.\n", money * 6 / 10);
    }
    // If the user buys less than 2 pieces, inform them about the discount.
    else {
        printf("The amount is %d. If you buy one more piece, the price will be 40 percent cheaper, but is this still acceptable?\n", money);
    }

    return 0;
}
