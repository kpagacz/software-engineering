#include<stdio.h>

float sumColumn(float tab[][15], int column) {
    float sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += tab[i][column];
    }
    return sum;
}

int main(void) {
    float tab[10][15];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 15; j++) {
            tab[i][j] = 0.5 * (i + 1 + j + 1);
        }
    }

    int column = -1;
    while(column < 0 || column > 14) {
        printf("Choose a column to sum (0 - 14): ");
        scanf("%i", &column);
    }

    float sum = sumColumn(tab, column);

    printf("Sum of the column: %f\n", sum);

    return 0;
}