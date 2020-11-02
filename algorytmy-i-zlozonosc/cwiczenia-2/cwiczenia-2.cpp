// cwiczenia-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<time.h>

using namespace std;
const int rozm = 100;

void selectionSort(int tab[], unsigned int size) {
	for (int i = 0; i < size; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (tab[j] < tab[min]) {
				min = j;
			}
		}
		std::swap(tab[i], tab[min]);
	}
}

void bubbleSort(int tab[], unsigned int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) { // robic check do size - i - 1, a nie size, bo ostatnia jest juz max
			if (tab[j] < tab[j - 1]) {
				std::swap(tab[j], tab[j - 1]);
			}
			else {
				if (j == size - i) {	// jesli dojechalismy do konca, to tablica posortowana
					return;
				}
			}
		}
	}
}

void insertionSort(int tab[], unsigned int size) {
	int temp;
	for (int i = 0; i < size; i++) {
		temp = tab[i];
		int j = i - 1;
		while (j >= 0 && temp < tab[j]) {
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = temp;
	}
}

void insertionSort2(int tab[], unsigned int size) {
	int temp;

	int min = 0;
	for (int i = 1; i < size; i++) {
		if (tab[i] < tab[min]) {
			min = i;
		}
	}
	std::swap(tab[0], tab[min]);

	for (int i = 0; i < size; i++) {
		temp = tab[i];
		int j = i - 1;
		while (temp < tab[j]) {
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = temp;
	}
}

int main()
{
	int tab[rozm];

	srand(time(0));

	for (int i = 0; i < rozm; i++) tab[i] = rand() % 1000;
	for (int i = 0; i < rozm; i++) cout << tab[i] << ", ";

	std::cout << "\nSelection sort\n";
	selectionSort(tab, rozm);
	for (int i = 0; i < rozm; i++) cout << tab[i] << ", ";

	for (int i = 0; i < rozm; i++) tab[i] = rand() % 1000;
	for (int i = 0; i < rozm; i++) cout << tab[i] << ", ";
	std::cout << "\nBubble sort\n";
	bubbleSort(tab, rozm);
	for (int i = 0; i < rozm; i++) cout << tab[i] << ", ";

	for (int i = 0; i < rozm; i++) tab[i] = rand() % 1000;
	for (int i = 0; i < rozm; i++) cout << tab[i] << ", ";
	std::cout << "\nInsertion sort\n";
	insertionSort(tab, rozm);
	for (int i = 0; i < rozm; i++) cout << tab[i] << ", ";

	for (int i = 0; i < rozm; i++) tab[i] = rand() % 1000;
	for (int i = 0; i < rozm; i++) cout << tab[i] << ", ";
	std::cout << "\nInsertion sort 2\n";
	insertionSort2(tab, rozm);
	for (int i = 0; i < rozm; i++) cout << tab[i] << ", ";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
