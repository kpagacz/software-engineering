#include<stdlib.h>
#include<stdio.h>
#include<string.h>



struct Money{
    int value;
};

struct Trip{
    char place[50];
    char date[7];
};

struct Letter {
    char text[250];
};

union Prize{
    struct Money money;
    struct Trip trip;
    struct Letter letter;
};

struct Employee {
    char name[50];
    char surname[50];
    union Prize prize;
    int union_type;
};

struct Employee createEmployee(void) {
    struct Employee new_employee;
    printf("Input name, surname and prize(money, trip or letter): ");
    char name[50];
    char surname[50];
    char prize[10];
    scanf("%s %s %s", &name, &surname, &prize);

    strcpy(new_employee.name, name);
    strcpy(new_employee.surname, surname);

    if(strcmp(prize, "money") == 0) {
        printf("Input amount of money to award: ");
        int award;
        scanf("%i", &award);
        struct Money money;
        money.value = award;
        union Prize new_prize;
        new_prize.money = money;
        new_employee.prize = new_prize;
        new_employee.union_type = 0;
    }

    if(strcmp(prize, "trip") == 0) {
        printf("Input trip destination and date(DDMMYY): ");
        char destination[50];
        char date[7];
        scanf("%s %s", &destination, &date);
        struct Trip new_trip;
        strcpy(new_trip.place, destination);
        strcpy(new_trip.date, date);
        union Prize new_prize;
        new_prize.trip = new_trip;
        new_employee.prize = new_prize;
        new_employee.union_type = 1;
    }

    if(strcmp(prize, "letter") == 0) {
        printf("Input text of the letter: ");
        char text[250];
        scanf("%s", text);
        struct Letter letter;
        strcpy(letter.text, text);
        union Prize new_prize;
        new_prize.letter = letter;
        new_employee.prize = new_prize;    
        new_employee.union_type = 2;
    }

    return new_employee;
}

void printMoney(struct Money money) {
    printf("%i", money.value);
}

void printTrip(struct Trip trip) {
    printf("%s %s", trip.date, trip.place);
}

void printLetter(struct Letter letter) {
    printf("%s", letter.text);
}

void printEmployee(struct Employee emp) {
    printf("Name: %s  Surname: %s  ", emp.name, emp.surname);
    printf("Prize: ");
    switch(emp.union_type) {
        case 0:
            printf("Money: ");
            printMoney(emp.prize.money);
            break;
        case 1:
            printf("Trip: ");
            printTrip(emp.prize.trip);
            break;
        case 2:
            printf("Letter: ");
            printLetter(emp.prize.letter);
            break;
        default:
            break;
    }
    printf("\n");
}

int main(void) {
    int N;
    printf("Input number of employees: ");
    scanf("%i", &N);

    struct Employee* employees = malloc(N * sizeof(struct Employee));
    for(int i = 0; i < N; i++) {
        employees[i] = createEmployee();
    }

    for(int i = 0; i < N; i++) {
        printEmployee(employees[i]);
    }

    return 0;
}