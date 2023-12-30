#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){

    char character[1];
    char string[40];
    bool isIn = false;

    printf("\nEnter a character: ");
    scanf("%c", &character);

    printf("\nEnter a word: ");
    scanf("%s", &string);

    for (int i = 0; i<strlen(string); i++){

        if (tolower(string[i]) == tolower(character[0])){
            isIn = true;
        }
    }

    if (isIn){
        printf("\n%c is in %s.\n", character[0], string);
    }
    else {
        printf("\n%c isn't in %s.\n", character[0], string);
    }

    return 0;
}
