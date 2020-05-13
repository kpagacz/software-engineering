#include<stdio.h>
#include<math.h>

double distanceFromStart(double x, double y, int* quarter) {
    if(x >= 0) {
        if(y >= 0) {
            *quarter = 1;
        } else {
            *quarter = 4;
        }
    } else {
        if(y >= 0) {
            *quarter = 2;
        } else {
            *quarter = 3;
        }        
    }

    return sqrt(x*x + y*y);
}

int main(void) {
    double x, y;
    int quarter;
    int* quarter_ptr = &quarter;

    printf("Input x y coordinates: ");
    scanf("%lf %lf", &x, &y);

    double distance = distanceFromStart(x, y, quarter_ptr);

    printf("Distance from 0,0 = %lf\nQuarter = %i", distance, *quarter_ptr);

    return 0;
}