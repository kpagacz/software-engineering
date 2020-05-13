#include<stdio.h>

int isZero(float tab[2][3]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            if(tab[i][j] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {
    float tab[2][3];

    printf("Input matrix (2v by 3c) elements:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%f", &tab[i][j]);
        }
    }

    int res = isZero(tab);

    res ? printf("There is zero.\n") : printf("There is no zero.\n");

    return 0;
}