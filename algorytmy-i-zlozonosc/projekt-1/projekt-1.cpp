#include <iostream>
#include <stdlib.h>
#include <chrono>

template <class T>
void QuickSort(T[], int, int, size_t (T[], size_t, size_t) = begin_pivot);

template<class T>
size_t Partition(T[], size_t, size_t, size_t (T[], size_t, size_t));

template<class T>
size_t QuickSelect(T[], size_t, size_t, size_t);

template <class T>
size_t random_pivot(T[], size_t, size_t);

template <class T>
size_t begin_pivot(T[], size_t, size_t);

template <class T>
size_t end_pivot(T[], size_t, size_t);

template <class T>
size_t median3_pivot(T[], size_t, size_t);

template <class T>
size_t median5_pivot(T[], size_t, size_t);

template <class T>
size_t median7_pivot(T[], size_t, size_t);

void uniform_fill(long long[], size_t, const unsigned long&, const unsigned long&);
void non_decreasing_fill(long long[], size_t);

template<class T>
void print_arr(T[], size_t);

int main()
{
	srand(1);
	std::cout << "RAND_MAX is: " << RAND_MAX << "\n";
	std::cout << "SIZE_MAX is: " << SIZE_MAX << "\n";

	size_t size = 9;
	long long* arr = new long long[size];

	uniform_fill(arr, size, 0, size);

	print_arr(arr, size);
	std::cout << QuickSelect(arr, 5, size - 1, 1) << "\n";
	print_arr(arr, size);

	return 0;
}

template<class T>
void QuickSort(T arr[], int begin, int end, size_t choose_pivot(T[], size_t, size_t))
{
	if (begin < end) {
		size_t pivot_index = Partition(arr, begin, end, choose_pivot);
		QuickSort(arr, begin, pivot_index - 1, choose_pivot);
		QuickSort(arr, pivot_index + 1, end, choose_pivot);
	}
}

template<class T>
size_t Partition(T arr[], size_t begin, size_t end, size_t choose_pivot(T[], size_t, size_t))
{
	std::swap(arr[choose_pivot(arr, begin, end)], arr[end]);

	size_t i = begin;
	for (size_t j = begin; j < end; j++) {
		if (arr[j] <= arr[end]) std::swap(arr[i++], arr[j]);
	}

	std::swap(arr[i], arr[end]);
	return size_t(i);
}

template<class T>
size_t QuickSelect(T arr[], size_t begin, size_t end, size_t kth_elem)
{
	size_t pivot = Partition(arr, begin, end, random_pivot);
	if (pivot == kth_elem + begin) return pivot;

	if (pivot < kth_elem + begin) {
		return QuickSelect(arr, pivot + 1, end, kth_elem - pivot);
	}
	else {
		return QuickSelect(arr, begin, pivot - 1, kth_elem);
	}
}

template<class T>
size_t random_pivot(T arr[], size_t begin, size_t end)
{
	return (rand() % (end - begin + 1)) + begin;
}

template<class T>
size_t begin_pivot(T arr[], size_t begin, size_t end)
{
	return begin;
}

template<class T>
size_t end_pivot(T arr[], size_t begin, size_t end)
{
	return end;
}

template<class T>
size_t median3_pivot(T arr[], size_t begin, size_t end)
{
	return 0;
}

template<class T>
size_t median5_pivot(T arr[], size_t begin, size_t end)
{
	return 0;
}

template<class T>
size_t median7_pivot(T arr[], size_t begin, size_t end)
{
	return 0;
}

template<class T>
void print_arr(T arr[], size_t size)
{
	for (size_t i = 0; i < size; i++) std::cout << arr[i] << " ";
	std::cout << "\n";
}

void uniform_fill(long long arr[], size_t size, const unsigned long& min, const unsigned long& max)
{
	long long rand_max = RAND_MAX;
	for (size_t i = 0; i < size; i++) arr[i] = (rand() * rand_max) % (max - min + 1) + min;
}

void non_decreasing_fill(long long arr[], size_t size)
{
	uniform_fill(arr, size, 0, 2 * size);
	QuickSort(arr, 0, size - 1, begin_pivot);
}
