#include <stdio.h>

void myPrintf(char *s1, char *s2) {
    while (*s1 != '\0') {
        if (*s1 == '_') {
            printf("%s", s2); // Replace '_' with the string pointed to by s2
        } else {
            printf("%c", *s1); // Print the character as it is
        }
        s1++;
    }
}

int main(void) {
    myPrintf("Hello _! How are you, _?\n", "Mike");
    myPrintf("Bonjour, _.\n", "Michel");
    myPrintf("_ _ _ _.\n", "Wow");
    myPrintf("YES, WE CAN!!\n", "Obama");
    return 0;
}
