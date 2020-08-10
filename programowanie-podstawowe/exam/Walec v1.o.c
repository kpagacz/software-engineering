#include <stdio.h>
#define PI (3.1415)


int main(void) {
    double rad;
    double height;
    printf("Input radius and height of a cylinder (ex. 3 7): \n");
    scanf("%lf %lf", &rad, &height);
    double volume;
    volume =  rad * rad *  height * PI;

    printf("Volume: %lf\n", volume);

    return 0;
}