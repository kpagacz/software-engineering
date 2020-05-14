#include<stdio.h>
#include<math.h>

float triangleArea(float a, float b, float c) {
    float s = 0.5 * (a + b + c);
    return sqrt(s * (s -a) * (s - b) * (s -c ));
};

int canFormTriangle(float a, float b, float c) {
    return a+b>c && a+c>b && b+c>a;
};

int main(void) {
    float a, b, c;
    printf("Input three sides of a triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    if(canFormTriangle(a, b, c)) {
        printf("Area of the triangle: %.2f\n", triangleArea(a, b, c));
    } else {
        printf("Sides %.2f %.2f %.2f do not form a triangle!\n", a, b, c, triangleArea(a, b, c));
    }
    return 0;
}