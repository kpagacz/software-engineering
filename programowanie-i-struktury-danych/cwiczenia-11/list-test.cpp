#include "list.h"
#include<iostream>

int main() {
    SortedList<int> list;
    list.push(1);
    list.push(2);
    list.push(5);
    std::cout << "Pushed 5";
    list.push(4);
    std::cout << "Pushed 4" << std::endl;
    list.push(6);
    std::cout << list;
    return 0;
}