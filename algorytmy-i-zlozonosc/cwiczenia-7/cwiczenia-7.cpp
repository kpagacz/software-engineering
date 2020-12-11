#include<iostream>
#include<time.h>

using namespace std;

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
    // dodatkowy wskaxnik temp na pocz¹tek listy
    // przestawiamy h
    // musimy jeszcze wydobyæ tê liczbê z
    // wagonika, wagonik zwolniæ (delete)
    // a liczbê zwróciæ

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
    node** Buckets = new node*[IleKubelkow];
    for (int i = 0; i < IleKubelkow; i++) Buckets[i] = nullptr;

    // przebiegnę wzdłuż tablicy t i porozrzucam śrubki do kubełków
    // do kubełka nr 0 liczby mniejsze niż 100
    // do kubełka nr 1 liczby [100, 199]
    // do kubełka nr 2 liczby [200, 299] itd
    for (int i = 0; i < rozm; i++) {
        Push(Buckets[t[i] / (zakres / IleKubelkow)], t[i]);
    }
    // przebiegnę wdłuż kubełków i wyrzucę ich zawartośc z powrotem do tablicy
    int counter = 0;
    for (int i = 0; i < IleKubelkow; i++) {
        while (Buckets[i] != nullptr) t[counter++] = Pull(Buckets[i]);
    }

    // wygładzę tablicę insert sortem
    InsertSort(t, rozm);
}

int main()
{
    int rozm = 80000;
    // int tab[rozm];
    int* tab = new int[rozm];
    // srand(time(0));
    for (int i = 0; i < rozm; i++)
        tab[i] = rand() % 1000;


    if (rozm < 110) for (int i = 0; i < rozm; i++) cout << tab[i] << ", ";

    int t1 = time(0);
    // InsertSort(tab,rozm);
    BucketSort(tab,rozm, 1000, 100);
    int t2 = time(0);

    cout << endl << "Procedura trwala " << t2 - t1 << " sekund";
    cout << endl << endl;

    if (rozm < 110) for (int i = 0; i < rozm; i++) cout << tab[i] << ", ";

    return 0;
}
