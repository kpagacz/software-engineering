// Napisać funkcje rekurencyjne wyznaczające największy wspólny 
// dzielnik dwóch liczb całkowitych podanych jako parametry za pomocą algorytmu Euklidesa:

//     niezoptymalizowanego (wybieramy większą z dwóch liczb i zamieniamy ją na różnicę 
//     większej i mniejszej; czynność tę powtarzamy do momentu uzyskania dwóch takich samych wartości; uzyskana wartość to NWD)
//     zoptymalizowanego (NWD liczb A i B wyznaczamy powtarzając czynności: 
//     zastąpienie liczby A liczbą B, a liczby B resztą z dzielenia A przez B; czynności 
//     powtarzamy do uzyskania przez B wartości 0, A jest wówczas największym wspólnym dzielnikiem). 

#include <iostream>

int unoptimized_lcd(int a, int b);
int optimized_lcd(int a, int b);

int main() {
    // input
    std::cout << "Input two integers: ";
    int a, b;
    std::cin >> a >> b;
    std::cout << "Largest common denominator (unoptimized): " << unoptimized_lcd(a, b) << ". Largest common denominator (optimized): " << optimized_lcd(a, b);
    
    return 0;
}


int unoptimized_lcd(int a, int b) {
    if (a == b) {
        return a;
    }

    if (a > b) {
        unoptimized_lcd(a - b, b);
    } else {
        unoptimized_lcd(a, b - a);
    }
}

int optimized_lcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    optimized_lcd(b, a % b);
}