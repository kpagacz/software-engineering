#include<stdio.h>

int solveLinear(int a1, int b1, int c1, int a2, int b2, int c2, double* x1, double* x2) {
    int w = a1 * b2 - a2 * b1;
    int wx = c1 * b2 - c2 * b1;
    int wy = a1 * c2 - a2 * c1;

    if(w == 0) {
        if(wx == 0 && wy == 0) {
            return 0;
        } else {
            return -1;
        }
    } else {
        *x1 = 1.0 * wx / w;
        *x2 = 1.0 * wy / w;
        return 1;
    }
}

int main(void) {
    int a1, b1, a2, b2, c2, c1;
    double x, y;

    double* x_ptr = &x;
    double* y_ptr = &y;

    printf("Input integers a1 b1 c1 a2 b2 c2\n");
    scanf("%i %i %i %i %i %i", &a1, &b1, &c1, &a2, &b2, &c2);

    switch (solveLinear(a1, b1, c1, a2, b2, c2, x_ptr, y_ptr))
    {
    case -1:
        printf("Zero solutions.");
        break;
    case 0:
        printf("Infinetely many solutions.");
        break;
    case 1:
        printf("One solution: x=%lf y=%lf", *x_ptr, *y_ptr);
        break;
    
    default:
        break;
    }
    return 0;
}