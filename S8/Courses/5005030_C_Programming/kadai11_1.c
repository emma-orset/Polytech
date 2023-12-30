#include <stdio.h>

int isSameChars(const char* s, char c) {
    while (*s != '\0') {
        if (*s != c) {
            return 0;
        }
        s++;
    }
    return 1;
}

int main() {
    char c;
    char s[100];

    printf("Character: ");
    scanf("%c", &c);
    printf("String: ");
    scanf("%s", s);

    if (isSameChars(s, c)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
