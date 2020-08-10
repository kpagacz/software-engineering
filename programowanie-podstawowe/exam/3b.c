#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void) {
    unsigned int no;

    printf("Input a nonegative integer: ");
    scanf("%i", &no);

    if(no == 0 || no == 1) {
        printf("Not prime\n");
        return 0;
    }

    int isprime=1;

    for(int i = 2; i <= sqrt(abs(no)); i++) {
        if(no%i == 0) {
            isprime=0;
            break;
        }
    }

    if(isprime) {
        printf("Prime\n");
    } else {
        printf("Not prime\n");
    }
    return 0;
}