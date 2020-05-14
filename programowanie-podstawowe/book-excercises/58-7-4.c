#include<stdio.h>

/* dla i = 0 element = 0, więc powinien przerywać, zakłądam, że zaczynamy od 1 */
void sequence(double epsilon) {
    double i = 1;
    double element = 0.25;
    while(element > epsilon) {
        element = i / ((i + 1) * (i + 1));
        printf("%.0lf %.2lf\n", i, element);
        i++;
    }
}

int main(void) {
    double epsilon;
    printf("Input number between from (0; 0.25): ");
    scanf("%lf", &epsilon);
    if(!(epsilon <= 0 || epsilon > 0.25)) {
        sequence(epsilon);
    } else {
        printf("Wrong epsilon value.\n");
    }
    return 0;
}