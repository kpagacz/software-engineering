#include<stdio.h>

int isSymmetrical(float tab[2][3]) {
    int isSymetric = 1;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3 / 2; j++) {
            if(tab[i][j] != tab[i][3 - 1 - j]) {
                isSymetric = 0;
            }
        }
    }

    return isSymetric;
}

int main(void) {
    float tab[2][3];

    printf("Input matrix (2v by 3c) elements:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%f", &tab[i][j]);
        }
    }

    int symetric = isSymmetrical(tab);

    symetric ? printf("Matrix is symmetric.\n") : printf("Matrix is not symmetric.\n");
    return 0;
}