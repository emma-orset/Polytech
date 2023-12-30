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

void printPreca(struct Preca _p){
    printf("#%d: %d, %04d/%02d/%02d, %04d\n", _p.id,_p.amount, _p.date.year, _p.date.month, _p.date.day, _p.code);
}

int main() {
    srand(time(NULL));

    struct Preca c1 = {1, 1000, {2026, 3, 31}, randNumber()};
    printPreca(c1);
    return 0;
}

