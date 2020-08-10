#include <stdio.h>



int main(void) {
    int month;
    printf("Input a month number: ");
    scanf("%i", &month);
    // printf("%i", month);

    if(month >= 1 && month <= 12) {
        printf("Month number is correct\n");
    } else {
        printf("Month number is incorrect\n");
    }

    return 0;
}