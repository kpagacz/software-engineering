#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Employee{
    char name[20];
    char surname[50];
    int hours, hourly_pay;
    float bonus_percent;
};

struct Employee createEmployee(void) {
    char name[20], surname[50];
    int hours, hourly_pay;
    float bonus;
    printf("Input name and surname of an employee, their hours and hourly wage and bonus in percents: ");
    scanf("%s %s %i %i %f", &name, &surname, &hours, &hourly_pay, &bonus);
    struct Employee new_employee;
    strcpy(new_employee.name, name);
    strcpy(new_employee.surname, surname);
    new_employee.hours = hours;
    new_employee.hourly_pay = hourly_pay;
    new_employee.bonus_percent = bonus;
    return new_employee;
};

float calculateWage(struct Employee employee) {
    float wage;
    wage = (employee.bonus_percent + 1) * employee.hours * employee.hourly_pay;
    return wage;
}

void printEmployee(struct Employee* employee) {
    printf("Name: %s\nSurname: %s\nHours: %i\nHourly pay: %i\nBonus: %.2f\n", 
            employee->name, employee->surname, employee->hours, employee->hourly_pay, employee->bonus_percent);
}

int main() {
    struct Employee em1 = createEmployee();
    printEmployee(&em1);
    printf("Employee wage: %.2f", calculateWage(em1));

    return 0;
}