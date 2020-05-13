#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#include<time.h>

struct Student {
    char name[50];
    char surname[50];
    int lucky_number;
};

struct Student createStudent(void) {
    struct Student new_student;
    printf("Enter name and surname: ");
    char name[50], surname[50];
    scanf("%s %s", &name, &surname);

    strcpy(new_student.name, name);
    strcpy(new_student.surname, surname);

    new_student.lucky_number = rand() % 100;

    return new_student;
};

void printStudent(struct Student stud) {
    printf("%s %s %i\n", stud.name, stud.surname, stud.lucky_number);
};

int main(void) {
    srand(time(0));
    int N;
    printf("Input number of students: ");
    scanf("%i", &N);

    struct Student* students = malloc(N * sizeof(struct Student));


    int max_lucky_number = INT_MIN;
    int sum_of_lucky_numbers = 0;
    for(int i = 0; i < N; i++) {
        students[i] = createStudent();
        sum_of_lucky_numbers += students[i].lucky_number;
        if(max_lucky_number < students[i].lucky_number) {
            max_lucky_number = students[i].lucky_number;
        }
    }

    float mean_lucky_numbers = 1.0 * sum_of_lucky_numbers / N;
    float min_diff_to_mean = 100;


    printf("Largest lucky numbers:\n");
    for(int i = 0; i < N; i++) {
        if(students[i].lucky_number == max_lucky_number) {
            printStudent(students[i]);
        }
        if(abs(mean_lucky_numbers - students[i].lucky_number) < min_diff_to_mean) {
            min_diff_to_mean = abs(mean_lucky_numbers - students[i].lucky_number);
        }
    }

    printf("Closest to mean:\n");
    for(int i = 0; i < N; i++) {
        if(abs(students[i].lucky_number - mean_lucky_numbers) <= min_diff_to_mean) {
            printStudent(students[i]);
        }  
    }

    return 0;
}