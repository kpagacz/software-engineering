#include <iostream>

int main() {
    int array[3] = {0};

    int G;
    std::cout << "Input G: ";
    std::cin >> G;


    int single_number;
    int threes_counter = 0;

    std::cout << "Input numbers: ";

    for (int i = 1; i < 3; i++) {
        std::cin >> single_number;
        if (!single_number) {
            std::cout << "There is no such 3 element subsequences.";
            return 0;
        }
        array[i] = single_number;
    }


    int max1, max2;
    int sorted[3];
    int temp;
    bool first = true;

    while(true){
        for (int i = 0; i < 2; i++) {
            array[i] = array[i + 1];
        }
        std::cin >> single_number;
        if (single_number == 0) {
            break;
        }

        array[2] = single_number;

        for (int i = 0; i < 3; i++) {
            sorted[i] = array[i];
        }
        

        // sort
        for (int i = 0; i < 2; i++) {
            if (sorted[i] > sorted[i + 1]) {
                temp = sorted[i];
                sorted[i] = sorted[i + 1];
                sorted[i + 1] = temp;
            }
        }

        for (int i = 0; i < 1; i++) {
            if (sorted[i] > sorted[i + 1]) {
                temp = sorted[i];
                sorted[i] = sorted[i + 1];
                sorted[i + 1] = temp;
            }
        }


        // compare
        if ((sorted[1] + sorted[2]) / 2.0 > G) {
            if(first) {
                std::cout << array[0] << "," << array[1] << "," << array[2];
                first = false;
            } else {
                std::cout << "; " << array[0] << "," << array[1] << "," << array[2];
            }

            threes_counter ++;
        }

                
    }

    std::cout << std::endl;

    if (!threes_counter) {
        std::cout << "There is no such 3 element subsequences.";
    } else {
        std::cout << "Number of such 3 element subsequences: " << threes_counter;
    }

    return 0;
}