#include <iostream>
const int rozm = 100;


int heap[rozm];
int ile = 0;


void FixFromBelow()
{
	int ktory = ile;
	while (heap[ktory] > heap[ktory / 2] && ktory != 1)
	{
		std::swap(heap[ktory], heap[ktory / 2]);
		ktory = ktory / 2;
	}
}

void Add(int num)
{
	ile++;
	heap[ile] = num;
	FixFromBelow();
}

void FixFromAbove() {
	int it = 1;
	int max = heap[it];
	while (2 * it <= ile) {
		int id_max = it;
		if (heap[2 * it] > heap[it]) {
			id_max = 2 * it;
		}

		if (2 * it + 1 <= ile && heap[2 * it + 1] > heap[2 * it])
			id_max = 2 * it + 1;

		if (id_max == it)
			break;
		else
			std::swap(heap[it], heap[id_max]);

		it = id_max;
	}
}

int Get()
{
	std::swap(heap[1], heap[ile]);
	ile--;
	FixFromAbove();
	return heap[ile + 1];
}

void heap_sort() {
	ile = 1;
	for (int i = ile; i < rozm; i++, ile++)
		FixFromBelow();

	for (int i = 1; i < rozm; i++)
		Get();
}

int main()
{
	Add(11);
	Add(21);
	Add(11);
	Add(31);
	Add(11);
	Add(41);
	Add(13);
	Add(1);
	Add(15);
	Add(22);

	for (int i = 1; i <= ile; i++) std::cout << heap[i] << "--";
	std::cout << "\n";

	Get();
	for (int i = 1; i <= ile; i++) std::cout << heap[i] << "--";
	std::cout << "\n";

	Get();
	for (int i = 1; i <= ile; i++) std::cout << heap[i] << "--";
	std::cout << "\n";

	heap_sort();
	for (int i = 1; i <= ile; i++) std::cout << heap[i] << "--";
	std::cout << "\n";

	return 1;
}