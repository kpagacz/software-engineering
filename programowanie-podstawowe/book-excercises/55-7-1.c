#include<stdio.h>

int main(void) {
    int number = 1, odd_sum = 0, even_sum = 0, odd_counter = 0, even_counter = -1;

    while(number != 0) {
        printf("Input a number (0 to exit): ");
        scanf("%i", &number);
        if(number % 2 == 0) {
            even_sum += number;
            even_counter++;
        } else {
            odd_sum += number;
            odd_counter++;
        }
    }

    printf("Even mean: %.2f  Odd mean: %.2f\n", 1.0 * even_sum / even_counter, 1.0 * odd_sum / odd_counter);
    return 0;
}