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

// optimized Quick Sort
template <class T>
void RunExperiment(const int& size,
	int pivot_fnc(T[], const int&, const int&),
	void filling_fnc(int[], const int&), 
	std::ofstream&, std::string,
	std::string, std::string);

template <class T>
void QuickSort(T[], int begin, int end,
	int pivot_fnc(T[], const int&, const int&));

// non-optimized Quick Sort
template <class T>
void RunExperimentBase(const int& size, int pivot_fnc(T[],
	const int&, const int&),
	void filling_fnc(int[], const int&),
	std::ofstream&, std::string,
	std::string, std::string);

template <class T>
void QuickSortBase(T[], int begin,
	int end, int pivot_fnc(T[],
		const int&, const int&));

// Partition functions
template<class T>
int Partition(T[], const int& begin,
	const int& end,
	int pivot_fnc(T[], const int&, const int&)); // Lomuto

template<class T>
std::pair<int, int> PartitionThreeWayQuickerWorst(T arr[], const int& begin,
	const int& end,
	int choose_pivot(T[], const int&, const int&)); // Lomuto with ties

template<class T>
std::pair<int, int> PartitionThreeWay(T arr[],
	const int& begin, const int& end,
	int choose_pivot(T[], const int&, const int&)); // Hoar with ties

// Pivot functions
template <class T>
using PivotFunc = int (*) (T arr[], const int& begin,
	const int& end);

template <class T>
int random_pivot(T[], const int&, const int&);

template <class T>
int begin_pivot(T[], const int&, const int&);

template <class T>
int end_pivot(T[], const int&, const int&);

template <class T>
int median3_pivot(T[], const int&, const int&);

template <class T>
int median5_pivot(T[], const int&, const int&);

template <class T>
int median7_pivot(T[], const int&, const int&);

// Median functions
template <class T>
int median_pivot(T[], const int&, const int&, const int&);

template<class T>
int QuickSelect(T[], const int&, const int&, const int&);

// Array filling functions
using FillFunc = void (*) (int arr[], const int& size);
void exceed_size_fill(int[], const int&);
void limited_fill(int[], const int&);
void non_decreasing_fill(int[], const int&);

// Filling util functions
void uniform_fill(int[], const int&, const int&, const int&);

// Printing function
template<class T>
void print_arr(T[], const int&);

int main()
{
	// output file
	std::string file_name = "time-results-optimized.csv";
	std::ofstream out_file;
	out_file.open(file_name);
	out_file << "Array size" << ";" << "Fill function"
		<< ";" << "Pivot function" << ";" << "Time elapsed[s]\n";
	out_file.close();
	
	// filling functions names
	int fill_fncs_size = 3;
	int pivot_fncs_size = 6;
	std::string fill_names [] = 
		{"Random", "Only 0 to 100 values", "Non-decreasing"};
	FillFunc fill_funcs [] = {exceed_size_fill, limited_fill,
		non_decreasing_fill};
	std::string pivot_names [] = {"Random", "Median of 3 elements",
		"Median of 5 elements", "Median of 7 elements",
		"Begin", "End"};
	PivotFunc<int> pivot_functions [] = {random_pivot,
		median3_pivot, median5_pivot, median7_pivot,
		begin_pivot, end_pivot};

	int max_size, step;

	//std::cout << "Quick Sort with optimizations:\n";
	//int max_size = 1000000;
	//for(int j = 0; j < pivot_fncs_size; j++) {
	//	for(int i = 0; i < fill_fncs_size; i++) {
	//		std::cout << "[";
	//		for (int done_pivot = 0; done_pivot < j; done_pivot++)
	//			std::cout << "x";
	//		for (int undone_pivot = j; undone_pivot <= pivot_fncs_size;
	//			undone_pivot++)
	//			std::cout << "o";
	//		std::cout << "]\n";
	//		for(int size = 10000; size <= max_size; size += 10000) {
	//			RunExperiment(size, *pivot_functions[j],
	//				*fill_funcs[i], out_file, fill_names[i],
	//				pivot_names[j], file_name);
	//			std::cout << "    [";
	//			for (int size_done = 0; size_done < size;
	//				size_done += 10000)
	//				std::cout << "x";
	//			for (int size_undone = size; size_undone <= max_size;
	//				size_undone += 10000)
	//				std::cout << "o";
	//			std::cout << "]\n";
	//		}
	//	}
	//}


	//std::cout << "Unoptimized Quick Sort:\n";
	//std::string unoptimized_no_end_begin =
	//	"time-results-unoptimized-no-begin-end.csv";
	//out_file.open(unoptimized_no_end_begin);
	//out_file << "Array size" << ";" << "Fill function" << ";" 
	//	<< "Pivot function" << ";" << "Time elapsed[s]\n";
	//out_file.close();
	//max_size = 50000;
	//step = 1000;
	//for (int j = 0; j < pivot_fncs_size - 2; j++) {
	//	for (int i = 0; i < fill_fncs_size; i++) {
	//		std::cout << "[";
	//		for (int done_pivot = 0; done_pivot < j; done_pivot++)
	//			std::cout << "x";
	//		std::cout << ".";
	//		for (int undone_pivot = j; undone_pivot < pivot_fncs_size - 3;
	//			undone_pivot++)
	//			std::cout << "o";
	//		std::cout << "]\n";

	//		for (int size = step; size <= max_size; size += step) {
	//			RunExperimentBase(size, *pivot_functions[j],
	//				*fill_funcs[i], out_file, fill_names[i],
	//				pivot_names[j], unoptimized_no_end_begin);

	//			std::cout << "    [";
	//			for (int size_done = 0; size_done < size;
	//				size_done += step)
	//				std::cout << "x";
	//			for (int size_undone = size;
	//				size_undone < max_size - step;
	//				size_undone += step)
	//				std::cout << "o";
	//			std::cout << "]\n";
	//		}
	//	}
	//}

	//std::string unoptimized_end_begin = "time-results-unoptimized-begin-end.csv";
	//out_file.open(unoptimized_end_begin);
	//out_file << "Array size" << ";" << "Fill function" 
	//	<< ";" << "Pivot function" << ";" << "Time elapsed[s]\n";
	//out_file.close();
	//max_size = 50000;
	//step = 1000;
	//for (int j = 4; j < pivot_fncs_size; j++) {
	//	for (int size = step; size <= max_size; size += step) {
	//		for (int i = 0; i < fill_fncs_size; i++) {
	//			RunExperimentBase(size, *pivot_functions[j],
	//				*fill_funcs[i], out_file,
	//				fill_names[i], pivot_names[j],
	//				unoptimized_end_begin);
	//		}

	//		std::cout << "[";
	//		for (int done_pivot = 0; done_pivot < j; done_pivot++)
	//			std::cout << "x";
	//		std::cout << ".";
	//		for (int undone_pivot = j; undone_pivot < pivot_fncs_size - 1;
	//			undone_pivot++)
	//			std::cout << "o";
	//		std::cout << "]\n";

	//		std::cout << "    [";
	//		for (int size_done = 0; size_done < size; size_done += step)
	//			std::cout << "x";
	//		for (int size_undone = size; size_undone < max_size - step;
	//			size_undone += step)
	//			std::cout << "o";
	//		std::cout << "]\n";
	//	}
	//}

	return 0;
}

template<class T>
void QuickSort(T arr[], int begin, int end, int choose_pivot(T[],
	const int&, const int&))
{
	while (begin < end) {
		std::pair<int, int> pivots = PartitionThreeWayQuickerWorst(arr,
			begin, end, choose_pivot);
		if (pivots.first - begin > end - pivots.second) {
			QuickSort(arr, pivots.second + 1, end, choose_pivot);
			end = pivots.first - 1;
		}
		else {
			QuickSort(arr, begin, pivots.first - 1, choose_pivot);
			begin = pivots.second + 1;
		}
	}
}

template<class T>
void QuickSortBase(T arr[], int begin, int end,
	int choose_pivot(T[], const int&, const int&))
{
	if (begin < end) {
		int pivot = Partition(arr, begin, end, choose_pivot);
		QuickSortBase(arr, begin, pivot - 1, choose_pivot);
		QuickSortBase(arr, pivot + 1, end, choose_pivot);
	}
}

template<class T>
std::pair<int, int> PartitionThreeWay(T arr[],
	const int& begin, const int& end,
	int choose_pivot(T[], const int&, const int&))
{

	std::swap(arr[choose_pivot(arr, begin, end)], arr[end]);
	
	int begin_equal = begin - 1, end_equal = end,
		forward = begin - 1, backward = end;

	while (backward > forward) {
		while (arr[++forward] < arr[end]);
		while (arr[--backward] > arr[end]) if (backward == begin)
			break;
		if (backward <= forward) break;
		std::swap(arr[forward], arr[backward]);
		if (arr[forward] == arr[end])
			std::swap(arr[forward], arr[++begin_equal]);
		if (arr[backward] == arr[end])
			std::swap(arr[backward], arr[--end_equal]);
	}
	std::swap(arr[forward], arr[end]);
	backward = forward;

	// swap equals to the middle
	for (int i = begin; i < begin_equal; ++i)
		std::swap(arr[i], arr[--forward]);
	for (int i = end - 1; i > end_equal; --i)
		std::swap(arr[i], arr[++backward]);
	return std::pair<int, int>(forward, backward);
}

template<class T>
std::pair<int, int> PartitionThreeWayQuickerWorst(T arr[], const int& begin,
	const int& end, int choose_pivot(T[], const int&, const int&))
{

	std::swap(arr[choose_pivot(arr, begin, end)], arr[end]);

	int equal_end = begin, equal_begin = begin, new_end = end - 1;

	while (equal_end <= new_end) {
		if (arr[equal_end] < arr[end])
			std::swap(arr[equal_end++], arr[equal_begin++]);
		else if (arr[equal_end] > arr[end])
			std::swap(arr[equal_end], arr[new_end--]);
		else equal_end++;
	}
	std::swap(arr[end], arr[equal_end]);

	return std::pair<int, int>(equal_begin, equal_end);
}

template<class T>
int Partition(T arr[], const int& begin,
	const int& end, int choose_pivot(T[],
	const int&, const int&))
{
	std::swap(arr[choose_pivot(arr, begin, end)], arr[end]);
	int i = begin - 1;
	for (int j = begin; j < end; j++) {
		if (arr[j] < arr[end]) std::swap(arr[++i], arr[j]);
	}

	std::swap(arr[++i], arr[end]);
	return i;
}

template<class T>
int QuickSelect(T arr[], const int& begin,
	const int& end, const int& kth_elem)
{
	int pivot = Partition(arr, begin, end, random_pivot);
	if (pivot == kth_elem + begin) return pivot;

	if (pivot < kth_elem + begin) {
		return QuickSelect(arr, pivot + 1, end,
			kth_elem + begin - pivot - 1);
	}
	else {
		return QuickSelect(arr, begin, pivot - 1, kth_elem);
	}
}

template<class T>
int random_pivot(T arr[], const int& begin, const int& end)
{
	std::uniform_int_distribution<int> distribution (begin, end);
	return distribution(gen);
}

template<class T>
int begin_pivot(T arr[], const int& begin, const int& end)
{
	return begin;
}

template<class T>
int end_pivot(T arr[], const int& begin, const int& end)
{
	return end;
}

template<class T>
int median3_pivot(T arr[], const int& begin, const int& end)
{
	return median_pivot(arr, begin, end, 3);
}

template<class T>
int median5_pivot(T arr[], const int& begin, const int& end)
{
	return median_pivot(arr, begin, end, 5);
}

template<class T>
int median7_pivot(T arr[], const int& begin, const int& end)
{
	return median_pivot(arr, begin, end, 7);
}

template <class T>
int median_pivot(T arr[], const int& begin,
	const int& end, const int& elems) {
	int possible_begin = std::max((end + begin - elems + 1) / 2, begin);
	int possible_end = std::min((end + begin + elems - 1) / 2, end);
	return QuickSelect(arr, possible_begin, possible_end,
		(possible_end - possible_begin) / 2);
}

template<class T>
void print_arr(T arr[], const int& size)
{
	for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
	std::cout << "\n";
}

void uniform_fill(int arr[], const int& size,
	const int& min, const int& max)
{
	std::uniform_int_distribution<int> distribution (min, max);
	for (int i = 0; i < size; i++) arr[i] = distribution(gen);
}

void non_decreasing_fill(int arr[], const int& size)
{
	for(int i = 0; i < size; i++) arr[i] = i;
}

void exceed_size_fill(int arr[], const int& size) {
	uniform_fill(arr, size, 0, 2 * size);
}
void limited_fill(int arr[], const int& size) {
	uniform_fill(arr, size, 0, 100);
}

template <class T>
void RunExperiment(const int& size,
	int pivot_fnc(T[], const int&, const int&),
	void filling_fnc(int[], const int&),
	std::ofstream& out_file, std::string fill_name,
	std::string pivot_name, std::string file_name) {
	try {
		int* arr = new int[size];
		filling_fnc(arr, size);

		std::clock_t s_clock = std::clock();
		QuickSort(arr, 0, size - 1, pivot_fnc);
		std::clock_t e_clock = std::clock();
		double elapsed_time_ms = 1000.0 * (double(e_clock) - double(s_clock))
			/ CLOCKS_PER_SEC;

		out_file.open(file_name, std::ios::app);
		out_file << size << ";" << fill_name << ";"
			<< pivot_name << ";" << std::fixed << 
			std::setprecision(3) << elapsed_time_ms / 1000.0 << "\n";
		out_file.close();

		delete [] arr;
		return;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << "\n";
		return;
	}
}

template <class T>
void RunExperimentBase(const int& size,
	int pivot_fnc(T[], const int&, const int&),
	void filling_fnc(int[], const int&),
	std::ofstream& out_file, std::string fill_name,
	std::string pivot_name, std::string file_name) {
	try {
		int* arr = new int[size];
		filling_fnc(arr, size);

		std::clock_t s_clock = std::clock();
		QuickSortBase(arr, 0, size - 1, pivot_fnc);
		std::clock_t e_clock = std::clock();
		double elapsed_time_ms = 1000.0 *
			(double(e_clock) - double(s_clock))
			/ CLOCKS_PER_SEC;

		out_file.open(file_name, std::ios::app);
		out_file << size << ";" << fill_name << ";" 
			<< pivot_name << ";" << std::fixed << 
			std::setprecision(3) << elapsed_time_ms / 1000.0 << "\n";
		out_file.close();

		delete[] arr;
		return;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
		return;
	}
}
