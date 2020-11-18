#include <iostream>

// POWER functions
int power_rec(unsigned int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return power_rec(n - 1) * n;
    }
}

int power_it(unsigned int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

// FIBONACCI sequence
int fib_rec(unsigned int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return fib_rec(n - 1) + fib_rec(n - 2);
    }
}

int fib_it(unsigned int n) {
    int prev = 0, prev2, curr = 1;

    for (int i = 1; i < n; i++) {
        prev2 = prev;
        prev = curr;
        curr = prev2 + prev;
    }

    return curr;
}

// FLOODFILL
void flood_fill(int tab[80][24], int x, int y, int new_color, int old_color) {
    if (x >= 80 || x < 0) {
        return;
    }
    if (y >= 24 || y < 0) {
        return;
    }
    
    if (tab[x][y] != old_color) {
        return;
    }

    if (tab[x][y] == new_color) {
        return;
    } else {
        old_color = tab[x][y];
        tab[x][y] = new_color;
        flood_fill(tab, x - 1, y, new_color, old_color);
        flood_fill(tab, x + 1, y, new_color, old_color);
        flood_fill(tab, x, y + 1, new_color, old_color);
        flood_fill(tab, x, y - 1, new_color, old_color);
    }
}

// HANOI TOWER
void hanoi(int number, int source, int destination, int supplementary) {
    if(number == 0) return;
    hanoi(number - 1, source, supplementary, destination);
    std::cout << source << "->" << destination << "\n";
    hanoi(number - 1, supplementary, destination, source);
}

int main()
{
    std::cout << "SILNIA:\n";
    int n = 0;
    std::cout << power_rec(n) << "\n";
    std::cout << power_it(n) << "\n";


    std::cout << "FIBONACCI:\n";
    int k = 4;
    std::cout << fib_rec(k) << " " << fib_it(k) << std::endl;


    std::cout << "FLODD FILL\n";
    int tab[80][24];
    for (int i = 0; i < 80; i++)
        for (int j = 0; j < 24; j++)
            if ((abs(j - 4) + abs(i - 6) < 7)
                || (abs(j - 12) < 5 && abs(i - 16) < 3)
                || ((i - 45) * (i - 45) + (j - 10) * (j - 10) < 20)
                || ((i - 36) * (i - 36) + (j - 12) * (j - 12) < 20)
                ) tab[i][j] = 1;
            else tab[i][j] = 0;


    for (int j = 0; j < 24; j++)
    {
        for (int i = 0; i < 60; i++) std::cout << tab[i][j];
        std::cout << std::endl;
    }

    flood_fill(tab, 45, 10, 3, tab[45][10]);

    for (int j = 0; j < 24; j++)
    {
        for (int i = 0; i < 60; i++) std::cout << tab[i][j];
        std::cout << std::endl;
    }


    std::cout << "HANOI TOWER\n";
    hanoi(3, 1, 2, 3);
    return 0;
}

