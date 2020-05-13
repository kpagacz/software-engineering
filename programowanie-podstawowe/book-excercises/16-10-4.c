#include<stdio.h>


float multiplicationDiagonal(float tab[][10], int length) {
    float result = 1;
    for(int i = 0; i < length; i++) {
        result *= tab[i][i];
    }

    return result;
}

float sumUpperHalf(float tab[][10], int length) {
    float sum = 0;
    for(int i = 0; i < length; i++) {
        for(int j = i + 1; j < length; j++) {
            sum += tab[i][j];
        }
    }
    return sum;
}

int main(void) {
    float tab[10][10];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tab[i][j] = 0.5 * (i + 1 + j + 1);
        }
    }

    float multiplication = multiplicationDiagonal(tab, 10);
    float sum = sumUpperHalf(tab, 10);

    printf("Multiplication result: %f\nSum result: %f\n", multiplication, sum);
    return 0;
}