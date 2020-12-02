#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;


int Partition(int tab[], int start, int stop)
{
	// Ulepszenie: losuj pivot
	srand(time(NULL));
	int random_pivot = rand() % (stop - start + 1) + start;
	std::swap(tab[stop], tab[random_pivot]);

	int j = start;
	for (int i = start; i < stop; i++) {
		if (tab[i] < tab[stop]) std::swap(tab[i], tab[j++]);
	}
	std::swap(tab[j], tab[stop]);
	return j;
}

void QSort(int tab[], int start, int stop) {
	if (start >= stop) return;
	int pivot = Partition(tab, start, stop);
	QSort(tab, start, pivot - 1);
	QSort(tab, pivot + 1, stop);
}



int main()
{


	int t[15];
	for (int i = 0; i < 15; i++) t[i] = 10 + rand() % 90;
	for (int i = 0; i < 15; i++) cout << t[i] << ", ";

	cout << endl;
	for (int i = 0; i < 14; i++) cout << "    ";
	cout << "^" << endl;

	QSort(t, 0, 14);

	for (int i = 0; i < 15; i++) cout << t[i] << ", ";
	cout << endl;
	return 0;

}