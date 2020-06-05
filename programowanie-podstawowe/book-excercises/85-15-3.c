#include<stdio.h>
#include<limits.h>

#define MAX(a,b) (a) >= (b) ? (a) : (b)

int main(void) {
    int N;
    printf("Input N: ");
    scanf("%d", &N);

    int number;
    int max = INT_MIN;
    printf("Input N numbers: ");
    for(int i = 0; i < N; i++) {
        scanf("%d", &number);
        max = MAX(max, number);
    }

    printf("Maximus was: %d\n", max);
    return 0;
}