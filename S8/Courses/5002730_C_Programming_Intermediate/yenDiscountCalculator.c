#include <stdio.h>
#include <stdlib.h>

/**
 * Calculate and display discounted prices in Yen based on user input.
 * @return int
 */
int main()
{
    int price;      // Variable to store the original price
    int discount;   // Variable to track the discount percentage

    // Prompt the user to enter the original price
    printf("Enter price : ");
    scanf("%d", &price);

    // Loop through discount percentages from 1% to 9%
    for (discount = 1; discount < 10; discount++)
    {
        // Calculate the discounted price in Yen using integer arithmetic
        int discountedPrice = price - (int)(price * discount * 0.1);

        // Display the discounted price in Yen with the corresponding discount percentage
        printf("%d0 = %d Yen\n", discount, discountedPrice);
    }

    return 0;
}
