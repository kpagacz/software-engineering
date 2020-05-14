#include<stdio.h>


int isInSquare(float x, float y) {
    if((x < -1 || x > 1) || (y < -1 || y > 1)) {
        return 0;
    } else {
        return 1;
    }
};

int isInCircle(float x, float y, float r) {
    return x * x + y * y <= r * r;
};

int main(void) {
    float x, y, r;
    printf("Input coordinates x and y of a single point as well as the radius of the circle\n");
    scanf("%f %f %f", &x, &y, &r);
    
    isInSquare(x, y) ? printf("Point in the 1x1 square.\n") : printf("Point outside of the 1x1 square.\n");

    isInCircle(x, y, r) ? printf("Point in the circle.\n") : printf("Point outside of the circle.\n");
    return 0;
}