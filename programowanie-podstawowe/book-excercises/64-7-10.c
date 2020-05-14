#include<stdio.h>


int main(void) {
    char choice;

    printf("Menu:\n");
    printf("k - KONIEC\n");
    printf("l - list\n");
    printf("o - open\n");

    do {
        printf("Input choice: ");
        scanf(" %c", &choice);
    } while(choice != 'k');

    return 0;
}