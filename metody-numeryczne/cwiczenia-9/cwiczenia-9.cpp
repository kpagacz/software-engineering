#include <iostream>
#include "LCG_generator.h"
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
	LCG_generator gen(7);
	std::vector<double> random_nums;
	for (int i = 0; i < 10000; i++)
		random_nums.push_back(gen.random());

	//for (const auto& num : random_nums)
	//	std::cout << num << " ";

	std::cout << "\n";
	double mean = std::accumulate(random_nums.begin(), random_nums.end(), 0.0) / random_nums.size();
	std::cout << "mean: " << mean << "\n";

	auto sum_var = [&mean](double a, double b) {
		return std::move(a) + (b - mean) * (b - mean);
	};

	double variance1 = std::accumulate(random_nums.begin(), random_nums.end(), 0.0, sum_var) / random_nums.size();
	std::cout << "variance: " << variance1 << "\n";


	double var_sum = 0;
	for (const auto& num : random_nums)
		var_sum += (num - mean) * (num - mean);
	double variance = var_sum / random_nums.size();
	std::cout << "variance: " << variance << "\n";

	return 0;
}