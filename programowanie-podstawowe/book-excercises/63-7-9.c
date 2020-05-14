#include<stdio.h>
#include<math.h>

int howManyNumbers(float max) {
    int result;
    float exact = -0.5 + 0.5 * sqrt(8 * max + 1);
    result = floor(exact);

    return result;
};

int main(void) {
    float max;
    printf("Input max: ");
    scanf("%f", &max);

    int howmany = howManyNumbers(max);
    printf("More than %i consecutive numbers need to be added together to get a number larger than %f\n", howmany, max);

    return 0;
}