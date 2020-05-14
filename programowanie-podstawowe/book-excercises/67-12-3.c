#include<stdio.h>
#include<string.h>

int main(void) {
    char text[1000];

    gets(text);
    printf("Length: %i\n", strlen(text));
    return 0;
}