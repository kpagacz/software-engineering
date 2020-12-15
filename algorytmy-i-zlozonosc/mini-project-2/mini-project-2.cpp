#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
#include <random>
#include <vector>
#include <stdlib.h>

using namespace std;

std::random_device rd;
std::mt19937 gen(rd());

struct node
{
    int num; //zawartosc
    node* next;  // wskaznik na nastepny
};

void Push(node*& h, int k)
{
    node* temp = new node;
    temp->num = k;
    temp->next = h;
    h = temp;
}

int Pull(node*& h)
{
    node* temp = h;
    h = h->next;
    int wynik = temp->num;
    delete temp;
    return wynik;
}

void InsertSort(int tablica[], int rozmiar)
{
    for (int i = 1; i < rozmiar; i++)
    {
        int temp = tablica[i];
        int j = i - 1;
        while (j >= 0 && tablica[j] > temp)
        {
            tablica[j + 1] = tablica[j];
            j--;
        }
        tablica[j + 1] = temp;
    }
}

void BucketSort(int t[], int rozm, int zakres, int IleKubelkow)
{
    node **Buckets = new node*[IleKubelkow];
	for(int i = 0; i < IleKubelkow; i++) Buckets[i] = nullptr;

    for (int i = 0; i < rozm; i++) Push(Buckets[t[i] / (zakres / IleKubelkow)], t[i]);
    int counter = 0;
    for (int i = 0; i < IleKubelkow; i++) while(Buckets[i] != nullptr) t[counter++] = Pull(Buckets[i]);
    InsertSort(t, rozm);

	for(int i = 0; i < IleKubelkow; i++) delete Buckets[i];
	delete [] Buckets;
}

void RunExperiment(int rozm, int zakres, int IleKubelkow, std::string plik_out) {
	int *t = new int[rozm];
	std::uniform_int_distribution<int> distribution (0, zakres);
	for(int i = 0; i < rozm; i++) t[i] = distribution(gen);

	std::clock_t start = clock();
	BucketSort(t, rozm, zakres, IleKubelkow);
	std::clock_t end = clock();
	double czas = 1000.0 * (double(end) - double(start)) / CLOCKS_PER_SEC;

	std::fstream wyjscie;
	wyjscie.open(plik_out, std::ios::app);
	wyjscie << IleKubelkow << "," << std::fixed << std::setprecision(3) << czas / 1000 << "\n";
	wyjscie.close();
	std::cout << "Done: " << IleKubelkow << "\n";
	delete [] t;
}

int main() {
	int size = 12000;
	int zakres = 1000;

	std::string nazwa_pliku = "time-results.csv";
	std::ofstream wyniki;
	wyniki.open(nazwa_pliku);
	wyniki << "Liczba kubelkow," << "Czas sortowania\n";
	wyniki.close();

	std::uniform_int_distribution<int> dist(0, zakres);
	int* arr = new int[size];
	for(int i = 0; i < size; i++) arr[i] = dist(gen);

	if(size < 200) {
		for(int i = 0; i < size; i++) std::cout << arr[i] << " ";
		std::cout << "\n";
	}
	for(int i = 1; i < zakres; i++) for(int j = 0; j < 5; j++) RunExperiment(size, zakres, i, nazwa_pliku);
	if(size < 200) for(int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
		std::cout << "\n";
	}

	delete [] arr;
	return 0;
}