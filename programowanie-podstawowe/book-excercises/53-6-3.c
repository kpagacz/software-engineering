#include<stdio.h>
#include<math.h>

float area(char shape) {
    switch(shape) {
        case 't':
            printf("Input height and base lengths: ");
            float height, base;
            scanf("%f %f", &height, &base);
            return 0.5 * height * base;
        case 'c':
            printf("Input radius: ");
            float radius, pi = acos(-1);
            scanf("%f", &radius);
            return pi * radius * radius;
        case 'r':
            printf("Input sides lengths: ");
            float a, b;
            scanf("%f %f", &a, &b);
            return a * b;
    }
};

int main(void) {
    char shape;
    char color[20];
    
    printf("Input type of a shape: r - rectangle, t - triangle, c - circle: ");
    scanf("%c", &shape);

    printf("Input color: ");
    scanf("%s", &color);

    float out_area = area(shape);

    switch(shape) {
        case 't':
            printf("You chose: triangle, color %s, area %f", color, out_area);
            break;
        case 'r':
            printf("You chose: rectangle, color %s, area %f", color, out_area);
            break;
        case 'c':
            printf("You chose: circle, color %s, area %f", color, out_area);
            break;
        default:
            break;
    }
    return 0;
}