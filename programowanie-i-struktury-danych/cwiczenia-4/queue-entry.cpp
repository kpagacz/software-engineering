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
    try {
        my_queue.Enqueue(7);
        my_queue.Output();
    } catch (std::exception e) {
        std::cout << "Queue is full, you rascal." << std::endl;
    }

    return 0;
}