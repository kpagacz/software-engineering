#include<stdio.h>

int multiply(int a, int* b) {
    if(a >= 1 && a <= 100) {
        *b = (*b)*a;
        return 1;
    } else {
        return 0;
    }
}


int main(void) {
    int numbers;
    scanf("%i", &numbers);

    int one = 1;
    int* res = &one;
    int single_number;

    int multplication_happened = 0;
    for(int i = 0; i < numbers; i++) {
        scanf("%i", &single_number);
        if(multiply(single_number, res)) {
            multplication_happened = 1;
        }
    }

    if(multplication_happened) {
        printf("%i\n", *res);
    } else {
        printf("There were no numbers from <1, 100>\n");
    }
    
    return 0;
}
