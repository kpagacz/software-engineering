#include<stdio.h>
#include<string.h>

void center(char text[]) {
    int length = strlen(text);
    for(int i = 0; i < 40 - length/2; i++) {
        printf(" ");
    }
    printf("%s\n", text);
};

int main(void) {
    char text[81];

    printf("Input text (up to 80 characters!)\n");
    gets(text);
    center(text);
    return 0;
}