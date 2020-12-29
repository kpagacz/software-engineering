#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>


double equation_11(double x) {
    return x * pow(2, x) - 1;
}

double equation_11_der(double x) {
    return pow(2, x) * (x * log(2) + 1);
}

double equation_11_sol() {
    return 0.6411857445049859;
}

double algebraic_equation(double x) {
    return (x - 1.7) * (x + 0.3) * (x - 1.1);
}

double multipoint_formula_N(double x, double func(double), double diff(double)) {
    double u = func(x) / diff(x);
    return x - 1.0 / 4 * (u + 3 * func(x) / diff(
        x - 2.0 / 9 * (2 * u + func(x) / (diff(x - u)))
    ));
}

auto root_newton(double x, double eps, double func(double), double diff(double)) {
    int counter = 0;
    double h;
    do {
        h = -(func(x) / diff(x));
        x += h;
        counter++;
    } while (abs(h) > eps);
   
    return std::pair(x, counter);
}

auto root_multipoint(double x_start, double eps, double func(double), double diff(double)) {
    int counter = 0;
    double new_x, difference;
    do {
        new_x = multipoint_formula_N(x_start, func, diff);
        difference = abs(new_x - x_start);
        x_start = new_x;
        counter++;
    } while(difference > eps);

    return std::pair(x_start, counter);
}

void run_experment(std::ofstream& results_file) {

}

int main() {


	return 0;
}