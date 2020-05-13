#include<stdio.h>
#include<limits.h>

int main(void) {
    int numbers;
    scanf("%i", &numbers);

    int max[2] = {INT_MIN, INT_MIN};
    int single_number;

    if(numbers <= 2) {
        for(int i = 0; i < numbers; i++) {
            scanf("%i", &single_number);
            printf("%i ", single_number);
        }
        printf("\n");
    } else {
        for(int i = 0; i < numbers; i++) {
            scanf("%i", &single_number);

            if(single_number > max[1]) {
                max[0] = max[1];
                max[1] = single_number;
            } else {
                if(single_number > max[0]) {
                    max[0] = single_number;
                }
            }
        }

        printf("%i %i", max[0], max[1]);
    }

    return 0;
}