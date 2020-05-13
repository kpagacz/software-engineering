#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "dynamic-arrays-toolbox.h"

struct Student{
    char name[50];
    char surname[50];
    int marks[5];
};

float mean(int array[], int length) {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum += array[i];
    }

    float res = (1.0 * sum) / length;
    return res;
}

struct Student createStudent(void) {
    struct Student new_student;
    printf("Enter name and surname: ");
    char name[50], surname[50];
    scanf("%s %s", &name, &surname);

    strcpy(new_student.name, name);
    strcpy(new_student.surname, surname);

    printf("Input 5 marks: ");
    for(int i = 0; i < 5; i++) {
        scanf("%i", &new_student.marks[i]);
    }

    return new_student;
}

int main() {
    printf("Input N: ");
    int students_no;
    scanf("%i", &students_no);

    struct Student* students = malloc(students_no * sizeof(struct Student));
    float* mark_averages = malloc(students_no * sizeof(float));

    for(int i = 0; i < students_no; i++) {
        students[i] = createStudent();
        mark_averages[i] = mean(students[i].marks, 5);
    }

    float sum = 0;
    for(int i = 0; i < students_no; i++) {
        sum += mark_averages[i];
    }
    float group_mark_average = sum / students_no;

    printf("Mean marks:\n");
    output1Darray(mark_averages, students_no);

    printf("Group mean: %.2f", group_mark_average);

    return 0;
}