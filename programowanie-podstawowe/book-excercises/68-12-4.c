#include<stdio.h>
#include<string.h>
#include<ctype.h>

void center(char text[]) {
    int length = strlen(text);
    for(int i = 0; i < 40 - length/2; i++) {
        printf(" ");
    }
    printf("%s\n", text);
};

int main(void) {
    char text[1000];
    printf("Input text:\n");
    gets(text);
    if(strlen(text) > 80) {
        printf("Text too large (needs to be less than 80 letters)\n");
    } else {
        for(int i = 0; i < strlen(text); i++) {
            text[i] = toupper(text[i]);
        }
    }

    center(text);
    return 0;
}