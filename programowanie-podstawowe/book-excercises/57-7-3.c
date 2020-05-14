#include<stdio.h>
#include<math.h>

int main(void) {
    double deposit, percent, goal;
    printf("Input deposit, goal and percentage: ");
    scanf("%lf %lf %lf", &deposit, &goal, &percent);

    double epochs = log2(goal / deposit) / log2(1 + percent);
    int int_epochs = (int)ceil(epochs);
    double exact_balance = pow(1 + percent, int_epochs) * deposit;
    printf("%i epochs needed to accumulate %.2lf.  Balance: %.2lf\n", int_epochs, goal, exact_balance);

    return 0;
}