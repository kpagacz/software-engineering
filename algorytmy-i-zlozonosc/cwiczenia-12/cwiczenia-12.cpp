#include <iostream>
using namespace std;
const int rozm = 100;


int heap[rozm];
int ile = -1;


int p(int x)
{
    return (x + 1) / 2 - 1;
}

int l(int x)
{
    return 2 * (x + 1) - 1;
}

int r(int x)
{
    return 2 * (x + 1);
}


void FixFromBelow(int heap[], int ile)
{
    int ktory = ile;
    while (heap[ktory] > heap[p(ktory)] && ktory > 0)
    {
        swap(heap[ktory], heap[p(ktory)]);
        ktory = p(ktory);
    }
}

void FixFromAbove(int heap[], int ile)
{
    int idx = 0;
    while (true)
    {
        int naj = idx;
        if (l(idx) <= ile && heap[naj] < heap[l(idx)]) naj = l(idx);
        if (r(idx) <= ile && heap[naj] < heap[r(idx)]) naj = r(idx);
        // ustali³em, kto jest naj
        if (idx == naj) break;
        swap(heap[idx], heap[naj]); idx = naj;
    }
}


void Add(int heap[], int& ile, int num)
{
    ile++;
    heap[ile] = num;
    FixFromBelow(heap, ile);
}


int Get(int heap[], int& ile)
{
    swap(heap[0], heap[ile]);
    ile--;
    FixFromAbove(heap, ile);
    return heap[ile + 1];
}






void heapsort(int tab[], int rozmiar)

{
    int ile = 0;
    // z tablicy robiê kopiec;
    for (int i = 1; i < rozmiar; i++) {
        ile++;
        FixFromBelow(tab, ile);
     }
     // z kopca tablicê posortowan¹
    for(int i=1; i<rozm; i++) Get(tab, ile);
}


int main()
{
    int ile = 0;

    int arr[5] = { 10, 8, 4, 7, 3 };
    heapsort(arr, 5);
    for (int i = 0; i < 5; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    return 1;

}