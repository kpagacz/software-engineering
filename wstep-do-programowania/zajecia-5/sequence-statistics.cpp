// Napisać program pobierający od użytkownika liczby całkowite w taki sposób,
// że wprowadzenie zera zakańcza podawanie, a następnie wypisujący sumę 
// wprowadzonych liczb, ich ilość i średnią oraz największą i najmniejszą
// wprowadzoną liczbę (wyniki mają nie uwzględniać końcowego zera).

#include <iostream>
#include <cmath>

int main() {
    // input
    int sum = 0;
    int number_count = 0;
    int smallest;
    int greatest;

    int number;

    // Edge case - first is zero
    std::cin >> number;
    if (number == 0) {
        std::cout << "Sum: " << sum << ". Number of values: " << number_count << ".";
        std::cout << "There is no smallest greatest or mean.";
        return 0;
    } else {
        sum += number;
        number_count ++;
        smallest = greatest = number;
    }

    while (std::cin >> number) {
        if (number == 0) {
            // end the inputting if number is 0
            break;
        } else {
            // if other than 0, calculate
            sum += number;
            number_count ++;
            smallest = smallest < number ? smallest : number;
            greatest = greatest > number ? greatest : number;
        }
    }

    float mean = 1.0 * sum / number_count;
    std::cout << "The sum is " << sum << ". The number of values is: " << number_count << ". The smallest was: " << smallest << ". The greatest was: " << greatest << ". ";
    std::cout << "The mean was: " << mean << ".";
    return 0;
}