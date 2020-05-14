#include<stdio.h>
#include<string.h>


int main(void) {
    char text[1000];

    do {
        printf("Input text (quit to exit): ");
        fgets(text, 1000, stdin);
        text[strlen(text) - 1] = '\0';        
    } while(strcmp(text, "quit") != 0);
    return 0;
}