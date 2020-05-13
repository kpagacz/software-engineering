#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<string.h>

struct Employee {
    char name[20], surname[30];
    int age, employement_start_year, department;
    float wage;
};

struct Employee createEmployee(void) {
    struct Employee new;
    printf("Input name, surname, age, year of the employement start (YYYY), department, wage:\n");
    scanf("%s %s %i %i %i %f", &new.name, &new.surname, &new.age, &new.employement_start_year, &new.department, &new.wage);

    return new;
};

void printEmployee(struct Employee emp) {
    printf("%s %s  Age:%i  Starting year:%i  Department%i  Wage:%.2f\n", 
            emp.name, emp.surname, emp.age, emp.employement_start_year, emp.department, emp.wage);
};

int findIndexLowestWage(struct Employee* employees, int employees_length) {
    float lowest = __FLT_MAX__;
    int lowest_index = 0;

    for(int i = 0; i < employees_length; i++) {
        if(employees[i].wage < lowest) {
            lowest = employees[i].wage;
            lowest_index = i;
        }
    }

    return lowest_index;
};

int findIndexHighestWage(struct Employee* employees, int employees_length) {
    float highest = __FLT_MIN__;
    int highest_index = 0;

    for(int i = 0; i < employees_length; i++) {
        if(employees[i].wage > highest) {
            highest = employees[i].wage;
            highest_index = i;
        }
    }

    return highest_index;
};

int findIndexYoungest(struct Employee* employees, int employees_length) {
    int lowest = INT_MAX;
    int lowest_index = 0;

    for(int i = 0; i < employees_length; i++) {
        if(employees[i].age < lowest) {
            lowest = employees[i].age;
            lowest_index = i;
        }
    }

    return lowest_index;
};

int findIndexOldest(struct Employee* employees, int employees_length) {
    int highest = INT_MIN;
    int highest_index = 0;

    for(int i = 0; i < employees_length; i++) {
        if(employees[i].age > highest) {
            highest = employees[i].age;
            highest_index = i;
        }
    }

    return highest_index;
};

int findIndexWorksLongest(struct Employee* employees, int employees_length) {
    int lowest = INT_MAX;
    int lowest_index = 0;
    for(int i = 0; i < employees_length; i++) {
        if(employees[i].employement_start_year < lowest) {
            lowest = employees[i].employement_start_year;
            lowest_index = i;
        }
    }

    return lowest_index;
};

int findIndexWorksShortest(struct Employee* employees, int employees_length) {
    int highest = INT_MIN;
    int highest_index = 0;

    for(int i = 0; i < employees_length; i++) {
        if(employees[i].employement_start_year > highest) {
            highest = employees[i].employement_start_year;
            highest_index = i;
        }
    }

    return highest_index;
};

void giveRaises(struct Employee* employees, int employees_length) {
    float small_raise = 0.1;
    float medium_raise = 0.2;
    float big_raise = 0.25;

    time_t time_t_now = time(NULL);
    struct tm* now = localtime(&time_t_now);
    int year_now = now->tm_year + 1900;
    int length_of_employement;

    for(int i = 0; i < employees_length; i++) {
        length_of_employement = year_now - employees[i].employement_start_year;

        if(length_of_employement < 5) {
            continue;
        } else {
            if(length_of_employement < 10) {
                employees[i].wage *= 1 + small_raise;
            } else {
                if(length_of_employement < 20) {
                    employees[i].wage *= 1 + medium_raise;
                } else {
                    employees[i].wage *= 1 + big_raise;
                }
            }
        }
    }

    free(now);
}

float* meanAgeInDepartments(struct Employee* employees, int employees_length, int number_of_departments) {
    int* sums = malloc(number_of_departments * sizeof(int));
    memset(sums, 0, number_of_departments * sizeof(sums[0]));
    int* employees_no_in_departments = malloc(number_of_departments * sizeof(int));
    memset(employees_no_in_departments, 0, number_of_departments * sizeof(sums[0]));
    float* means = malloc(number_of_departments * sizeof(float));


    for(int i = 0; i < employees_length; i++) {
        sums[employees[i].department] += employees[i].age;
        employees_no_in_departments[employees[i].department]++;
    }

    for(int i = 0; i < number_of_departments; i++) {
        means[i] = 1.0 * sums[i] / employees_no_in_departments[i];
    }

    free(sums);
    free(employees_no_in_departments);

    return means;
};

int* employees_no_in_departments(struct Employee* employees, int employees_length, int number_of_departments) {
    int* employees_no_in_departments = malloc(number_of_departments * sizeof(int));
    memset(employees_no_in_departments, 0, number_of_departments * sizeof(employees_no_in_departments[0]));
    for(int i = 0; i < employees_length; i++) {
        employees_no_in_departments[employees[i].department]++;
    }

    return employees_no_in_departments;
};

float* meanTimeInDepartments(struct Employee* employees, int employees_length, int number_of_departments) {
    int* sums = malloc(number_of_departments * sizeof(int));
    memset(sums, 0, number_of_departments * sizeof(sums[0]));
    int* employees_no_in_departments = malloc(number_of_departments * sizeof(int));
    memset(employees_no_in_departments, 0, number_of_departments * sizeof(sums[0]));
    float* means = malloc(number_of_departments * sizeof(float));

    time_t now = time(NULL);
    struct tm* now_tm = localtime(&now);
    int year_now = now_tm->tm_year + 1900;

    for(int i = 0; i < employees_length; i++) {
        sums[employees[i].department] += (year_now - employees[i].employement_start_year);
        employees_no_in_departments[employees[i].department]++;
    }

    for(int i = 0; i < number_of_departments; i++) {
        means[i] = 1.0 * sums[i] / employees_no_in_departments[i];
    }

    free(sums);
    free(employees_no_in_departments);
    free(now_tm);

    return means;
};

float* meanWageInDepartments(struct Employee* employees, int employees_length, int number_of_departments) {
    int* sums = malloc(number_of_departments * sizeof(int));
    memset(sums, 0, number_of_departments * sizeof(sums[0]));
    int* employees_no_in_departments = malloc(number_of_departments * sizeof(int));
    memset(employees_no_in_departments, 0, number_of_departments * sizeof(sums[0]));
    float* means = malloc(number_of_departments * sizeof(float));


    for(int i = 0; i < employees_length; i++) {
        sums[employees[i].department] += employees[i].wage;
        employees_no_in_departments[employees[i].department]++;
    }

    for(int i = 0; i < number_of_departments; i++) {
        means[i] = 1.0 * sums[i] / employees_no_in_departments[i];
    }

    free(sums);
    free(employees_no_in_departments);

    return means;
};

float meanWage(struct Employee* employees, int employees_length) {
    float mean;
    float sum = 0;

    for(int i = 0; i < employees_length; i++) {
        sum += employees[i].wage;
    }

    mean = sum / employees_length;
    return mean;
}

int main(void) {
    int no;
    printf("Input number of employees: ");
    scanf("%i", &no);

    struct Employee* employees = malloc(no * sizeof(struct Employee));
    for(int i = 0; i < no; i++) {
        employees[i] = createEmployee();
    }

    int lowest_wage = findIndexLowestWage(employees, no);
    int highest_wage = findIndexHighestWage(employees, no);
    int longest = findIndexWorksLongest(employees, no);
    int shortest = findIndexWorksShortest(employees, no);
    int youngest = findIndexYoungest(employees, no);
    int oldest = findIndexOldest(employees, no);

    printf("Current lowest wage employee:\n");
    printEmployee(employees[lowest_wage]);
    printf("Current highest wage employee:\n");
    printEmployee(employees[highest_wage]);
    printf("Current shortest employee:\n");
    printEmployee(employees[shortest]);
    printf("Current longest employee:\n");
    printEmployee(employees[longest]);
    printf("Current youngest employee:\n");
    printEmployee(employees[youngest]);
    printf("Current oldest employee:\n");
    printEmployee(employees[oldest]);

    giveRaises(employees, no);

    printf("\n\nAfter raises:\n");
    lowest_wage = findIndexLowestWage(employees, no);
    highest_wage = findIndexHighestWage(employees, no);
    longest = findIndexWorksLongest(employees, no);
    shortest = findIndexWorksShortest(employees, no);
    youngest = findIndexYoungest(employees, no);
    oldest = findIndexOldest(employees, no);
    printf("Current lowest wage employee:\n");
    printEmployee(employees[lowest_wage]);
    printf("Current highest wage employee:\n");
    printEmployee(employees[highest_wage]);
    printf("Current shortest employee:\n");
    printEmployee(employees[shortest]);
    printf("Current longest employee:\n");
    printEmployee(employees[longest]);
    printf("Current youngest employee:\n");
    printEmployee(employees[youngest]);
    printf("Current oldest employee:\n");
    printEmployee(employees[oldest]);

    printf("\nIs the longest employee also the youngest? ");
    longest == youngest ? printf("Yes") : printf("No");

    printf("\nIs the oldest employee also the shortest? ");
    oldest == shortest ? printf("Yes") : printf("No");
    printf("\n");

    printf("Input number of departments: ");
    int dept_no;
    scanf("%i", &dept_no);

    printf("\nMean age in departments:\n");
    float* mean_ages = meanAgeInDepartments(employees, no, dept_no);
    for(int i = 0; i < dept_no; i++) {
        printf("Dept no.%i: %.2f\n", i, mean_ages[i]);
    }

    printf("\nMean time of employement in departments:\n");
    float* mean_times = meanTimeInDepartments(employees, no, dept_no);
    for(int i = 0; i < dept_no; i++) {
        printf("Dept no.%i: %.2f\n", i, mean_times[i]);
    }

    printf("\nNumber of employees in departments\n");
    int* dept_employees = employees_no_in_departments(employees, no, dept_no);
    for(int i = 0; i < dept_no; i++) {
        printf("Dept no.%i: %i\n", i, dept_employees[i]);
    }

    printf("\nMean wages in departments:\n");
    float* mean_wages = meanWageInDepartments(employees, no, dept_no);
    for(int i = 0; i < dept_no; i++) {
        printf("Dept no.%i: %.2f\n", i, mean_wages[i]);
    }

    printf("\nMean wage in the company: %.2f\n", meanWage(employees, no));

    return 0;
}