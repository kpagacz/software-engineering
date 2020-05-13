#include<stdio.h>

void swapFirstWithLastColumn(float tab[5][6]) {
    float temp;

    for(int i = 0; i < 5; i++) {
        temp = tab[i][0];
        tab[i][0] = tab[i][5];
        tab[i][5] = temp;
    }
}

int main(void) {
    float tab[5][6];

    printf("Input matrix (5v by 6c) elements:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 6; j++) {
            scanf("%f", &tab[i][j]);
        }
    }

    swapFirstWithLastColumn(tab);

    printf("Matrix after swap:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 6; j++) {
            printf("%f ", tab[i][j]);
        }
        printf("\n");
    }   

    return 0;
}