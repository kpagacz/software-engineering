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