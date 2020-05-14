#include<stdio.h>
#include<string.h>

void justifyRight(char poem[7][80]) {
    int line_length;
    for(int i = 0; i < 7; i++) {
        line_length = strlen(poem[i]);
        for(int j = 0; j < 80 - line_length; j++) {
            printf(" ");
        }
        printf("%s", poem[i]);
    }
};

int main(void) {
    char poem[7][80];
    for(int i = 0; i < 7; i++) {
        fgets(poem[i], 80, stdin);
    }

    justifyRight(poem);

    return 0;
}