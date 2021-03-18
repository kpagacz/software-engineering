#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>


int main() {
	// Is this really C++?
	int tab[3];
	tab[0] = 10;
	tab[1] = 7;
	tab[2] = 8;

	// This is C++
	int tab_cpp[3]{ 10, 7 ,8 };

	// Even better
	std::vector<int> arr{ 10, 7, 8 };

	// Old-school
	for (int i = 0; i < 3; i++)
		std::cout << tab_cpp[i] << " ";
	std::cout << "\n";

	// Range-loops
	for (const auto& i : tab_cpp)
		std::cout << i << " ";
	std::cout << "\n";

	// Find the minimum value in an array
	int min = INT_MAX;
	for (int i = 0; i < 3; i++)
		if (tab_cpp[i] < min) min = tab_cpp[i];
	std::cout << "Min value is: " << min << "\n";

	// #include <algorithm>
	std::cout << "Min value is: " << *std::min_element(tab_cpp, tab_cpp + 3) << "\n";

	// Summing
	int sum = 0;
	for (int i = 0; i < 3; i++) sum += tab_cpp[i];

	std::cout << "Sum is: " << sum << '\n';

	std::cout << "Sum is: " << std::accumulate(tab_cpp, tab_cpp + 3, 0) << "\n";


	return 0;
}