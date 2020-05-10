#include <stdio.h>

int main(void){
    float a, b;

    printf("Input two real numbers: ");
    scanf("%f %f", &a, &b);

    float res = a * b;

    printf("Multiplication result: %f\n", res);
    return 0;
}