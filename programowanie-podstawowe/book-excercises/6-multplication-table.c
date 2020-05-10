#include<stdio.h>

int main(void) {
    printf("Multplication table 10x10\n");

    printf("     ");
    for (int i = 1; i < 11; i++) {
        printf("%-5i", i);
    }
    printf("\n");

    for(int i = 1; i < 11; i++) {
        printf("%-5i", i);
        for(int j = 1; j < 11; j++) {
            printf("%-5i", i*j);
        }
        printf("\n");
    }

    return 0;
}