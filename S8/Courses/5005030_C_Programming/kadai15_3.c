#include <stdio.h>
#include <string.h>

#define MAX_CHAR_LENGTH 50
#define MAX_DATA_ENTRIES 100
#define MAX_BUFFER_SIZE 256

typedef struct{
    int id;
    char name[MAX_CHAR_LENGTH];
    char position[MAX_CHAR_LENGTH];
    int yearsOfService;
    int salary;
}Person;

void displayData(Person persons[], int nbLines) {
    for (int i = 0; i < nbLines; i++) {
        printf("%4d %10s %20s %4d %10d\n", persons[i].id, persons[i].name, persons[i].position, persons[i].yearsOfService, persons[i].salary);
    }
}

int searchAndDisplay(Person persons[], int nbLines, const char *searchName) {
    for (int i = 0; i < nbLines; i++) {
        if (strcmp(persons[i].name, searchName) == 0) {
            printf("\n%d %s %s %d %d\n\n", persons[i].id, persons[i].name, persons[i].position, persons[i].yearsOfService, persons[i].salary);
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Arguments missing. Enter the name of the file.\n");
        return 1;
    }

    FILE *filep = fopen(argv[1], "r");
    if (filep == NULL) {
        printf("Wrong file.\n");
        return 1;
    }

    Person persons[MAX_DATA_ENTRIES];

    int i = 0;
    char line[MAX_BUFFER_SIZE];

    while (fgets(line,MAX_BUFFER_SIZE, filep) != NULL) {
        sscanf(line, "%d %s %s %d %d", &persons[i].id, persons[i].name, persons[i].position, &persons[i].yearsOfService, &persons[i].salary);
        i++;
    }

    displayData(persons, i);

    char searchName[MAX_CHAR_LENGTH];
    printf("\nName: ");
    scanf("%s", searchName);

    fclose(filep);

    if (searchAndDisplay(persons, i, searchName) == 1) {
        printf("No data for this name.\n");
        return 1;
    }else{
        return 0;
    }
}
