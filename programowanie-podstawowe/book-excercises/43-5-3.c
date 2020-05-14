#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char** argv) {
    if(argc != 4) {
        printf("Need three parameters a b c of a quadratic function.\nUsage: ./multiplication-table a b c");
        exit(1);
    }

    double a = strtod(argv[1], NULL);
    double b = strtod(argv[2], NULL);
    double c = strtod(argv[3], NULL);

    if(a == 0) {
        printf("This equation is not quadratic!\n");
        exit(1);
    }

    // delta method
    double delta = b*b - 4 * a * c;

    if(delta < 0) {
        printf("No real roots exist.\n");
        exit(1);
    }

    if(delta == 0) {
        printf("One root: %f", (-b - sqrt(delta)) / (2 * a));
        exit(0);
    }

    float x1 = (-b - sqrt(delta)) / (2 * a);
    float x2 = (-b + sqrt(delta)) / (2 * a);

    printf("Real roots are: %f %f", x1, x2);

    return 0;
}
