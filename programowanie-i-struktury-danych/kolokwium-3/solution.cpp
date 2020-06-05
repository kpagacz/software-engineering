#include<iostream>
#include"rope.hpp"


int main() {
    // task1
    Rope<int> rope1;
    rope1.push(7);
    rope1.push(7);
    rope1.push(6);
    rope1.push(5);
    rope1.push(3);
    rope1.push(3);
    rope1.push(3);
    rope1.push(2);
    rope1.push(1);
    rope1.push(1);
    rope1.push(1);
    rope1.push(1);
    std::cout << rope1;
    int K;
    std::cout << "Input K: ";
    // std::cin >> K;
    rope1.removePlus(K);
    std::cout << rope1;

    // task2
    std::cout << "TASK 2: " << std::endl;
    Rope<int> rope2;
    rope2.push(9);
    rope2.push(8);
    rope2.push(7);
    rope2.push(6);
    rope2.push(5);
    rope2.push(4);
    rope2.push(3);
    rope2.push(2);
    rope2.push(1);
    rope2.push(0);
    rope2.push(-1);
    std::cout << rope2;
    rope2.moveEven();
    std::cout << rope2;
    
    Rope<int> rope3;
    rope3.push(8);
    rope3.push(4);
    rope3.push(2);
    rope3.push(6);
    std::cout << rope3;
    rope3.moveEven();
    std::cout << rope3;
    return 0;
}