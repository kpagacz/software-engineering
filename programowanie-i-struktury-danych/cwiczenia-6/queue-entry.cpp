#include <iostream>

#include "queue.hpp"

int main() {
    std::cout << "Queue test" << std::endl;

    // default constructor
    Queue test_queue;
    
    // enqueue, print 
    test_queue.enqueue(1);
    test_queue.enqueue(2);

    std::cout << "Should print 1,2: ";
    test_queue.print();
    std::cout << std::endl;

    // size

    std::cout << "Should print 2: " << test_queue.size() << std::endl;

    // clear
    test_queue.clear();
    std::cout << "Should print nothing: ";
    test_queue.print();
    std::cout << "Should print 0: " << test_queue.size() << std::endl;

    // dequeue exception
    std::cout << "Should catch an exception: " << std::endl;
    try {
        test_queue.dequeue();
    } catch (const std::exception& e) {
        std::cout << e.what();
    }

    // dequeue
    test_queue.enqueue(7);
    test_queue.enqueue(8);
    std::cout << "Should print nothing 7,8: ";
    test_queue.print();
    int int1 = test_queue.dequeue();
    int int2 = test_queue.dequeue();
    std::cout << "First out: " << int1 << " " << "Second out: " << int2 << std::endl;
    test_queue.print();
    test_queue.size();

    Queue test_queue2;
    test_queue2.enqueue(7);
    test_queue2.enqueue(8);
    test_queue.enqueue(7);
    test_queue.enqueue(8);

    bool equal = test_queue == test_queue2;
    std::cout << "Operator == test. Should print 1: " << equal << std::endl;  

    // copy assignment
    test_queue = test_queue;
    std::cout << "Self copy assignment test. Should print 7 8: ";
    test_queue.print();
    return 0;
}