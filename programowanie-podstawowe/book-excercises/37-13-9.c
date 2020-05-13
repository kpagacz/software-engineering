#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    char name[50];
    char surname[50];
    int marks[5];
};

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
};

float mean(int array[], int length) {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum += array[i];
    }

    float res = (1.0 * sum) / length;
    return res;
};

void printStudent(struct Student student) {
    printf("%s  %s  ", student.name, student.surname);
    for(int j = 0; j < 5; j++) {
        printf("%i ", student.marks[j]);
    }
};

void printStudents(struct Student* students, int students_length) {
    for(int i = 0; i < students_length; i++) {
        printStudent(students[i]);
        printf("%.2f\n", mean(students[i].marks, 5));
    }
};


void printHigherStipend(struct Student* students, int students_length) {
    int higher = 1;
    for(int i = 0; i < students_length; i++) {
        higher = 1;
        for(int j = 0; j < 5; j++) {
            if(students[i].marks[j] != 5) {
                higher = 0;
            }
        }
        if(higher) {
            printStudent(students[i]);
            printf("\n");
        }
    }
}

void printNormalStipend(struct Student* students, int students_length) {
    int was4 = 0, no3 = 1;
    for(int i = 0; i < students_length; i++) {
        was4 = 0;
        no3 = 1;
        for(int j = 0; j < 5; j++) {
            if(students[i].marks[j] == 4) {
                was4 = 1;
            }
            if(students[i].marks[j] <= 3) {
                no3 = 0;
            }
        }
        if(was4 == 1 && no3 == 1) {
            printStudent(students[i]);
            printf("\n");
        }
    }
}

int main(void) {
    int no;
    printf("Input number of students: ");
    scanf("%i", &no);

    struct Student* students = malloc(no * sizeof(struct Student));
    for(int i = 0; i < no; i++) {
        students[i] = createStudent();
    }

    printf("List of students:\n");
    printStudents(students, no);

    printf("List of students with higher stipend:\n");
    printHigherStipend(students, no);

    printf("List of students with normal stipend:\n");
    printNormalStipend(students, no);

    return 0;
}