#include <stdio.h>

char* myStrrChr(char* s, int c) {
    char* last = NULL; // Last occurrence of c

    while (*s != '\0') {
        if (*s == c) {
            last = s;
        }
        s++;
    }

    return last;
}

int main(void) {
    int c;
    char str[] = "the quick brown fox jumps over the lazy dog.";
    char* ptr;

    printf("Input: ");
    c = getchar();

    ptr = myStrrChr(str, c);

    if (ptr) {
        printf("The last occurrence of %c is at position %ld, and the remaining string is: %s\n", c, ptr - str, ptr);
    } else {
        printf("%c does not appear in the string: %s\n", c, str);
    }

    return 0;
}
