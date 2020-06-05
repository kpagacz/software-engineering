#include<iostream>

#include "rope.hpp"

int main() {
    // task 1
    std::cout << "Task 1" << std::endl;
    std::cout << "Testing push and printing: " << std::endl;
    Rope<int> rope1;
    rope1.push(1);
    rope1.push(5);
    rope1.push(6);
    rope1.push(1);
    rope1.push(3);
    rope1.push(7);
    rope1.push(2);
    rope1.push(7);
    rope1.push(3);
    rope1.push(1);
    rope1.push(3);
    rope1.push(1);
    std::cout << rope1;

    int S, K;
    std::cout << "Input S and K" << std::endl;
    std::cin >> S >> K;
    rope1.removeSeqs(S, K);
    std::cout << rope1;

    // task 2
    std::cout << "Task 2: " << std::endl;


    // task 3
    std::cout << "Task 3: " << std::endl;
    return 0;
}