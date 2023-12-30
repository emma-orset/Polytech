#include <stdio.h>
#include <stdlib.h>

/*
 *   This program calculates the consumption tax, payment amount, and points based on the input price (HT).
 *   @return int
 */
int main() {
    int price_ht; // Stores the price of the product (HT).
    double tax = 0.1; // Stores the tax rate, which is 10%.

    printf("Price of the product (HT): ");
    scanf("%d", &price_ht);

    double price = (price_ht * tax) + price_ht; // Calculate the total price including tax.

    double points = price / 10; // Calculate the points earned, which are 10% of the total price.

    double price_tax = price_ht * tax; // Calculate the consumption tax amount.

    printf("\n\nThe consumption tax is %.f yens, the payment amount is %.f yens. I got %.f points.", price_tax, price, points);

    return 0;
}
