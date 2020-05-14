#include<stdio.h>
#include<string.h>
#include<ctype.h>

void decode(char text[], int shift) {
    int length = strlen(text);

    for(int i = 0; i < length; i++) {
        if(islower(text[i])) {
            text[i] = 'a' + ((text[i] - shift - 'a') % ('z' - 'a' + 1) + ('z' - 'a' + 1)) % ('z' - 'a' + 1);
        } else {
            if(isupper(text[i])) text[i] = 'A' + ((text[i] - shift - 'A') % ('Z' - 'A' + 1) + ('Z' - 'A' + 1)) % ('Z' - 'A' + 1);
        }
    }
};

void encode(char text[], int shift) {
    int length = strlen(text);

    for(int i = 0; i < length; i++) {
        if(islower(text[i])) {
            text[i] = 'a' + (text[i] + shift - 'a') % ('z' - 'a' + 1);
        } else {
            if(isupper(text[i])) {
                text[i] = 'A' + (text[i] + shift - 'A') % ('Z' - 'A' + 1);
            } 
        }
    }
};

int main(void) {
    char text[1000];
    printf("Text to encode decode\n");
    gets(text);
    encode(text, 3);

    puts(text);
    decode(text, 3);
    puts(text);

    return 0;
}