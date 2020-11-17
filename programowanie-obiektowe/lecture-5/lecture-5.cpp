#include <iostream>
#include"FifoQueue.h"

int main()
{
    FifoQueue<int> q1;
    q1.push(7);
    q1.push(8);
    q1.push(9);
    std::cout << q1;

    q1.pop();
    std::cout << q1;

    std::cout << "Testing copy constructor:\n";
    FifoQueue<int> q2(q1);
    std::cout << q2;
    q1.push(111);
    std::cout << "q1: " << q1 << "q2: " << q2;

    std::cout << "Testing assignment operator\n";
    FifoQueue<int> q3;
    q3 = q1;
    q3.push(128);
    std::cout << "q3: " << q3 << "q1: " << q1;


    return 0;
}