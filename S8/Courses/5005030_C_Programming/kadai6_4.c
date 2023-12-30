#include <stdio.h>
#include <stdlib.h>

int main() {
    int numStrings;
    printf("Number of strings: ");
    scanf("%d", &numStrings);

    char strings[numStrings][100]; // Assuming maximum string length of 100 characters

    for (int i = 0; i < numStrings; i++) {
        printf("str[%d]: ", i);
        scanf("%s", strings[i]);
    }

    int maxLength = 0;

    for (int i = 0; i < numStrings; i++) {
        int length = 0;
        while (strings[i][length] != '\0') {
            length++;
        }
        if (length > maxLength) {
            maxLength = length;
        }
    }

    printf("Longest string(s):\n");
    for (int i = 0; i < numStrings; i++) {
        int length = 0;
        while (strings[i][length] != '\0') {
            length++;
        }
        if (length == maxLength) {
            printf("%s (%d)\n", strings[i], length);
        }
    }

    return 0;
}

