#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <ctime>
#include <string>

// random generator setup
std::random_device rd;
std::mt19937 gen(rd());

template <class T>
double RunExperiment(const long& size, long pivot_fnc(T[], const long&, const long&), void filling_fnc(long[], const long&));

template <class T>
void QuickSort(T[], const long& begin, const long& end, long pivot_fnc(T[], const long&, const long&));

template<class T>
long Partition(T[], const long& begin, const long& end, long pivot_fnc(T[], const long&, const long&));

// pivots functions
template <class T>
using PivotFunc = long (*) (T arr[], const long& begin, const long& end);

template <class T>
long random_pivot(T[], const long&, const long&);

template <class T>
long begin_pivot(T[], const long&, const long&);

template <class T>
long end_pivot(T[], const long&, const long&);

template <class T>
long median3_pivot(T[], const long&, const long&);

template <class T>
long median5_pivot(T[], const long&, const long&);

template <class T>
long median7_pivot(T[], const long&, const long&);

// util median function
template <class T>
long median_pivot(T[], const long&, const long&, const int&);

template<class T>
long QuickSelect(T[], const long&, const long&, const long&);

// filling functions
using FillFunc = void (*) (long arr[], const long& size);
void exceed_size_fill(long[], const long&);
void limited_fill(long[], const long&);
void non_decreasing_fill(long[], const long&);

// filling util functions
void uniform_fill(long[], const long&, const long&, const long&);

template<class T>
void print_arr(T[], long);

int main()
{
	// output file
	std::string file_name = "time_results.csv";
	std::ofstream out_file;
	out_file.open(file_name);
	out_file << "Array size" << ";" << "Fill function" << ";" << "Pivot function" << ";" << "Time elapsed[s]\n";
	out_file.close();
	
	// filling functions names
	int fill_fncs_size = 3;
	int pivot_fncs_size = 6;
	std::string fill_names [] = {"Random", "Only 0 to 100 values", "Non-decreasing"};
	std::string pivot_names [] = {"Random", "Begin", "End", "Median of 3 elements", "Median of 5 elements", "Median of 7 elements"};

	FillFunc fill_funcs [] = {exceed_size_fill, limited_fill, non_decreasing_fill};
	PivotFunc<long> pivot_functions [] = {random_pivot, begin_pivot, end_pivot, median3_pivot, median5_pivot, median7_pivot};

	long max_size = 200000;
	for(long size = 10000; size <= max_size; size += 10000) {
		for(int i = 0; i < fill_fncs_size; i++) {
			for(int j = 0; j < pivot_fncs_size; j++) {
				double elapsed_time = RunExperiment(size, *pivot_functions[j], *fill_funcs[i]);
				out_file << size << ";" << fill_names[i] << ";" << pivot_names[j] << ";" << std::fixed << std::setprecision(3) << elapsed_time << "\n";
			}
		}
		// Progress bar
		std::cout << "[";
		for(long done = 10000; done <= size; done += 10000) std::cout << "x";
		for(long not_done = size + 10000; not_done <= max_size; not_done += 10000) std::cout << "o";
		std::cout << "]\n";
	}

	out_file.close();
	return 0;
}

template<class T>
void QuickSort(T arr[], const long& begin, const long& end, long choose_pivot(T[], const long&, const long&))
{
	if (begin < end) {
		long pivot_index = Partition(arr, begin, end, choose_pivot);
		QuickSort(arr, begin, pivot_index - 1, choose_pivot);
		QuickSort(arr, pivot_index + 1, end, choose_pivot);
	}
}

template<class T>
long Partition(T arr[], const long& begin, const long& end, long choose_pivot(T[], const long&, const long&))
{
	std::swap(arr[choose_pivot(arr, begin, end)], arr[end]);

	long i = begin;
	for (long j = begin; j < end; j++) if (arr[j] <= arr[end]) std::swap(arr[i++], arr[j]);

	std::swap(arr[i], arr[end]);
	return i;
}

template<class T>
long QuickSelect(T arr[], const long& begin, const long& end, const long& kth_elem)
{
	long pivot = Partition(arr, begin, end, random_pivot);
	if (pivot == kth_elem + begin) return pivot;

	if (pivot < kth_elem + begin) {
		return QuickSelect(arr, pivot + 1, end, kth_elem + begin - pivot - 1);
	}
	else {
		return QuickSelect(arr, begin, pivot - 1, kth_elem);
	}
}

template<class T>
long random_pivot(T arr[], const long& begin, const long& end)
{
	std::uniform_int_distribution<long> distribution (begin, end);
	return distribution(gen);
}

template<class T>
long begin_pivot(T arr[], const long& begin, const long& end)
{
	return begin;
}

template<class T>
long end_pivot(T arr[], const long& begin, const long& end)
{
	return end;
}

template<class T>
long median3_pivot(T arr[], const long& begin, const long& end)
{
	return median_pivot(arr, begin, end, 3);
}

template<class T>
long median5_pivot(T arr[], const long& begin, const long& end)
{
	return median_pivot(arr, begin, end, 5);
}

template<class T>
long median7_pivot(T arr[], const long& begin, const long& end)
{
	return median_pivot(arr, begin, end, 7);
}

template <class T>
long median_pivot(T arr[], const long& begin, const long& end, const int& elems) {
	long possible_begin = std::max((end + begin - elems + 1) / 2, begin);
	long possible_end = std::min((end + begin + elems - 1) / 2, end);
	return QuickSelect(arr, possible_begin, possible_end, (possible_end - possible_begin) / 2);
}

template<class T>
void print_arr(T arr[], const long& size)
{
	for (long i = 0; i < size; i++) std::cout << arr[i] << " ";
	std::cout << "\n";
}

void uniform_fill(long arr[], const long& size, const long& min, const long& max)
{
	std::uniform_int_distribution<long> distribution (min, max);
	for (long i = 0; i < size; i++) arr[i] = distribution(gen);
}

void non_decreasing_fill(long arr[], const long& size)
{
	for(long i = 0; i < size; i++) arr[i] = i;
}

void exceed_size_fill(long arr[], const long& size) {
	uniform_fill(arr, size, 0, 2 * size);
}
void limited_fill(long arr[], const long& size) {
	uniform_fill(arr, size, 0, 100);
}

template <class T>
double RunExperiment(const long& size, long pivot_fnc(T[], const long&, const long&), void filling_fnc(long[], const long&)) {
	try {
		long* arr = new long[size];
		filling_fnc(arr, size);

		std::clock_t s_clock = std::clock();
		QuickSort(arr, 0, size - 1, pivot_fnc);
		std::clock_t e_clock = std::clock();
		double elapsed_time_ms = 1000.0 * (e_clock - s_clock) / CLOCKS_PER_SEC;

		delete [] arr;
		return elapsed_time_ms / 1000.0;	
	}
	catch(const std::exception& e) {
		return -1;
	}
}
