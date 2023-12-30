#include <stdio.h>
#include <stdlib.h>

void extract_consonant(char *string){
    char newString[50];
    int n=0;

    for (int i = 0; i<strlen(string); i++){

            if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'y'){
                continue;
            }
            else {
                newString[n] = string[i];
                n++;
            }
    }

    printf("\nThe word without consonant is %s.\n", newString);

}

int main(void){
    char string[50];

    printf("Enter a word: ");
    scanf("%s", &string);

    extract_consonant(string);

    return 0;
}
