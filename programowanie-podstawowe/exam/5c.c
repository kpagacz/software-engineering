#include<stdio.h>

int main(void) {
    char name[100];

    printf("Input your name: ");
    gets(name);

    printf("Hello, %s", name);

    return 0;
}