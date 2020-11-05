#include<iostream>
#include<time.h>

using namespace std;
const int rozm = 500000;

void SelectionSort(int tablica[], int rozmiar)
{

    for (int t = 0; t < rozmiar - 1; t++)
    {
        int mini_idx = t;
        for (int i = t + 1; i < rozmiar; i++)
            if (tablica[i] < tablica[mini_idx]) mini_idx = i;
        swap(tablica[t], tablica[mini_idx]);
    }

}

void InsertSort(int tablica[], int rozmiar)
{

    for (int t = 1; t < rozmiar; t++)
    {
        int temp = tablica[t];
        int i = t - 1;
        while ((i >= 0) && (tablica[i] > temp))
        {
            tablica[i + 1] = tablica[i];
            i--;
        }
        tablica[i + 1] = temp;
    }

}

void InsertSortStep(int tablica[], int rozmiar, int step)
{
    for (int s = 0; s < step; s++) {
        for (int t = step + s; t < rozmiar; t+=step)
        {
            int temp = tablica[t];
            int i = t - step;
            while ((i >= 0) && (tablica[i] > temp))
            {
                tablica[i + step] = tablica[i];
                i-=step;
            }
            tablica[i + step] = temp;
        }
    }

}

void InsertSortStep2(int tablica[], int rozmiar, int step)
{

    for (int t = step; t < rozmiar; t ++)
    {
        int temp = tablica[t];
        int i = t - step;
        while ((i >= 0) && (tablica[i] > temp))
        {
            tablica[i + step] = tablica[i];
            i -= step;
        }
        tablica[i + step] = temp;
    }


}

//////////////////////////////////////////////////////////////////////
/// LIST
struct Node {
    int value;
    Node* next;
    Node(int k = 0, Node* _next = nullptr) : value(k), next(_next) {}
};

void Add(Node*& head, int k) {
    Node* creator = new Node;
    creator->value = k;
    creator->next = head;
    head = creator;
}

int main()
{
    int* tab = new int[rozm];

    srand(0);

    for (int i = 0; i < rozm; i++) tab[i] = rand() % 100000;

    // for (int i = 0; i < rozm; i++) cout << tab[i] << ", ";

    cout << "*";
    int t1 = time(0);

    // sortowanie
    // InsertSortStep2(tab, rozm, 50);
    // InsertSortStep2(tab, rozm, 1);

    int t2 = time(0);

    cout << endl << "Procedura trwala " << t2 - t1 << " sekund";


    cout << endl << endl;
    // for (int i = 0; i < rozm; i++) cout << tab[i] << ", ";

    ///////////////////////
    /// LIST
    /// 
    /// Task: 

    Node* first = new Node();
    Node* last = new Node();

    first->value = 0;
    first->next = last;
    last->value = INT_MAX;
    last->next = nullptr;

    std::cout << first->value << " " << last->value;

    int no;
    while (true) {
        std::cout << "Input number: ";
        std::cin >> no;

        if (no == 0) break;

        Node* succ = first, *pred = nullptr;
        while (no >= succ->value) {
            succ = pred;
            succ = succ->next;
        }

        Node* creator = new Node(no, succ);
        pred->next = creator;
    }

    return 0;
}
