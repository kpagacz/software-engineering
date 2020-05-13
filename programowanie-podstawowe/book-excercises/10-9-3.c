#include<stdio.h>

void gain(double percent, double funds, double* gain) {
    *gain = funds * (1 + percent);
}


int main() {
    double p1 = 0.01, p2 = 0.02;
    double input;
    scanf("%lf", &input);
    
    double gain_d = 0, gain_d2 = 0;
    double* gain1 = &gain_d;
    double* gain2 = &gain_d2;

    gain(p1, input, gain1);
    printf("1p: %lf\n", *gain1);

    gain(p2, input, gain2);
    printf("2p: %lf\n", *gain2);
}