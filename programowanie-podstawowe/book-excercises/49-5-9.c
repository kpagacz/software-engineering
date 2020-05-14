#include<stdio.h>

int isInAlphabet(char character) {
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
};

int isCode2Digitis(char character) {
    return character >= 10 && character < 100;
};

int isOperator(char character) {
    return (character == '-') || (character == '+') || (character == '\\') || (character == '*'); 
};

int main(void) {
    char character;
    printf("Input a character: ");
    scanf("%c", &character);

    isInAlphabet(character) ? printf("Character is in latin alphabet.\n") : printf("Character is not in latin alphabet.\n");
    isCode2Digitis(character) ? printf("Character has 2 digit code.\n") : printf("Character does not have 2 digit code.\n");
    isOperator(character) ? printf("Character is an arithmetic operator.\n") : printf("Character is not a mathematical operator.\n");
    return 0;
}