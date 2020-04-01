#ifndef _UNBOUNDED_STACK
#define _UNBOUNDED_STACK


#include <iostream>
#include <stdexcept>

#include "stack-unbounded.hpp"

// StackElement - copy constructor
StackElement::StackElement(StackElement& copied_element) {
    value = copied_element.value;
    next = new StackElement(*(copied_element.next));
}

// Stack - destructor
Stack::~Stack() {
    std::cout << "Destructor called." << std::endl;
    StackElement* iterator = first_element;
    while(iterator != nullptr) {
        StackElement* killer = iterator;
        iterator = iterator->next;
        delete [] killer;
    }
    first_element = nullptr;
}

// Stack - copy constructor
Stack::Stack(Stack& copied_stack) {
    std::cout << "Copy constructor called." << std::endl;
    // return *this, if the rhs stack is empty
    if(copied_stack.first_element == nullptr) {
        return;
    }

    // copy first element 
    first_element = new StackElement;
    *first_element = *copied_stack.first_element;

    // then deep copy each stack element from the rhs stack
    StackElement* this_iterator = first_element;
    StackElement* rhs_iterator = copied_stack.first_element;

    while(rhs_iterator->next != nullptr) {
        this_iterator->next = new StackElement;
        *(this_iterator->next) = *(rhs_iterator->next);
        rhs_iterator = rhs_iterator->next;
        this_iterator = this_iterator->next;     
    }
}

// Stack - move constructor
Stack::Stack(Stack&& moved_stack) {
    std::cout << "Move constructor called." << std::endl;

    // end if the moved stack is empty
    if(moved_stack.first_element == nullptr) {
        first_element = nullptr;
        return;
    }

    first_element = moved_stack.first_element;
    moved_stack.first_element = nullptr;

}

// Stack - copy assignment
Stack& Stack::operator=(Stack& rhs_stack) {
    std::cout << "Assigning from lvalue" << std::endl;
    // first, deallcoate current stack
    clear();

    // return *this, if the rhs stack is empty
    if(rhs_stack.first_element == nullptr) {
        return *this;
    }

    // copy first element 
    first_element = new StackElement;
    *first_element = *rhs_stack.first_element;

    // then deep copy each stack element from the rhs stack
    StackElement* this_iterator = first_element;
    StackElement* rhs_iterator = rhs_stack.first_element;

    while(rhs_iterator->next != nullptr) {
        this_iterator->next = new StackElement;
        *(this_iterator->next) = *(rhs_iterator->next);
        rhs_iterator = rhs_iterator->next;
        this_iterator = this_iterator->next;   
    }

    return *this;
}

// Stack - move assigment
Stack& Stack::operator=(Stack&& rhs_stack) {
    std::cout << "Assigning from rvalue" << std::endl;

    clear();

    first_element = rhs_stack.first_element;
    rhs_stack.first_element = nullptr;
    
    return *this;
}

// == operator overload
bool operator==(Stack& lhs, Stack& rhs) {
    StackElement* lhs_iterator = lhs.first_element;
    StackElement* rhs_iterator = rhs.first_element;

    if (lhs.size() != rhs.size()) {
        return false;
    }

    bool equal = true;

    while (lhs_iterator != nullptr) {
        if (lhs_iterator->value != rhs_iterator->value) {
            equal = false;
            break;
        }

        lhs_iterator = lhs_iterator->next;
        rhs_iterator = rhs_iterator->next;
    }

    return equal;
}

// Stack - print
void Stack::print() {
    StackElement* iterator = first_element;

    while(iterator != nullptr) {
        std::cout << iterator->value << " ";
        iterator = iterator->next;
    }

    std::cout << std::endl;
}

// Stack - push
void Stack::push(const int& new_value) {
    StackElement* new_first = new StackElement;

    new_first->value = new_value;
    new_first->next = first_element;
    
    first_element = new_first;
}

// Stack - pop
int Stack::pop() {
    if (first_element == nullptr) {
        throw std::runtime_error("Stack is empty");
    } else {
        StackElement* killer = first_element;
        int first_value = first_element->value;
        first_element = first_element->next;
        delete [] killer;
        return first_value;
    }
}

// Stack - size
int Stack::size() {
    int size = 0;
    StackElement* iterator = first_element;
    while(iterator != nullptr) {
        iterator = iterator->next;
        size += 1;
    }

    return size;
}

// Stack - clear
void Stack::clear() {
    StackElement* iterator = first_element;
    while(iterator != nullptr) {
        StackElement* killer = iterator;
        iterator = iterator->next;
        delete [] killer;
    }

    first_element = nullptr;
}

#endif