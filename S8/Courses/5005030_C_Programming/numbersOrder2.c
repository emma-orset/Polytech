#include <stdio.h>

/*
 *    Check the order of three integers.
 *    @param n1 The first integer.
 *    @param n2 The second integer.
 *    @param n3 The third integer.
 *    @return 1 if n1 <= n2 <= n3, -1 if n1 >= n2 >= n3, 0 otherwise.
 */
int ckOrder(int n1, int n2, int n3) {
    int res;
    if (n1 <= n2 && n2 <= n3) {
        res = 1;  // The numbers are in ascending order.
    } else if (n1 >= n2 && n2 >= n3) {
        res = -1; // The numbers are in descending order.
    } else {
        res = 0;  // The numbers are not in any specific order.
    }
    return res;
}

/*
 *    Main function to check the order of three integers and display the result.
 *    @return 0 indicating successful execution.
 */
int main() {
    int n1, n2, n3;

    printf("\nn1 : ");
    scanf("%d", &n1);

    printf("\nn2 : ");
    scanf("%d", &n2);

    printf("\nn3 : ");
    scanf("%d", &n3);

    int res = ckOrder(n1, n2, n3);

    if (res == 0) {
        printf("\n%d", res);    // Numbers are not in a specific order.
    } else {
        printf("\n%+d", res);   // Display the order result with a sign (+1 or -1).
    }

    return 0;
}
