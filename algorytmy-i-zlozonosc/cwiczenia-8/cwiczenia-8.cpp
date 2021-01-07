#include <iostream>

// Only the maximum value of the knapsack with maximum weight of max_weight
int knapsack_rec(int udzwig, int w[], int c[], int IleTowarow) {
	if (udzwig <= 0) return 0;

	int max_value = 0;

	for(int i = 0; i < IleTowarow; i++)
		if (w[i] <= udzwig) {
			int v = c[i] + knapsack_rec(udzwig - w[i], w, c, IleTowarow);
			if (v > max_value) max_value = v;
		}

	return max_value;
}

// Maximum value + what to put
int knapsack_it(int max_weight, int w[], int p[], int items) {
	int* values = new int [max_weight + 1];
	int* put_in = new int[max_weight + 1];

	for (int i = 0; i < max_weight + 1; i++) 
		put_in[i] = -1;

	values[0] = 0;

	
	for (int i = 0; i < max_weight + 1; i++) {
		int max_value = 0, what = -1;
		int value;
		for(int j = 0; j < items; j++)
			if (w[j] <= i) {
				value = p[j] + values[i - w[j]];
				if (value > max_value) {
					max_value = value;
					what = j;
				}
			}
		values[i] = max_value;
		put_in[i] = what;
	}

	int total = max_weight;
	std::cout << "{";
	while (put_in[total] > -1) {
		std::cout << " " << put_in[total] << " ,";
		total -= w[put_in[total]];
	}
	std::cout << "}\n";

	return values[max_weight];
}

//
int max_subset_rec1(int* arr, int start, int stop) {
	int max_sum = 0;
	int curr_sum = 0;

	if (start == stop) return arr[start];

	for (int i = start; i <= stop; i++) {
		curr_sum = max_subset_rec1(arr, start, i - 1) + max_subset_rec1(arr, i + 1, stop);
		if (curr_sum > max_sum) max_sum = curr_sum;
	}
	
	return max_sum;
}

int main() {
	const int ile_towarow = 3;
	int wagi[] { 21, 20, 18 };
	int ceny[] { 100, 80, 62 };

	//std::cout << knapsack_it(40, wagi, ceny, ile_towarow);

	int values[]{7, 1, 1, 7, 8};
	std::cout << max_subset_rec1(values, 0, 4);

	return 0;
}