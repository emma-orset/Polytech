#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Include the math library for sqrt function.

/*
 *   This program checks the position of a point relative to a circle.
 *   @return int
 */
int main() {
    double x1, y1, r, x2, y2; // Stores the coordinates of the circle center, circle radius, and point P.

    printf("Coordinate circle center x1: ");
    scanf("%lf", &x1);

    printf("\nCoordinate circle center y1: ");
    scanf("%lf", &y1);

    printf("\nCircle radius r: ");
    scanf("%lf", &r);

    printf("\nCoordinate point P x2: ");
    scanf("%lf", &x2);

    printf("\nCoordinate point P y2: ");
    scanf("%lf", &y2);

    // Calculate the distance between the circle center and point P using the distance formula.
    double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    if (distance < r) {
        printf("\n\nThe point P is inside the circle.");
    } else if (distance == r) {
        printf("\n\nThe point P is on the circumference of the circle.");
    } else {
        printf("\n\nThe point P is outside the circle.");
    }

    return 0;
}
