#include <stdio.h>
#include <stdlib.h>

/**
 * Prompt the user for their name and greet them in a polite manner.
 * @return int
 */
int main() {
    char name[100]; // Variable to store the user's name

    // Prompt the user to enter their name
    printf("Your name? : ");
    scanf("%s", name);

    // Display a polite greeting using the entered name
    printf("%s-san, Hello!\n", name);

    return 0;
}
