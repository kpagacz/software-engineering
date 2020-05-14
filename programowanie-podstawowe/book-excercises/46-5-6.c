#include<stdio.h>

int stipend(float marks[3]) {
    float mean = (marks[0] + marks[1] + marks[2]) / 3;
    if(mean > 4) {
        return 500;
    } else {
        if (mean > 3) {
            return 300;
        } else {
            return 0;
        }
    }
}

int main(void) {
    float marks[3];
    printf("Input three marks from exams: ");
    scanf("%f %f %f", &marks[0], &marks[1], &marks[2]);

    printf("Stipend: %i zl", stipend(marks));
    return 0;
}