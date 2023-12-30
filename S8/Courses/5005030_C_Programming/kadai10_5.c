#include <stdio.h>

char *delChar(char *str, char c) {
    char *dest = str;
    char *src = str;

    while (*src) {
        if (*src != c) {
            *dest = *src;
            dest++;
        }

        src++;
    }

    *dest = '\0';

    return str;
}

int main(void) {
    char str[100], c;

    printf("c: ");
    scanf("%c", &c);

    printf("str: ");
    scanf("%s", str);

    char *result = delChar(str, c);

    printf("new str: %s\n", result);

    return 0;
}
