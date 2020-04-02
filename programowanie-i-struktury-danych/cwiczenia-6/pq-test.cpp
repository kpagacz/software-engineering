#include <iostream>

#include "process_queue.hpp"

int main() {
    ProcessQueue test_queue1;
    test_queue1.addProcess(7);
    test_queue1.print();
    test_queue1.addProcess(8, 7);
    test_queue1.print();
    test_queue1.addProcess(7, 2);
    test_queue1.print();

    test_queue1.addProcess(11);
    test_queue1.addProcess(11, 1);

    test_queue1.addProcess(13);

    try {
        test_queue1.prioritizeProcess(1);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    test_queue1.print();
    test_queue1.prioritizeProcess(13);
    test_queue1.print();
    test_queue1.prioritizeProcess(13);
    test_queue1.print();
    test_queue1.prioritizeProcess(8);
    test_queue1.print();

    return 0;
}