#include<stdio.h>
#include<math.h>

float weirdFunction(float alpha, int t) {
    switch(t) {
        case 0:
        case 1:
        case 2:
        case 3:
            return 0.5 * (1 + cos(alpha));
        case 4:
        case 6:
        case 7:
            return sqrt(alpha * alpha + 1);
        case 8:
            return 1 - sin(alpha);
    }
};

int isTInRange(int t) {
    if(t >= 0 && t <= 3) {
        return 1;
    } else {
        if(t >= 6 && t <= 8) {
            return 1;
        } else {
            return 0;
        }
    }
};

int main(void) {
    float alpha;
    int t;

    printf("Input alpha and t: ");
    scanf("%f %i", &alpha, &t);
    isTInRange(t) ? printf("%f\n", weirdFunction(alpha, t)) : printf("parameter t is not in the defined range.\n");
    return 0;
}