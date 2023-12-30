#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Date {
    int year;
    int month;
    int day;
};

int randNumber(){
    return (rand() % 9999) + 1;
}

struct Preca {
    int id;
    int amount;
    struct Date date;
    int code;

};

int main() {
    srand(time(NULL));

    struct Preca c1 = {1, 1000, {2026, 3, 31}, randNumber()};

    printf("ID: %d\n", c1.id);
    printf("Amount: %d\n", c1.amount);
    printf("Expiration date: %d %d %d\n", c1.date.year, c1.date.month, c1.date.day);
    printf("Security code: %04d\n",c1.code);
    return 0;
}
