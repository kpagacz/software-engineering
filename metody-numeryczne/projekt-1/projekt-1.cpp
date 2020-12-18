#include <iostream>
#include <iomanip>



auto root_newton(double x, double eps, double func(double), double diff(double)) {
    int counter = 0;
    double h;
    do
    {
        h = -(func(x) / diff(x));
        x += h;
        counter++;
    } while (abs(h) > eps);
   
    return std::pair(x, counter);
}

int main() {


	return 0;
}