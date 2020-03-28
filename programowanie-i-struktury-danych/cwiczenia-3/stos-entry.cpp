/*
Biblioteki, struktury - cd. Stosy.

    Napisać bibliotekę implementującą stosy liczb całkowitych o ograniczonym rozmiarze, tj. udostępniającą:
        typ Stos (typ strukturalny, przechowujący tablicę liczb całkowitych o rozmiarze odpowiadającym maksymalnemu rozmiarowi stosu, liczbę pamiętającą maksymalny rozmiar oraz indeks elementu będącego aktualnym wierzchołkiem stosu),
        konstruktor stosu przyjmujący jako parametr maksymalny rozmiar tworzonego stosu,
        destruktor stosu,
        funkcję wypisującą zawartość stosu,
        funkcję wkładającą element na stos, zgłaszającą wyjątek jeśli włożenie elementu nie jest możliwe (stos jest pełny),
        funkcję zdejmującą element ze stosu, zwracającą zdjętą wartość oraz zgłaszającą wyjątek jeśli zdjęcie elementu nie jest możliwe (stos jest pusty),
        funkcję czyszczącą stos,
        funkcję zwracającą aktualny rozmiar stosu 
    oraz program testujący działanie biblioteki.
    Wykorzystać powyższą bibliotekę do napisania programu obliczającego wartość wyrażenia zapisanego w odwrotnej notacji polskiej. 
*/

#include "stos.hpp"
#include <iostream>


int main() {
    // stack testing
    
    Stack my_stack(7);

    // testing Pop exception
    try {
        my_stack.Pop();
    } catch (std::exception e) {
        e.what();
        std::cout << "Stack is empty, you silly" << std::endl;
    }

    // testing Push and Output
    my_stack.Push(1);
    my_stack.Push(7);
    my_stack.Output();

    // testing Pop return and size reduction
    int popped = my_stack.Pop();
    std::cout << "This was on top of the stack, but it's not anymore: " << popped << std::endl;
    my_stack.Output();

    // testing Push exception
    my_stack.Push(2);
    my_stack.Push(3);
    my_stack.Push(4);
    my_stack.Push(5);
    my_stack.Push(6);
    my_stack.Push(7);

    try {
        my_stack.Push(8);
    } catch (std::exception e) {
        e.what();
        std::cout << "Stack is full, you rascal.";
    }

    return 0;
}