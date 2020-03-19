#ifndef MY_QUEUE
#define MY_QUEUE

#include <iostream>
#include <stdexcept>

#include "queue.hpp"

Queue::Queue() {
    max_size = 5;
    first_index = 0;
    current_size = 0;
    _queue = new int[max_size];
}
Queue::~Queue() {
    delete [] _queue;
}

void Queue::Output() const {
    std::cout << "Queue is: ";
    for (int i = 0; i < current_size; i++) {
        std::cout << _queue[(first_index + i) % max_size] << " ";
    }
    std::cout << std::endl;
}

void Queue::Enqueue(const int& element) {
    if (current_size >= max_size) {
        throw std::range_error("Queue is at max size.");
    } else {
        _queue[(first_index + current_size++) % max_size] = element;
    }
}

int Queue::Dequeue() {
    if (current_size <= 0) {
        throw std::range_error("Queue is empty.");
    } else {
        current_size--;
        return _queue[first_index++];
    }
}

void Queue::Clear() {
    first_index = 0;
    current_size = 0;
}

int Queue::Size() const {
    return current_size;
}

#endif