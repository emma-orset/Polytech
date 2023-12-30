#include <stdio.h>
#include <stdlib.h>

/*
 *   This program checks the exam scores of 10 students and prints whether each student has passed or failed.
 *   @return int
 */
int main() {
    int tab[10] = {60, 36, 42, 51, 83, 81, 29, 45, 77, 62};

    for (int i = 0; i < 10; i++) {
        if (tab[i] >= 60) {
            printf("Student number %d = %d : succeeded\n", i + 1, tab[i]);
        } else {
            printf("Student number %d = %d : failed\n", i + 1, tab[i]);
        }
    }

    return 0;
}
