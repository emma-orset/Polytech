#include <stdio.h>
#include <stdlib.h>

/*
 *   This program calculates the profit percentage based on the base price and the selling price.
 *   @return int
 */
int main() {
    double first_price;
    double your_price;
    double profit;

    printf("What is the base price of this item?\n");
    scanf("%lf", &first_price);

    printf("\n\nHow much do you want to sell this item for?\n");
    scanf("%lf", &your_price);

    profit = ((your_price - first_price) / (double)your_price) * 100; // Calculate the profit percentage.

    printf("\n\nHere are the benefits you get: %.1f percent", profit);

    return 0;
}
