#include <iostream>
#include <vector>

int longest_subseq(int* arr, int size) {
	int* longest_subseqs = new int[size];
	for (int i = 0; i < size; i++) longest_subseqs[i] = 1;
	std::vector<int> notes(size, -1);

	for (int i = 1; i < size; i++)
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j])
				if (longest_subseqs[j] + 1 > longest_subseqs[i]) {
					longest_subseqs[i] = longest_subseqs[j] + 1;
					notes[i] = j;
				}

	int max_idx = 0;
	for (int i = 0; i < size; i++)
		if (longest_subseqs[i] > longest_subseqs[max_idx]) max_idx = i;
	
	int notes_idx = max_idx;
	std::cout << "Taken elements: ";
	do
	{
		std::cout << arr[notes_idx] << " ";
		notes_idx = notes[notes_idx];
	} while (notes_idx >= 0 && notes_idx != -1);

	std::cout << "\n";

	return longest_subseqs[max_idx];
}

int main() {
	int arr[5] = { 1, 1, 2, 3, 4 };
	std::cout << longest_subseq(arr, 5) << "\n";


}