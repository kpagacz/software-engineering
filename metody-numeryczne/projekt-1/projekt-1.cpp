#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <string>


double equation_11(double x) {
    return x * pow(2, x) - 1;
}

double equation_11_der(double x) {
    return pow(2, x) * (x * log(2) + 1);
}

double equation_11_sol(double x) {
    return 0.6411857445049859;
}

double algebraic_equation(double x) {
    return (x - 1.7) * (x + 0.3) * (x - 1.1);
}

double algebraic_equation_der(double x) {
    return 1.03 + x * (-5.0 + 3 * x);
}

double algebraic_equation_sol(double x) {
    // I will be checking only two roots, not three
    if (x > 1.7)
        return 1.7;
    else if (x < -0.3)
        return -0.3;
}

double multipoint_formula_N(double x, double func(double), double diff(double)) {
    double u = func(x) / diff(x);
    return x - 1.0 / 4 * (u + 3 * func(x) / diff(
        x - 2.0 / 9 * (2 * u + func(x) / (diff(x - u)))
    ));
}

auto root_newton(double x_start, double eps, double func(double), double diff(double)) {
    int counter = 0;
    double h;
    do {
        h = -(func(x_start) / diff(x_start));
        x_start += h;
        counter++;
    } while (abs(h) > eps);
   
    return std::make_pair(x_start, counter);
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

    return std::make_pair(new_x, counter);
}

void run_experiment(std::ofstream& results_file, double x_start, double eps, double func(double), double diff(double), double solution(double)) {
    auto multi_res = root_multipoint(x_start, eps, func, diff);
    auto newton_res = root_newton(x_start, eps, func, diff);

    double sol = solution(x_start);

    results_file << "wielopunktowa," <<
        std::fixed << std::setprecision(3) << x_start << "," <<
        std::scientific << std::setprecision(2) << eps << "," <<
        multi_res.second << "," <<
        std::fixed << std::setprecision(16) << multi_res.first << "," <<
        std::scientific << std::setprecision(3) << abs(multi_res.first - sol) << "," <<
        std::scientific << std::setprecision(3) << abs(multi_res.first - sol) / abs(multi_res.first) << "\n";

    results_file << "Newtona," <<
        std::fixed << std::setprecision(3) << x_start << "," <<
        std::scientific << std::setprecision(2) << eps << "," <<
        newton_res.second << "," <<
        std::fixed << std::setprecision(16) << newton_res.first << "," <<
        std::scientific << std::setprecision(3) << abs(newton_res.first - sol) << "," <<
        std::scientific << std::setprecision(3) << abs(newton_res.first - sol) / abs(newton_res.first) << "\n";
}

int main() {
    std::string file_name = "output.csv";
    std::ofstream results;
    results.open(file_name, std::ofstream::out);
    results << "Metoda,Poczatkowe x,Epsilon,Liczba iteracji,Wynik,Blad bezwzgledny,Blad wzgledny\n";

    double x_start = 10, eps = 0.001;
    //auto res = root_multipoint(x_start, eps, equation_11, equation_11_der);
    //std::cout << res.first << " " << res.second << "\n";

    run_experiment(results, x_start, eps, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 10, 0.1, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 100, 0.1, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 1000, 0.1, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 10000, 0.1, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 100000, 0.1, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 10, 0.001, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 100, 0.001, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 1000, 0.001, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 10000, 0.001, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 100000, 0.001, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 10, 0.0000001, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 100, 0.0000001, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 1000, 0.0000001, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 10000, 0.0000001, equation_11, equation_11_der, equation_11_sol);
    run_experiment(results, 100000, 0.0000001, equation_11, equation_11_der, equation_11_sol);

    results.close();
	return 0;
}