#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>  // Include the string.h header for strlen function

/*
 *    This program takes a character and a string as input and checks if the character is present in the string.
 *   @param character A single character input from the user.
 *   @param string A string input from the user.
 *   @return int
 */
int main(void) {

    char character[1];
    char string[40];
    bool isIn = false;

    printf("\nEnter a character: ");
    scanf("%c", &character[0]); // Use &character[0] to read a single character.

    printf("\nEnter a word: ");
    scanf("%s", string); // No need for &string since it's an array.

    for (int i = 0; i < strlen(string); i++) {
        if (tolower(string[i]) == tolower(character[0])) {
            isIn = true;  // Set isIn to true if the character is found in the string.
        }
    }

    if (isIn) {
        printf("\n%c is in %s.\n", character[0], string);
    } else {
        printf("\n%c isn't in %s.\n", character[0], string);
    }

    return 0;
}
