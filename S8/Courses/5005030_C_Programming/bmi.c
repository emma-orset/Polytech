#include <stdio.h>
#include <stdlib.h>

/*
 *   This program calculates the BMI (Body Mass Index) based on user input for size (in cm) and weight (in kg).
 *   It also categorizes the BMI result into different weight status.
 *   @return int
 */
int main() {
    double size; // Stores the user's size in centimeters.
    double weight; // Stores the user's weight in kilograms.

    printf("Input your size (cm): ");
    scanf("%lf", &size);

    printf("\nInput your weight (kg): ");
    scanf("%lf", &weight);

    size = size / 100.0; // Convert size to meters for BMI calculation.

    double bmi = (weight / (size * size)); // Calculate the BMI.

    printf("\nYour BMI is %.1f, you are: ", bmi);

    if (bmi < 18.5) {
        printf("Underweight");
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("Healthy Weight");
    } else if (bmi >= 25 && bmi <= 29.9) {
        printf("Obesity 1");
    } else if (bmi >= 30 && bmi <= 34.5) {
        printf("Obesity 2");
    } else if (bmi >= 35 && bmi <= 39.5) {
        printf("Obesity 3");
    } else {
        printf("Obesity 4");
    }

    return 0;
}
