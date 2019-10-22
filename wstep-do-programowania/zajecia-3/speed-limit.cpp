#include <iostream>
#include <iomanip>

int main() {
    // input
    int exceeded;
    std::cout << "Input the number of kilometers per hour over the speed limit.\n";
    std::cin >> exceeded;

    // calculations
    int fine;
    if (exceeded < 11) {
        fine = exceeded / 10.0 * 50;
    } else if (exceeded < 21) {
        fine = 50 + (exceeded - 10) / 10.0 * 50;
    } else if (exceeded < 31) {
        fine = 100 + (exceeded - 20) / 10.0 * 100;
    } else if (exceeded < 41) {
        fine = 200 + (exceeded - 30) / 10.0 * 100;
    } else if (exceeded < 51) {
        fine = 300 + (exceeded - 40) / 10.0 * 100;
    } else {
        fine = 400 + __min(100, (exceeded - 51)/50.0 * 100);
    }

    // output
    std::cout << "Fine is: " << std::fixed << std::setprecision(2) << fine << " PLN.";
    return 0;
}