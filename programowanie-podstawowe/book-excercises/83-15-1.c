#include<stdio.h>

#define Pi 3.14

int main(void){
    float radius;
    printf("Input radius: ");
    scanf("%f", &radius);

    printf("Area: %.2f  Circumference: %.2f\n", Pi*radius*radius, 2*Pi*radius);

    return 0;
}