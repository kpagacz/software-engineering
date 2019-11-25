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

    // sort of a hash table
    int hash[26] = {0};

    // randomize the letters
    int single_letter;
    for (int i = 0; i < text_length; i++) {
        single_letter = rand() % 26;
        text[i] = single_letter + 'a';
        hash[single_letter] ++;
    }
    // input end character
    text[text_length] = '\0';

    std::cout << "Randomized text is: " << text << std::endl;

    // printing out counts of letters
    for (int i = 0; i < 26; i++) {
        if (hash[i]) {
            // if the letter occured at least once, print it
            std::cout << "Letter " << char(i + 'a') << " occured: " << hash[i] << " times." << std::endl;
        }
    }    

    return 0;
}