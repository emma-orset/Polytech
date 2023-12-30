#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Play a word guessing game (hangman).
 * @return int
 */
int main() {
    char word[40];              // The word to guess
    int life = 10;              // Number of remaining lives
    char letters_try[27] = "";  // Letters already guessed

    // Player 1 enters a word
    printf("Player 1\nEnter a word: ");
    scanf("%s", word);

    // Convert the word to lowercase for case-insensitive matching
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }

    system("cls");  // Clear the screen

    // Display the number of letters in the word
    printf("Here is the number of letters to find: %d\n\n", (int)strlen(word));

    char secret[strlen(word) + 1];  // Secret word with hidden letters

    // Initialize the secret word with asterisks
    for (int i = 0; i < strlen(word); i++) {
        secret[i] = '*';
    }
    secret[strlen(word)] = '\0';

    // Main game loop
    while (strchr(secret, '*') != NULL && life > 0) {
        char letter;
        bool find = false;

        // Player 2 guesses a letter
        printf("%s\n\nPlayer 2, you still have %d lives\n\nLetters already tried:\n%s\n\nTry a Letter : ", secret, life, letters_try);
        scanf(" %c", &letter);

        letter = tolower(letter);  // Convert the guessed letter to lowercase

        // Check if the letter has not been guessed before adding it
        if (strchr(letters_try, letter) == NULL) {
            strncat(letters_try, &letter, 1);
        }

        // Check if the guessed letter is in the word
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == letter) {
                secret[i] = letter;
                find = true;
            }
        }

        if (!find) {
            life--;  // Decrement the remaining lives if the letter is not in the word
        }

        system("cls");  // Clear the screen
    }

    // Display the game result
    if (life > 0) {
        printf("Congratulations! You found the word!\n\n%s\n\n\n", word);
    } else {
        printf("You ran out of lives! The word was %s\n\n\n", word);
    }

    return 0;
}
