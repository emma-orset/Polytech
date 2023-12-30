#include <stdio.h>
#include <stdlib.h>

/*
 *   This program calculates the GPA (Grade Point Average) based on user-input scores and credits for multiple subjects.
 *   @return int
 */
int main() {
    int num_subjects, scores[100], credits[100];
    int total_credits = 0, total_gp = 0;

    printf("Enter number of subjects: ");
    scanf("%d", &num_subjects);
    printf("\n");

    // Input scores and credits for each subject and calculate the total credits.
    for (int i = 0; i < num_subjects; i++) {
        printf("Enter a score for subject %d: ", i + 1);
        scanf("%d", &scores[i]);

        printf("Enter credits for subject %d: ", i + 1);
        scanf("%d", &credits[i]);

        printf("\n");

        total_credits += credits[i];
    }

    // Calculate the total grade points (GP) based on scores and credits for each subject.
    for (int i = 0; i < num_subjects; i++) {
        if (scores[i] >= 90) {
            total_gp += 4 * credits[i];
        } else if (scores[i] >= 80) {
            total_gp += 3 * credits[i];
        } else if (scores[i] >= 70) {
            total_gp += 2 * credits[i];
        } else if (scores[i] >= 60) {
            total_gp += credits[i];
        }
    }

    // Calculate the GPA using the total grade points and total credits.
    double gpa = (double)total_gp / total_credits;

    printf("Your GPA = %.3f \n", gpa);

    return 0;
}
