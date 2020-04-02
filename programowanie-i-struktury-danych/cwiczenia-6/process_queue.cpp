#ifndef __PROCESS_QUEUE
#define __PROCESS_QUEUE

#include <iostream>
#include <stdexcept>
#include <iomanip>

#include "process_queue.hpp"

// PROCESS
bool operator==(const Process& lhs, const Process& rhs) {
    return lhs._PID == rhs._PID;
}

bool operator!=(const Process& lhs, const Process& rhs) {
    return lhs._PID != rhs._PID;
}

// NODE
bool operator==(const Node& lhs, const Node& rhs) {
    // i see some problems with it. it would return true, if ending nodes
    // from two different queues were compared == and the nodes would have the 
    // same process PID. But in my code it is not a problem, because I never
    // compare nodes from different queues. I currently have no idea, how
    // to resolve this.
    return (lhs._next_node == rhs._next_node) && (lhs._process == rhs._process);
}
bool operator!=(const Node& lhs, const Node& rhs) {
    return !(lhs == rhs);
}

// PROCESS QUEUE
ProcessQueue::~ProcessQueue() {
    Node* it = _head;
    Node* destructor;
    while(it != nullptr){
        destructor = it;
        it = it->_next_node;
        delete destructor;
    }
}

void ProcessQueue::print() const {
    Node* it = _head;
    unsigned int cell_width = 10;
    std::cout << std::setw(cell_width) << "PID" << std::setw(cell_width) << "Threads" << std::endl;
    while(it != nullptr) {
        std::cout << std::setw(cell_width) << it->_process._PID << std::setw(cell_width) << it->_process._threads << std::endl;
        it = it->_next_node;
    }
}

Node* ProcessQueue::findProcess(const unsigned int& PID) const {
    Node* it = _head;
    Node* found_process = nullptr;
    while(it != nullptr) {
        if(it->_process._PID == PID) {
            found_process = it;
            break;
        }
        it = it->_next_node;
    }

    return found_process;
}

void ProcessQueue::addProcess(const unsigned int& PID, const unsigned int& threads) {
    Node* found_process = findProcess(PID);
    if(found_process == nullptr) {
        if(_size == 0) {
            Process new_process(PID);
            _head = new Node(new_process);
            _tail = _head;
            _size++;
        } else {
            Process new_proces(PID);
            Node* new_node = new Node(new_proces);

            _tail->_next_node = new_node;
            _tail = new_node;

            _size++;
        }
    } else {
        found_process->_process._threads += threads;
    }
}

void ProcessQueue::prioritizeProcess(const unsigned int& PID) {
    Node* process_to_move = findProcess(PID);

    // case: process not in a queue
    if (process_to_move == nullptr) {
        throw std::out_of_range("Process not in a ProcessQueue.");
    }

    // case: process is at the front of the queue
    if(process_to_move == _head) {
        return;
    }

    // find predecessing node
    Node* pre_to_move = _head;
    while(pre_to_move->_next_node != process_to_move) {
        pre_to_move = pre_to_move->_next_node;
    }

    // case: process is in the back
    if(process_to_move == _tail) {
        process_to_move->_next_node = _head;
        pre_to_move->_next_node = nullptr;

        _head = process_to_move;
        _tail = pre_to_move;
        return;
    }

    // case: process is in the middle
    if(process_to_move != _head && process_to_move != _tail) {
        pre_to_move->_next_node = process_to_move->_next_node;
        process_to_move->_next_node = _head;

        _head = process_to_move;
        return;
    }
}


#endif