#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to read the previous amount of money from the binary file
int loadMoney() {
    FILE *file = fopen("kadai16_2_money.dat", "rb");
    if (file == NULL) {
        printf("Last Update Date and Time: Starting new record\n"); // First run, file doesn't exist
        return 0;
    }

    // Read the current amount of money
    int currentMoney;
    fread(&currentMoney, sizeof(int), 1, file);

    // Read the last update date and time
    char lastUpdate[100];
    fread(lastUpdate, sizeof(char), sizeof(lastUpdate), file);

    printf("Last Update Date and Time: %s\n", lastUpdate);

    fclose(file);
    return currentMoney;
}

// Function to write the current amount of money to the binary file
void saveMoney(int currentMoney) {
    FILE *file = fopen("kadai16_2_money.dat", "wb");
    if (file == NULL) {
        printf("Error: Failed to open the file.\n");
        exit(1);
    }

    // Get the current date and time
    time_t currentTime;
    struct tm *timeInfo;
    time(&currentTime);
    timeInfo = localtime(&currentTime);
    char lastUpdate[100];
    strftime(lastUpdate, sizeof(lastUpdate), "Year: %Y; Month: %m; Day: %d; Hour: %H; Minutes: %M; Seconds: %S\n", timeInfo);

    // Write the current amount of money and last update date and time to the binary file
    fwrite(&currentMoney, sizeof(int), 1, file);
    fwrite(lastUpdate, sizeof(char), sizeof(lastUpdate), file);

    fclose(file);
}

int main(int argc, char *argv[]) {
    int previousMoney = loadMoney(); // Load the previous amount of money from the binary file

    printf("Previous amount of money: %d yen\n", previousMoney);

    int income = 0;
    if (argc > 1) {
        income = atoi(argv[1]); // Convert command-line argument to integer if provided
        printf("Today's income: %d yen\n", income);
    }

    int expenses;
    printf("-----\nToday's expenses: ");
    scanf("%d", &expenses); // Input today's expenses

    int currentMoney = previousMoney + income - expenses; // Calculate current amount of money

    printf("-----\nCurrent amount of money: %d yen\n", currentMoney);

    saveMoney(currentMoney); // Save the current amount of money and last update date and time to the binary file

    return 0;
}
