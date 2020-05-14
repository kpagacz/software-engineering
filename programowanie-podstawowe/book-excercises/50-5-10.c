#include<stdio.h>

float max(float a, float b) {
    return a > b ? a : b;
}

float calculateTax(float wage) {
    return 0.18 * (max(wage - 556.02, 0)) + 0.32 * (max(0, wage - 85528)); 
};

int main(void) {
    float wage;
    printf("Input gross wage: ");
    scanf("%f", &wage);
    printf("Tax: %.2f", calculateTax(wage));
    return 0;
}