#include<stdio.h>
#include<ctype.h>

int main(void) {
    char character = '1', looking_for;
    int digit_counter = 0, looging_for_counter = 0;

    printf("Input character to look for: ");
    scanf("%c", &looking_for);

    printf("Input a sentence:\n");
    scanf(" %c", &character);
    while(character != '.') {
        if(isdigit(character)) {
            digit_counter ++;
        }
        if(character == looking_for) {
            looging_for_counter++;
        }
        scanf("%c", &character);
    }

    printf("There was %i digits and %i cases of %c.\n", digit_counter, looging_for_counter, looking_for);
    return 0;   
}