#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(void) {
    unsigned int no;
    printf("Input nonegative integer: ");
    scanf("%i", &no);
    no = no + 1;

    int *primes = (int*)malloc(no * sizeof(int));
    // int *arr = (int*)malloc(no * sizeof(int));

    for(int i = 0; i < no; i++) {
        primes[i] = 1;
    }


    primes[0] = 0;
    primes[1] = 0;

    for(int i = 2; i <= sqrt(no); i++) {
        if(primes[i] == 0) {
            continue;
        } else {
            for(int j = 2 * i; j < no; j = j + i) {
                primes[j] = 0;
            }
        }   
    }

    printf("Primes are: ");
    for(int i = 0; i < no; i++) {
        if(primes[i] == 1) {
            printf("%i ", i);
        }
    }


    return 0;
}