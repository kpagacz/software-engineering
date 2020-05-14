#include<stdio.h>

int weirdFunction(int a, int b, int c) {
    int all_even = 1;
    if(a % 2 || b % 2 || c % 2) {
        all_even = 0;
    }

    if(all_even) {
        return a + b +c;
    } else {
        if(a == 1 || b == 1 || c == 1) {
            return a * b * c;
        } else {
            return -1;
        }
    }
}

int main(void) {
    int a, b, c;
    printf("Input three integers: ");
    scanf("%i %i %i", &a, &b, &c);

    printf("Result of the weird function: %i", weirdFunction(a, b, c));
    return 0;
}