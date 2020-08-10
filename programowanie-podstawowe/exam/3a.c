#include <stdio.h>



int main(void) {
    unsigned int no;

    printf("Input a non negative integer: ");
    scanf("%i", &no);


    for(int i = 0; i <= no; i++) {
        if(i%3 == 0 && i%5 == 0) {
            printf("%i ", i);
        }
    }

    return 0;
}