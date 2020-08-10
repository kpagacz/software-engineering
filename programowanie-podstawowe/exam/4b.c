#include<stdio.h>


void hanoi(int N, char A, char B, char C) {
    if(N > 0) {
        hanoi(N - 1, A, C, B);
        printf("%c -> %c\n", A, B);
        hanoi(N - 1, C, B, A);
    }
}

int main(void) {
    printf("HANOI XD\n");

    hanoi(3, 'A', 'B', 'C');
    return 0;
}