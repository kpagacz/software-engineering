/*
Biblioteki, struktury - cd. Kolejki.

    Napisać bibliotekę implementującą kolejki liczb całkowitych o zmiennym rozmiarze, tj. udostępniającą:
        typ Kolejka (typ strukturalny, przechowujący dynamiczną tablicę liczb całkowitych o rozmiarze odpowiadającym bieżącemu rozmiarowi kolejki oraz liczbę pamiętającą obecny rozmiar,
        konstruktor kolejki (bezparametrowy),
        destruktor kolejki,
        funkcję wypisującą zawartość kolejki,
        funkcję wstawiającą element do kolejki, zgłaszającą wyjątek jeśli wstawienie elementu nie jest możliwe (brak pamięci),
        funkcję usuwającą element z kolejki, zwracającą usuniętą wartość oraz zgłaszającą wyjątek jeśli usunięcie elementu nie jest możliwe (kolejka jest pusta),
        funkcję czyszczącą kolejkę,
        funkcję zwracającą aktualny rozmiar kolejki 
    oraz program testujący działanie biblioteki. 
*/


#include <iostream>
#include <stdexcept>

#include "queue.hpp"

int main() {
    Queue my_queue;

    // testing dequeue exception
    try {
        my_queue.Dequeue();
    } catch (std::exception e) {
        std::cout << "Queue is empty, you silly." << std::endl;
    }

    // testing adding and output
    my_queue.Enqueue(1);
    my_queue.Output();

    // testing queue, dequeue
    my_queue.Enqueue(2);
    my_queue.Dequeue();
    my_queue.Enqueue(3);
    my_queue.Output(); // should output 2, 3

    // queue capacity
    my_queue.Enqueue(4);
    my_queue.Enqueue(5);
    my_queue.Enqueue(6);
    my_queue.Enqueue(7);
    my_queue.Output();


    return 0;
}