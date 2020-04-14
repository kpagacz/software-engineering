#include <iostream>
#include <stdexcept>
#include "sorted_list_unbounded.hpp"


List::List(const List& other) {
    List::Node* other_it = other._head;

    _head = nullptr;
    _tail = nullptr;

    while(other_it != nullptr) {
        List::Node* creator = new List::Node(other_it->_value);
        if(_tail == nullptr) {
            _head = creator;
        } else {
            _tail->_next = creator;
        }
        _tail = creator;
        other_it = other_it->_next;
    }


    _size = other._size;
}

List& List::operator=(const List& other) {
    if(&other == this) {
        return *this;
    }
    clear();

    List::Node* other_it = other._head;

    while(other_it != nullptr) {
        List::Node* creator = new List::Node(other_it->_value);
        if(_tail == nullptr) {
            _head = creator;
        } else {
            _tail->_next = creator;
        }
        _tail = creator;
        other_it = other_it->_next;
    }

    _size = other._size;

    return *this;  
}

List::List(List&& temp_list) {
    _size = temp_list.size();
    _head = temp_list._head;
    _tail = temp_list._tail;

    temp_list._size = 0;
    temp_list._head = nullptr;
    temp_list._tail = nullptr;
}

List& List::operator=(List&& temp_list) {
    clear();
    
    _size = temp_list.size();
    _head = temp_list._head;
    _tail = temp_list._tail;

    temp_list._size = 0;
    temp_list._head = nullptr;
    temp_list._tail = nullptr;

    return *this;
}

List::~List() {
    clear();
}

void List::print() const {
    List::Node* it = _head;

    while(it != nullptr) {
        std::cout << it->_value << " ";
        it = it->_next;
    }
    
    std::cout << std::endl;
}

void List::insert(const int& value) {

    List::Node* new_node = new List::Node(value);
    
    // case: no elements in list
    if(_size == 0) {
        _head = new_node;
        _tail = new_node;
        _size++;
        return;
    } else {
    // case: at least one element in list
        List::Node* last_lower = nullptr;
        List::Node* first_greater_equal = _head;

        List::Node* new_node = new List::Node(value);

        while(first_greater_equal != nullptr) {
            if(first_greater_equal->_value < value){
                last_lower = first_greater_equal;
                first_greater_equal = first_greater_equal->_next;
            } else {
                break;
            }
        }

        new_node->_next = first_greater_equal;

        // case new value lower than head value
        if(last_lower == nullptr) {
            _head = new_node;
        } else {
            last_lower->_next = new_node;
        }

        // case: new value higher than tail value
        if(last_lower == _tail) {
            _tail = new_node;
        }
        _size++;
    }
}

void List::remove(const int& value) {
    List::Node* it = _head;
    List::Node* before_it = nullptr;

    // iterate until the value is found or end of list
    while(it != nullptr) {
        if(it->_value != value) {
                before_it = it;
                it = it->_next;
        } else {
            break;
        }
    }

    // now it points to element to destroy and before_it to the
    // previous element or it points to nullptr
    if(it != nullptr) {
        if(_size == 1) {
            // case: only one element
            _head = nullptr;
            _tail = nullptr;
            _size--;
            delete it;
        } else {
            if(it == _head) {
                // case: element is _head
                _head = it->_next;
                _size--;
                delete it;
            } else {
                if(it == _tail) {
                    // case: element is _tail
                    _tail = before_it;
                    _tail->_next = nullptr;
                    _size--;
                    delete it;
                } else {
                    // case: element is not _head and not _tail
                    before_it->_next = it->_next;
                    _size--;
                    delete it;
                }
            }
        }
    }
}

void List::remove_all_instances(const int& value) {
    List::Node* it = _head;
    List::Node* before_it = nullptr;

    // iterate until the value is found or end of list
    while(it != nullptr) {
        if(it->_value == value) {
            break;
        } else {
            before_it = it;
            it = it->_next;
        }
    }


    // end if value was not found or list is empty
    if(it == nullptr) {
        return;
    }

    // iterate to end of elements with value _value
    List::Node* group_end = it;
    List::Node* after_group_end = it->_next;

    while(after_group_end != nullptr) {
        if(after_group_end->_value == value) {
            group_end = after_group_end;
            after_group_end = after_group_end->_next;
        } else {
            break;
        }
    }

    // now before_it points at Node before group or nullptr
    // it points at the first node with value
    // group_end points at the last node with value
    // after_group_end points at the first node or nullptr
    if(it == _head) {
        _head = after_group_end;
    } else {
        // reassign pointer of before_it node to the first node after the group
        // in case before_it is not nullptr
        before_it->_next = after_group_end;
    }

    // do tail first
    if(group_end == _tail) {
        _tail = before_it;
    }

    // reassign pointer of the last node of the group to nullptr
    group_end->_next = nullptr;

    // delete the nodes inside the group
    List::Node* killer;
    while(it != nullptr) {
        killer = it;
        it = it->_next;
        delete killer;
        _size--;
    }
        
}

std::size_t List::size() const {
    return _size;
}

void List::clear() {
    List::Node* it = _head;
    List::Node* killer;
    while(it != nullptr) {
        killer = it;
        it = it->_next;
        delete killer;
    }

    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

int List::at(const int& index) const {
    if(index >= _size) {
        throw std::out_of_range("Index out of range");
    }

    List::Node* it = _head;
    for(int i = 0; i < index; i++) {
        it = it->_next;
    }

    return it->_value;
}


bool operator==(const List::Node& lhs, const List::Node& rhs) {
    return lhs._value == rhs._value;
}

bool operator==(const List& lhs, const List& rhs) {
    bool equal = true;

    if(lhs.size() != rhs.size()) {
        return false;
    }
    
    List::Node* lhs_it = lhs._head;
    List::Node* rhs_it = rhs._head;

    while(lhs_it != nullptr) {
        if(lhs_it->_value != rhs_it->_value) {
            equal = false;
            break;
        }

        lhs_it = lhs_it->_next;
        rhs_it = rhs_it->_next;
    }
    
    return equal;
}