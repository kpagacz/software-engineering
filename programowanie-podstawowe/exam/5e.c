#include<stdio.h>

int main(void) {
    char pass[100];

    printf("Input password: ");
    gets(pass);
    if(pass != NULL) {
        // printf("In if\n");
        for(int i = 0; pass[i] != 0; i++) {
            if(pass[i] >= 'A' && pass[i] <= 'Z') {
                printf("%c ", pass[i]);
            }
        }
    }
    return 0;
}