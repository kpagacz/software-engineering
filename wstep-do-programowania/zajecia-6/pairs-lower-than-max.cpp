// Napisać program pobierający od użytkownika wartości całkowite aż do 
// podania wartości 0 kończącej pobieranie i wypisujący te pary kolejno 
// podawanych liczb, dla których suma wartości pary jest mniejsza od 
// największej z dotychczas podanych wartości, oraz wypisujący ile było 
// takich par (końcowe zero nie jest brane pod uwagę; przykład: dla ciągu 
// wartości 4,1,2,3,-1,6,5,0 wypisane mają być pary: 1,2; 3,-1; -1,6 oraz 
// informacja że były 3 takie pary). 

#include <iostream>

int main() {
    // input
    int max = INT_MIN;
    int last_number, current_number, counter = 0;

    std::cin >> last_number;
    max = last_number > max ? last_number : max;
    if (last_number == 0) {
        std::cout << "No such pairs. "
        return 0;
    }

    while (std::cin >> current_number) {
        // if 0, stop accepting numbers
        if (current_number == 0) {
            break;
        }
        // else do stuff
        max = current_number > max ? current_number : max;

        if (current_number + last_number < max) {
            std::cout << last_number << " " << current_number << std::endl;
            counter++;
        }
        last_number = current_number;
    } 

    std::cout << "There was/were " << counter << " such pair(s)." << std::endl;
    return 0;
}