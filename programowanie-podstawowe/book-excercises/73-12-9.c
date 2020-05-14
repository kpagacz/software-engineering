#include<stdio.h>
#include<string.h>
#include<ctype.h>

void encode(char text[], int shift) {
    int length = strlen(text);

    for(int i = 0; i < length; i++) {
        if(islower(text[i])) {
            text[i] = 'a' + (text[i] + shift) % ('z' - 'a' - 1);
        } else {
            if(isupper(text[i])) text[i] = 'A' + (text[i] + shift) % ('Z' - 'A' - 1);
        }
    }
};

int main(void) {
    char text[1000];
    printf("Input text to encode (max 1000 characters):\n");
    gets(text);
    encode(text, 3);

    puts(text);
    return 0;
}