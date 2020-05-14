#include<stdio.h>

float pay_with_bonus(float wage, int years_employed) {
    if(years_employed < 5) {
        return wage;
    } else {
        if(years_employed < 10) {
            return wage * (1 + 1.0 * years_employed / 100);
        } else {
            return wage * (1 + 0.15);
        }
    }
}

int main(void) {
    float wage;
    int years_employed;

    printf("Input wage and years employed: ");
    scanf("%f %i", &wage, &years_employed);

    printf("Total wage (base and bonus): %.2f", pay_with_bonus(wage, years_employed));
    return 0;
}