#include <math.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

/* Zrobilem tylko do 14, poniewaz dla wiekszych n ponizszy algorytm
wykonuje sie zbyt dlugo na moj biedny komputer.
Musialbym zmienic podejscie, zeby moc "dobic" do 20.
*/

void StepBack(int* stan, int& col, const int& size);

void Print(int* stan, const int& size, int& licznik2)
{
    std::cout << ++licznik2 << "-----";
    for (int i = 0; i < size; i++)
        std::cout << stan[i] << " ";
    std::cout << "\n";
}

int LastNonzeroColumn(int* stan, const int& size)
{
    int i = size - 1;
    while (stan[i] == -1) i--;
    return i;
}

void NextColumn(int* stan, const int& col)
{
    stan[col + 1] = 0;
}

void NextStep(int* stan, int &col, const int& size)
{
    if (col != -1) stan[col]++;
    if (stan[col] == size) StepBack(stan, col, size);
}

void StepBack(int* stan, int& col, const int& size)
{
    stan[col] = -1;
    col--;
    NextStep(stan, col, size);
}


bool Test(int* stan, const int& col, int& licznik)
{
    licznik++;
    for (int i = col - 1; i >= 0; i--)
        if (
            (stan[i] == stan[col]) ||
            (stan[i] == stan[col] - col + i) ||
            (stan[i] == stan[col] - i + col)
            ) return false;
    return true;
}

int ProblemHetmanow(const int& board_size) {
    int* stan = new int[board_size];
    memset(stan, -1, sizeof(int) * board_size);

    int licznik = 0, licznik2 = 0;

    stan[0] = 0;
    while (stan[0] != -1)
    {
        int c = LastNonzeroColumn(stan, board_size);
        if (Test(stan, c, licznik))
        {
            if (c == board_size - 1)
            {
                //Print(stan, board_size, licznik2);
                ++licznik2;
                NextStep(stan, c, board_size);
            }
            else
            {
                NextColumn(stan, c);
            }
        }
        else
        {
            NextStep(stan, c, board_size);
        }

    }

    delete[] stan;
    return licznik2;
}


int main()
{
    std::string filename = "rezultaty.txt";
    std::ofstream out;
    out.open(filename, std::ios::out);
    for (int i = 1; i < 15; i++) {
        int liczba_rozwiazan = ProblemHetmanow(i);
        out << "Liczba hetmanow: " << i << "Plansza: " << i << "x" << i << " Rozwiazania: " << liczba_rozwiazan << "\n";
        std::cout << "X";
    }
    out.close();

    return 0;
}