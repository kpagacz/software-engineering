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
    return (x - 1.71) * (x + 0.3) * (x - 1.11);
}

double algebraic_equation_der(double x) {
    return 1.03 + x * (-5.0 + 3 * x);
}

double algebraic_equation_sol(double x) {
    // I will be checking only two roots, not three
    if (x > 1.71)
        return 1.71;
    else if (x < -0.31)
        return -0.31;
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
        std::fixed << std::setprecision(16) << abs(multi_res.first - sol) << "," <<
        std::fixed << std::setprecision(16) << abs(multi_res.first - sol) / abs(multi_res.first) << "\n";

    results_file << "Newtona," <<
        std::fixed << std::setprecision(3) << x_start << "," <<
        std::scientific << std::setprecision(2) << eps << "," <<
        newton_res.second << "," <<
        std::fixed << std::setprecision(16) << newton_res.first << "," <<
        std::fixed << std::setprecision(16) << abs(newton_res.first - sol) << "," <<
        std::fixed<< std::setprecision(16) << abs(newton_res.first - sol) / abs(newton_res.first) << "\n";
}

double order_sequence(double previous, double current, double solution, int p) {
    return abs(current - solution) / pow(abs(previous - solution), p);
}

void newton_order(std::ofstream& results_file, double x_start, double eps, double func(double), double diff(double), double solution(double)) {
    results_file << "Element no, p = 1, p = 2, p = 3, p = 4\n";
    double sol = solution(x_start);

    int counter = 0;
    double h, new_x;
    do {
        h = -(func(x_start) / diff(x_start));
        new_x = x_start + h;
        
        results_file << ++counter << ","
            << order_sequence(x_start, new_x, sol, 1) << ","
            << order_sequence(x_start, new_x, sol, 2) << ","
            << order_sequence(x_start, new_x, sol, 3) << ","
            << order_sequence(x_start, new_x, sol, 4) << ","
            << "\n";

        x_start = new_x;
    } while (abs(h) > eps);
}

void multipoint_order(std::ofstream& results_file, double x_start, double eps, double func(double), double diff(double), double solution(double)) {
    results_file << "Element no, p = 1, p = 2, p = 3, p = 4, p = 5\n";
    int counter = 0;
    double new_x, difference, sol = solution(x_start);
    do {
        new_x = multipoint_formula_N(x_start, func, diff);
        difference = abs(new_x - x_start);

        results_file << ++counter << ","
            << order_sequence(x_start, new_x, sol, 1) << ","
            << order_sequence(x_start, new_x, sol, 2) << ","
            << order_sequence(x_start, new_x, sol, 3) << ","
            << order_sequence(x_start, new_x, sol, 4) << ","
            << order_sequence(x_start, new_x, sol, 5) << ","
            << "\n";

        x_start = new_x;
    } while (difference > eps);

}

int main() {
    // point A and C: speed of convergence and precision depending on the starting x (with a constant epsilon)
    std::string file_name = "results/pointAC-algebraic.csv";
    std::ofstream algebraic_results;
    algebraic_results.open(file_name, std::ofstream::out);
    algebraic_results << "Metoda,Poczatkowe x,Epsilon,Liczba iteracji,Wynik,Blad bezwzgledny,Blad wzgledny\n";

    std::string file_name2 = "results/pointAC-eq11.csv";
    std::ofstream eq11_results;
    eq11_results.open(file_name2, std::ofstream::out);
    eq11_results<< "Metoda,Poczatkowe x,Epsilon,Liczba iteracji,Wynik,Blad bezwzgledny,Blad wzgledny\n";

    double epsilon = 0.001;
    for (double x = 10; x <= 100; x += 10)
        run_experiment(eq11_results, x, epsilon, equation_11, equation_11_der, equation_11_sol);
    for(double x = 10; x <= pow(10,10); x*=10)
        run_experiment(algebraic_results, x, epsilon, algebraic_equation, algebraic_equation_der, algebraic_equation_sol);

    algebraic_results.close();
    eq11_results.close();

    // point B and D: speed of convergence and precision depending on the epsilon (with a constant starting x)
    file_name = "results/pointBD-algebraic.csv";
    algebraic_results.open(file_name, std::ofstream::out);
    algebraic_results << "Metoda,Poczatkowe x,Epsilon,Liczba iteracji,Wynik,Blad bezwzgledny,Blad wzgledny\n";

    file_name2 = "results/pointBD-eq11.csv";
    eq11_results.open(file_name2, std::ofstream::out);
    eq11_results << "Metoda,Poczatkowe x,Epsilon,Liczba iteracji,Wynik,Blad bezwzgledny,Blad wzgledny\n";

    double start_x = 10;
    for (double epsilon = 1; epsilon >= pow(10, -16); epsilon /= 10) {
        run_experiment(algebraic_results, start_x, epsilon, algebraic_equation, algebraic_equation_der, algebraic_equation_sol);
        run_experiment(eq11_results, start_x, epsilon, equation_11, equation_11_der, equation_11_sol);
    }
    algebraic_results.close();
    eq11_results.close();

    // Supplementary objectives: order of convergence of both methods
    file_name = "results/convergence-order-newton.csv";
    file_name2 = "results/convergence-order-multipoint.csv";
    std::ofstream newton_out;
    std::ofstream multi_out;
    newton_out.open(file_name);
    multi_out.open(file_name2);
    double order_x_start = 100, order_eps = 0.00000000000001;
    newton_order(newton_out, order_x_start, order_eps, equation_11, equation_11_der, equation_11_sol);
    multipoint_order(multi_out, order_x_start, order_eps, equation_11, equation_11_der, equation_11_sol);
    newton_out.close();
    multi_out.close();
	return 0;
}