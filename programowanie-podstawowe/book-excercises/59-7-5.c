#include<stdio.h>
#include<limits.h>

int main(void) {
    float number, max = -1 * __FLT_MAX__;
    do {
        printf("Input a number: ");
        scanf("%f", &number);
        if(number > max) max = number;
    } while(number != -1);

    printf("Max number was: %f\n", max);
    return 0;
}