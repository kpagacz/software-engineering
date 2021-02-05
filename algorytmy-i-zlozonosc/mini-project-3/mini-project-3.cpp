#include <iostream>
#include <ctime>
#include <random>
#include <cstring>
#include <string>
#include <fstream>

std::random_device rd;
std::mt19937 gen(rd());

// HEAPSORT
int p(int x)
{
  return (x+1)/2-1;
}

int l(int x)
{
  return 2*(x+1)-1;
}

int r(int x)
{
  return 2*(x+1);
}

void FixFromBelow(int heap[], int count)
{
  int ktory = count;
  while(heap[ktory]>heap[p(ktory)] && ktory>0)
  {
   std::swap(heap[ktory],heap[p(ktory)]);
   ktory=p(ktory);
  }
}

void FixFromAbove(int heap[], int count)
{
    int idx = 0;
    while(true)
    {
      int naj = idx;
      if(l(idx) <= count && heap[naj]<heap[l(idx)]) naj = l(idx);
      if(r(idx) <= count && heap[naj]<heap[r(idx)]) naj = r(idx);
      // ustaliłem, kto jest naj
      if(idx==naj) break;
      std::swap(heap[idx], heap[naj]); idx = naj;
    }
}

void Add(int heap[], int &count, int num)
{
  count++;
  heap[count]=num;
  FixFromBelow(heap, count);
}

int Get(int heap[], int &count)
{
  std::swap(heap[0],heap[count]);
  count--;
  FixFromAbove(heap, count);
  return heap[count+1];
}

void HeapSort(int tab[], int size)
{
     int count = 0;
     for(int i=1; i<size; i++) {
         count++;
         FixFromBelow(tab, count);
     }
     for(int i=1; i<size; i++) Get(tab, count);
}

// QUICKSORT
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


template<typename T>
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
void QuickSort(T arr[], int begin, int end)
{
	if (begin < end) {
		int pivot = Partition<int>(arr, begin, end, begin_pivot);
		QuickSort(arr, begin, pivot - 1);
		QuickSort(arr, pivot + 1, end);
	}
}

int main()
{
    std::uniform_int_distribution<int> distribution (0, 100);

    // Output file setup
    std::string file_name = "results.csv";
    std::ofstream output;
    output.open(file_name, std::ios_base::out);
    output << "Array size,Heap Sort Time[ms],Quick Sort Time[ms]\n";

    for(int i = 20000; i <= 1000000; i+=20000) {
        output << i << ",";
        int* arr = new int[i];
        std::uniform_int_distribution<int> distribution (0, i);

        for(int j = 0; j < i; j++) arr[j] = distribution(gen);

        // Heap sort time measurement
        int* sort_array = new int[i];
        std::memcpy(sort_array, arr, sizeof(int) * i);

        std::clock_t s_time = std::clock();
        HeapSort(sort_array, i);
        std::clock_t e_time = std::clock();
        double elapsed_time_ms = 1000.0 * (double(e_time) - double(s_time))
			/ CLOCKS_PER_SEC;
        output << elapsed_time_ms << ",";

        // Quick sort time measurement
        std::memcpy(sort_array, arr, sizeof(int) * i);
        
        s_time = std::clock();
        QuickSort(sort_array, 0, i - 1);
        e_time = std::clock();
        elapsed_time_ms = 1000.0 * (double(e_time) - double(s_time))
			/ CLOCKS_PER_SEC;
        output << elapsed_time_ms << "\n";

        delete [] arr;
        delete [] sort_array;        
    }

    output.close();
    return 0;
}
