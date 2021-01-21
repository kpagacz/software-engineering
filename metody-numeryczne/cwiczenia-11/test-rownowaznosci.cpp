#include <iostream>
#include <vector>
#include <numeric>
#include "LCG.h"

int main() {
	
	for (auto i : { 1, 7, 14, 23, 24, 79, 50, 101, 1010, 9 }) {
		LCG gen(i);
		std::vector<int> counts(10, 0);
		for (int i = 0; i < 10000; i++) {
			int rand = int(1000 * gen.random());
			counts[rand / 100]++;
		}

		double n = 10000, k = 10;
		auto sq_sum = [&n, &k](double sum, double el) {
			return std::move(sum) + (el - n / k) * (el - n / k);
		};

		double chi = k / n * std::accumulate(counts.begin(), counts.end(), 0.0, sq_sum);

		std::cout << "Counts: ";
		for (auto c : counts)
			std::cout << c << " ";
		std::cout << "Chi^2 statistic: " << chi << " ";
		std::cout << "\n";
	}

	return 0;
}