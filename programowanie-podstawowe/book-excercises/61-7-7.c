#include<stdio.h>

int isIncreasing(int length) {
    float previous, current;
    printf("Input %i numbers: ", length);
    int isIncreasing = 1;
    scanf("%f", &previous);
    length --;
    if(length == 0) return 1;
    scanf("%f", &current);
    do {
        if(current < previous) {
            isIncreasing = 0;
        }
        length--;
    } while(length > 0);

    return isIncreasing;
}

int main(void) {
    int length;
    printf("Input length of the sequence: ");
    scanf("%i", &length);

    isIncreasing(length) ? printf("Is increasing.\n") : printf("Is not increasing.\n");

    return 0;
}