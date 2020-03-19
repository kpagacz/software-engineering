#ifndef MY_QUEUE
#define MY_QUEUE

#include <iostream>
#include <stdexcept>

#include "queue.hpp"

// constructors and other operators
Queue::Queue() {
    max_size = 5;
    first_index = 0;
    current_size = 0;
    _queue = new int[max_size];
}
Queue::~Queue() {
    delete [] _queue;
}

Queue::Queue(const Queue& other_queue) { // copy constructor
    _queue = other_queue._queue;
    max_size = other_queue.max_size;
    first_index = other_queue.first_index;
    current_size = other_queue.current_size;
}

// other
void Queue::Output() const {
    std::cout << "Queue is: ";
    for (int i = 0; i < current_size; i++) {
        std::cout << _queue[(first_index + i) % max_size] << " ";
    }
    std::cout << std::endl;
}

void Queue::Enqueue(const int& element) {
    // queue extension
    if (current_size == max_size) {
        max_size *= 2;
        try {
            int* _new_queue = new int[max_size];
            for (int i = 0; i < current_size; i++) {
                _new_queue[i] = _queue[i];
            }
            delete [] _queue;
            _queue = _new_queue;
        } catch (std::exception e) {
            std::cout << "Out of memory" << std::endl;
        }
        first_index = 0;
    }

    // reassignment of values to index 0
    if (first_index != 0) {
        for (int i = 0; i < current_size; i++) {
            _queue[i] = _queue[first_index + i];
        }
    }
    first_index = 0;

    // assignment
    _queue[current_size++] = element;
}

int Queue::Dequeue() {
    if (current_size <= 0) {
        // throw error when the queue is empty
        // cannot dequeue from an empty queue
        throw std::range_error("Queue is empty.");
    } else {
        current_size--;

        // reduce the memory allocation when the queue size is lower than one fourth of the max_size
        if (current_size < max_size / 4) {
            max_size /= 2;
            int* _new_queue = new int[max_size];
            for (int i = 0; i < current_size; i++) {
                _new_queue[i] = _queue[i];
            }
            delete [] _queue;
            _queue = _new_queue;
        }
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