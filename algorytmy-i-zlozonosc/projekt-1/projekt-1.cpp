#include <iostream>
#include <stdlib.h>

template <class T>
void QuickSort(T[], int, int, size_t (T[], size_t, size_t) = begin_pivot);

template<class T>
size_t Partition(T[], size_t, size_t, size_t (T[], size_t, size_t));

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

void uniform_fill(int[], size_t, const int&, const int&);
void non_decreasing_fill(int[], size_t);

template<class T>
void print_arr(T[], size_t);

int main()
{
	srand(0);
	size_t size = 5;
	int* arr = new int[size];

	non_decreasing_fill(arr, size);

	print_arr(arr, size);
	QuickSort(arr, 0, 4, begin_pivot);
	print_arr(arr, size);

	return 0;
}

template<class T>
void QuickSort(T arr[], int begin, int end, size_t choose_pivot(T[], size_t, size_t))
{
	if (begin < end) {
		int pivot_index = Partition(arr, begin, end, choose_pivot);
		QuickSort(arr, begin, pivot_index - 1, choose_pivot);
		QuickSort(arr, pivot_index + 1, end, choose_pivot);
	}
}

template<class T>
size_t Partition(T arr[], size_t begin, size_t end, size_t choose_pivot(T[], size_t, size_t))
{
	std::swap(arr[choose_pivot(arr, begin, end)], arr[end]);
	T pivot = arr[end];

	int i = begin - 1;
	for (size_t j = begin; j < end; j++) {
		if (arr[j] <= pivot) {
			std::swap(arr[++i], arr[j]);
		}
	}

	std::swap(arr[++i], arr[end]);
	return size_t(i);
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

void uniform_fill(int arr[], size_t size, const int& min, const int& max)
{
	int interval_end = max - min + 1;
	for (size_t i = 0; i < size; i++) arr[i] = rand() % interval_end + min;
}

void non_decreasing_fill(int arr[], size_t size)
{
	uniform_fill(arr, size, 0, 2 * size);
	QuickSort(arr, 0, size - 1, begin_pivot);
}
