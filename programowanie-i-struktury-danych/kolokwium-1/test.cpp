#include<iostream>
#include "sznur.hpp"

int main() {
    // task1
    Rope rope;
    rope.push(1);
    rope.push(2);
    rope.push(1);
    rope.push(3);
    rope.push(0);
    rope.push(7);
    rope.push(10);
    std::cout << rope << "Size: " << rope.getSize() << std::endl;;

    remove(rope, 4);
    std::cout << rope;
    std::cout << "Size: " << rope.getSize() << std::endl;

    Rope rope2;
    rope2.push(2);
    rope2.push(1);
    rope2.push(2);
    std::cout << rope2;
    remove(rope2, 4);
    std::cout << rope2;

    // task2
    rope2.push(2);
    rope2.push(1);
    rope2.push(1);
    rope2.push(7);
    rope2.push(8);
    std::cout << "Moving rope2" << std::endl;
    std::cout << rope2;
    move(rope2);
    std::cout << rope2;
    Rope rope3;
    rope3.push(9);
    rope3.push(8);
    rope3.push(7);
    rope3.push(5);
    rope3.push(2);
    rope3.push(3);
    rope3.push(4);
    std::cout << "Moving rope3" << std::endl;
    std::cout << rope3;
    move(rope3);
    std::cout << rope3;

    // task3
    std::cout << "Task3" << std::endl;
    Rope rope4;
    Rope rope5;
    rope4.push(7);
    rope4.push(7);
    rope4.push(6);
    rope4.push(5);
    rope4.push(4);
    rope4.push(4);
    rope4.push(4);
    rope4.push(4);
    rope4.push(3);
    rope4.push(2);
    rope4.push(2);
    rope5.push(8);
    rope5.push(8);
    rope5.push(6);
    rope5.push(6);
    rope5.push(6);
    rope5.push(5);
    rope5.push(4);
    rope5.push(4);
    rope5.push(2);
    rope5.push(2);

    std::cout << rope4 << rope5;
    std::cout << "Exchanging those two ropes:" << std::endl;
    exchangeConstantSequences(rope4, rope5);
    std::cout << rope4;
    std::cout << rope5;
    return 0;
}