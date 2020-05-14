#include<stdio.h>

void PartialSums(int length) {
    float partial_sum = 0, number;
    printf("Input %i numbers:\n", length);
    while(length > 0) {
        scanf("%f", &number);
        partial_sum += number;
        length--;
        printf("Partial sum: %.2f\n", partial_sum);
    }

}

int main(void) {
    int length;
    printf("Input length of the sequence: ");
    scanf("%i", &length);

    PartialSums(length);

    return 0;
}