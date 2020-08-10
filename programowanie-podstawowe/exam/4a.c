#include <stdio.h>


int silnia(int n);


int main(void) {
    unsigned int no;
    printf("Input positive number: ");
    scanf("%i", &no);
    // printf("%i", no);

    printf("Factorial: %i", silnia(no));
    return 0;
}


int silnia(int n ) {
    if(n == 0) {
        return 1;
    } else {
        return n * silnia(n - 1);
    }
}