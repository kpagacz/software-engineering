#include <stdio.h>



int main(void) {
    printf("Input a number: ");
    float number;
    scanf("%f", &number);
    printf("Square is: %f\n", number * number);
    return 0;
}