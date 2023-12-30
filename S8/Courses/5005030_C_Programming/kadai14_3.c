#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int baseSalary;
    int housingAllowance;
    int transportationAllowance;
    int familyAllowance;

}Salary;

typedef struct{
    int memberId;
    char name[50];
    char position[20];
    int yearsOfService;
    char transport[30];
    Salary salary;

}Member;

int totalPay(Member _member){
    Salary salary = _member.salary;
    return salary.baseSalary+salary.familyAllowance+salary.housingAllowance+salary.transportationAllowance;
}

int main(void){
    Member members[5] = {
                            {127, "Humphrey", "s_chief", 21, "Bus", {400000, 10000, 4000, 25000}},
                            {204, "Cary", "s_chief", 15, "Train", {350000, 10000, 5000, 15000}},
                            {255, "James", "chief", 12, "Bus", {300000, 0, 2000, 0}},
                            {272, "Katharine", "member", 10, "Walk", {270000, 27000, 0, 0}},
                            {300, "Bette", "member", 5, "Train", {240000, 1000, 15000, 0}}
                        };

    char pos[20];
    int i;
    int count = 0;

    printf("Position: ");
    scanf("%s", pos);

    for(i=0; i<5; i++){
        if (strcmp(members[i].position,pos) == 0){
            printf("%d %s %s %d %s %d\n",members[i].memberId, members[i].name, members[i].position, members[i].yearsOfService, members[i].transport, totalPay(members[i]));
            count++;
        }

        if (i==4 && count==0){
            printf("Nobody\n");
            break;
        }
    }

    return 0;
}
