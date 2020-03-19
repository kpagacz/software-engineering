#ifndef __STOS
#define __STOS

#include <iostream>
#include <stdexcept>

#include "stos.hpp"

Stack::Stack(const int& size) {
    max_size = size;
    _stack = new int[max_size];
    current_size = 0;
}

Stack::~Stack() {
    delete [] _stack;
}

void Stack::Output() const {
    std::cout << "Stack: ";
    for (int i = 0; i < current_size; i++) {
        std::cout << _stack[i] << " ";
    }
    std::cout << std::endl;
}

void Stack::Push(const int& element) {
    if (current_size >= max_size) {
        throw std::range_error("Max size reached.");
    } else {
        _stack[current_size++] = element;
    }
}

int Stack::Pop() {
    if (current_size <= 0) {
        throw std::range_error("Stack is empty.");
    } else {
        return _stack[--current_size];
    }
}

void Stack::Clear() {
    current_size = 0;
}

int Stack::Size() const {
    return current_size;
}

#endif