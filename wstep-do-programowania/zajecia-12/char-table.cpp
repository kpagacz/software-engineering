// Napisać następujące funkcje operujące na napisach "w stylu C" (tablicach znaków):

//     funkcję zwracającą liczbę mówiącą ile razy znak podany jako parametr wystąpił w napisie podanym jako parametr,
//     funkcję zwracającą znak najczęściej występujący w napisie podanym jako parametr 
//          (jeśli kilka znaków ma tę samą częstość, należy zwrócić pierwszy z nich)
//     funkcję modyfikującą napis podany jako parametr poprzez zamianę w nim wszystkich liter na wielkie,
//     funkcję zwracającą łańcuch powstały z łańcucha podanego jako parametr poprzez zastąpienie
//          sąsiadujących z sobą takich samych znaków pojedynczym znakiem;
//     funkcję której parametrami są (przynajmniej): ciąg znaków oraz dodatnia liczba całkowita N, 
//          zwracającą ciąg znaków występujących w napisie podanym jako parametr dokładnie N razy,
//     funkcję o dwóch parametrach będących łańcuchami, zwracającą numer pozycji w pierwszym łańcuchu,
//          od której rozpoczyna się łańcuch drugi, lub -1 jeśli łańcuch drugi nie występuje w pierwszym; 
// oraz program testujący ich działanie. 

#include <iostream>
#include <cstring>

int countOccurances(char text[], char& sign);
char mostCommon(char text[]);
void changeToUppercase(char text[]);
char* demultiplicate(char text[], char* demultiplicate);
//????
int findInString(char text[], char look_for[]);

int main() {
    // input
    const int text_length = 101;
    char text[text_length];
    std::cout << "Input text (maximum 100 characters): ";
    std::cin.getline(text, text_length);

    // count occurances
    std::cout << "Counting occurances. Input sign to count in text: ";
    char sign;
    std::cin >> sign;
    std::cout << sign << " occured " << countOccurances(text, sign) << " times." << std::endl;

    // count the most frequent
    std::cout << "Most frequent sign in the text: " << mostCommon(text) << std::endl;

    // change to uppercase
    changeToUppercase(text);
    std::cout << "Text changed to uppercase:" << std::endl << text << std::endl;

    // demultiplicated
    char demultiplicated [text_length];
    char* demulti_text = demultiplicate(text, demultiplicated);
    std::cout << "Demultiplicated text: " << demulti_text << std::endl;

    // look for a text in the text
    char look_for[101];
    std::cout << "Input a string (maximum 100 characters) to look for in the text: " << std::endl;
    std::cin.ignore();
    std::cin.getline(look_for, 101);
    std::cout << "Index of the beginning of the searched string: " << findInString(text, look_for) << std::endl;

    return 0;
}

int countOccurances(char text[], char& sign) {
    int occurances = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == sign) {
            occurances++;
        }
    }
    return occurances;
}
char mostCommon(char text[]) {
    int hash[int('z') + 1] = {0};
    for (int i = 0; i < strlen(text); i++) {
        hash[text[i]]++;
    }
    int most_frequent = 0;
    for (int i = 1; i < 100; i++) {
        most_frequent = (hash[i] > hash[most_frequent]) ? i : most_frequent;
    }

    return char(most_frequent);
}
void changeToUppercase(char* text) {
    for (int i = 0; text[i] != 0; i++) {
        text[i] = toupper(text[i]);
    }
}
char* demultiplicate(char text[], char* demultiplicate) {
    demultiplicate[0] = text[0];
    int j = 1;
    for (int i = 1; i < strlen(text); i++) {
        if (text[i] != text[i-1]) {
            demultiplicate[j] = text[i];
            j++;
        }
    }
    demultiplicate[j] = 0;

    return demultiplicate;
}

//????

int findInString(char text[], char look_for[]) {
    int index_start = -1;
    for (int i = 0; i < strlen(text) - strlen(look_for); i++) {
        bool same = true;
        for (int j = 0; j < strlen(look_for); j++) {
            if (text[i + j] != look_for[j]) {
                same = false;
                break;
            }
        }

        if (same) {
            index_start = i;
            break;
        }
    }

    return index_start;
}