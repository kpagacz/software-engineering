#include<stdio.h>

int main(void) {
    float current, previous;
    float coefficient;
    
    int counter = 0;

    printf("Input numbers (0 ends): ");
    scanf("%f", &previous);
    if(previous == 0) {
        return 0;
    } else {
        counter++;
    }

    scanf("%f", &current);
    if(current == 0) {
        return 0;
    } else {
        counter ++;
    }

    coefficient = current / previous;

    while(current / previous == coefficient) {
        previous = current;
        scanf("%f", &current);
        if(current == 0 || current / previous != coefficient) {
            break;
        } else {
            counter++;
        }
    }

    printf("Numbers made a geometric sequence of length: %i\n", counter);

    return 0;
}