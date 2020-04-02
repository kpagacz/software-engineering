#ifndef __QUEUE
#define __QUEUE

#include <iostream>
#include <stdexcept>


#include "queue.hpp"

// NODE
bool operator==(const Node& lhs, const Node& rhs) {
    return lhs._next_node == rhs._next_node;
}

bool operator!=(const Node& lhs, const Node& rhs) {
    return lhs._next_node != rhs._next_node;
}

// QUEUE
// CONSTRUCTORS DESTRUCTORS ASSIGNMENT
Queue::~Queue() {
    Node* it = _head;
    Node* destructor = it;
    while (it != nullptr) {
        destructor = it;
        it = it->_next_node;
        delete [] destructor;
    }
}

Queue::Queue(Queue& other_queue) {
    Node* it_other_queue  = other_queue._head;
    while(it_other_queue != nullptr) {
        enqueue(it_other_queue->_value);
        it_other_queue = it_other_queue->_next_node;
    }
}

Queue& Queue::operator=(Queue& other_queue) {
    if (*this == other_queue) {
        return *this;
    } else {
        clear();
        Node* it_other_queue = other_queue._head;
        while(it_other_queue != nullptr) {
            enqueue(it_other_queue->_value);
        }
        return *this;
    }
}

Queue::Queue(Queue&& r_value_queue) {
    _size = r_value_queue._size;
    _head = r_value_queue._head;
    _tail = r_value_queue._tail;

    r_value_queue._head = nullptr;
    r_value_queue._tail = nullptr;
}

Queue& Queue::operator=(Queue&& r_value_queue) {
    clear();
    _size = r_value_queue._size;
    _head = r_value_queue._head;
    _tail = r_value_queue._tail;

    r_value_queue._head = nullptr;
    r_value_queue._tail = nullptr;
    
    return *this;
}

// SETTERS GETTERS
std::size_t Queue::size() const {
    return _size;
}

// OPERATORS
bool operator==(const Queue& lhs, const Queue& rhs) {
    bool equal = true;
    if (lhs._size != rhs._size) {
        equal = false;
    } else {
        Node* it_lhs = lhs._head;
        Node* it_rhs = rhs._head;
        while(it_lhs != nullptr) {
            if(it_lhs->_value != it_rhs->_value) {
                equal = false;
                break;
            }
            it_lhs = it_lhs->_next_node;
            it_rhs = it_rhs->_next_node;
        }
    }

    return equal;
}


// QUEUE DEQUEUE ELEMENTS
void Queue::enqueue(const int& value) {
    Node* new_node = new Node(value);
    if (_head == nullptr) {
        _head = new_node;
        _tail = new_node;
    } else {
        _tail->_next_node = new_node;
        _tail = new_node;
    }
    _size ++;
}

int Queue::dequeue() {
    // case: queue is empty
    if (_head == nullptr) {
        throw std::out_of_range("Queue is empty. No food for nom nom.\n");
    }

    // case: queue has 1 element (_head and _tail point to the same node)
    int return_value;
    if(*_head == *_tail) {
        Node* destructor = _head;
        return_value = _head->_value;
        delete destructor; // free memory
        
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    } else {
    // case: queue has more than 1 element
        Node* destructor = _head;
        return_value = _head->_value;
        _head = _head->_next_node;
        delete destructor;
        _size--;
    }

    return return_value;
}

// OTHER
void Queue::print() const {
    Node* iterator = _head;
    while(iterator != nullptr) {
        std::cout << iterator->_value << " ";
        iterator = iterator->_next_node;
    }
    std::cout << std::endl;
}

void Queue::clear() {
    Node* it = _head;
    Node* destructor = it;
    while (it != nullptr) {
        destructor = it;
        it = it->_next_node;
        delete [] destructor;
    }

    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

#endif