// Napisać program generujący napis będący losowym 
// ciagiem małych liter, o losowej długości nie większej 
// niż 20, a następnie informujący ile razy wystąpiły w 
// napisie poszczególne znaki. 
#include <iostream>
#include <cstdlib>
#include <time.h>

int main() {
    // initialize random seed
    srand(time(NULL));

    // create char array
    char text[21];

    // randomize length of the text
    int text_length = rand() % 21;

    // randomize the letters
    for (int i = 0; i < text_length; i++) {
        text[i] = rand() % 26 + 'a';
    }

    return 0;
}