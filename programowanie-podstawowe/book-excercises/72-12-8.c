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

void toUpper(char text[]) {
    if(strlen(text) > 80) {
        printf("Text too large (needs to be less than 80 letters)\n");
    } else {
        for(int i = 0; i < strlen(text); i++) {
            text[i] = toupper(text[i]);
        }
    }
};

void reverse(char text[]) {
    int length = strlen(text);
    char temp;
    for(int i = 0; i < length/2; i++) {
        temp = text[i];
        text[i] = text[length - 1 - i];
        text[length - 1 - i] = temp;
    }
};

int main(void) {
    char text[80];
    printf("Input text (max 80 characters):\n");
    gets(text);

    reverse(text);
    toUpper(text);
    center(text);

    return 0;
}