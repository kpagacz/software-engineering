#include<stdio.h>

void weirdFunction(float a, float b, int w, float x) {
    switch(w) {
        case 2:
            if(x == 1.5) {
                printf("%.2f\n", a*a + 2 * a * b + b * b);
            }
            break;
        case 4:
            if(a == 1.5) {
                printf("%.2f\n", a + 2.0 / b + 4 * w);
            }
            break;
        case 8:
            if(b == 2) {
                printf("%.2f\n", a - x * w);
            }
            break;
        default:
            printf("No solutions.\n");
    }
}

int main(void){
    float a, b, x;
    int w;
    printf("Input a, b, x, w: ");
    scanf("%f %f %f %i", &a, &b, &x, &w);
    weirdFunction(a, b, w, x);
    
    return 0;
}