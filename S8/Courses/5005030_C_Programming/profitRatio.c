#include <stdio.h>
#include <stdlib.h>

/*
 *   This program calculates the profit ratio for an item based on its cost and selling price.
 *   @param cost The cost of the item.
 *   @param price The selling price of the item.
 *   @return The calculated profit ratio as a percentage.
 */
double profitRatio(int cost, int price) {
    return ((price - cost) / (double)price) * 100;
}

int main() {
    int cost; // Stores the cost of the item.
    int price; // Stores the selling price of the item.
    double profit; // Stores the calculated profit ratio.

    printf("What is the base price of this item?\n");
    scanf("%d", &cost);

    printf("\nHow much do you want to sell this item for?\n");
    scanf("%d", &price);

    profit = profitRatio(cost, price); // Calculate the profit ratio using the provided function.

    printf("\nHere is the profit ratio: %.1f percent\n\n", profit);

    return 0;
}
