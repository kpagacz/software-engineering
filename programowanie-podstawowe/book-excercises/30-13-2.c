#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "dynamic-arrays-toolbox.h"

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


int main(void) {
    printf("Input number of employees: ");
    int employees_no;
    scanf("%i", &employees_no);
    
    struct Employee* employees = (struct Employee*) malloc(employees_no * sizeof(struct Employee));
    float* wages = (float*) malloc(employees_no * sizeof(float));

    /* read in employees, calculate wage, find max */
    float max_wage = __FLT_MIN__;
    int max_wage_index = 0;
    float wages_sum = 0;
    for(int i = 0; i < employees_no; i++) {
        employees[i] = createEmployee();
        wages[i] = calculateWage(employees[i]);
        wages_sum += wages[i];
        if(wages[i] > max_wage) {
            max_wage = wages[i];
            max_wage_index = i;
        }
    }

    printf("Payroll:\n");
    output1Darray(wages, employees_no);

    printf("Sum of wages: %.2f\n", wages_sum);
    printf("Max wage: %.2f. Surname of the largest earner: %s\n", max_wage, employees[max_wage_index].surname);
    return 0;
}