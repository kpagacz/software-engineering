#include <iostream>
#include <cmath>

int main() {
    // input
    std::cout << "Please input an amount of money to pay and the amount given to the cashier.\n";
    float to_pay, given;
    do {
        std::cin >> to_pay >> given;
    } while (to_pay > given);

    float change = given - to_pay;

    // calculations
    float nominals[14] = {200, 100, 50, 20, 10, 5, 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
    int output[14] = {0}; // initializes with all 0s


    //int i = 0; // start with the highest nominal
    for (int i = 0; i < 14; i++) { 
        int i_nominal_in_change = floor(change / nominals[i]); // how many times the ith nominal is in the change
        output[i] = i_nominal_in_change; // assign this number to output[i]
        change -= i_nominal_in_change * nominals[i]; // decrease the change by the amount of money added by including ith nominal i_nominal_in_change times
        //i++; // go to the next nominal
    }

    // output
    std::cout << "The change of " << given-to_pay << " should be in:\n";
    for (int i = 0; i < 14; i++) {
        if (output[i] != 0) {
            std::cout << nominals[i] << " PLN: " << output[i] << std::endl;
        }
    }
    return 0;
}