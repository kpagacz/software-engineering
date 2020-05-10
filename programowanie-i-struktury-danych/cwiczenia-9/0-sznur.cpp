#include <iostream>
#include <stdexcept>

#include "0-sznur.hpp"


Sznur::Node::Node(const Sznur::Node& other) {
    value = other.value;
    next = nullptr;
}

// constructor, assignment, destructor
Sznur::Sznur(const Sznur& other) {
    Node* other_it = other._head;

    while(other_it != nullptr) {
        push_back(other_it->value);
        other_it = other_it->next;
    }
}

// Sznur(Sznur&&);
// Sznur& operator=(const Sznur&);
// Sznur& operator=(Sznur&&);

Sznur::~Sznur() {
    Node* it = _head;
    Node* destroyer = nullptr;

    while(it != nullptr) {
        destroyer = it;
        it = it->next;
        delete destroyer;
    }
}

// other
std::ostream& operator<<(std::ostream& os, const Sznur& sznur) {
    os << "Sznur: " << sznur._head << std::endl;

    Sznur::Node* it = sznur._head;
    while(it != nullptr) {
        os << it->value << " ";
        it = it->next;
    }

    os << std::endl;

    return os;
}

void Sznur::push_back(const int& _value) {
    Node* creator = new Node(_value);

    if(_head == nullptr) {
        _head = creator;
    } else {
        Node* it = _head;

        while(it->next != nullptr) {
            it = it->next;
        }

        it->next = creator;
    }

    _size++;
}

void Sznur::UsunFragmenty(const int& N) {
    if (N < 1) {
        throw std::invalid_argument("N must be > 0");
    }

    if(_head == nullptr) {
        return;
    }

    Node* group_begin = _head;
    Node* group_end = _head;
    Node* before_group = nullptr;
    Node* after_group = _head->next;

    Node* destroyer = nullptr;

    int group_size = 1;

    while(after_group != nullptr) {
        // case: same value, extend chain
        if(after_group->value == group_end->value) {
            group_end = after_group;
            after_group = after_group->next;
            group_size++;
        } else {
        // case: different value, delete chain
        // reset pointers and group_size
            if(group_size >= N) {
                // delete chain
                if(before_group == nullptr) {
                    _head = after_group;
                } else {
                    before_group->next = after_group;
                }

                group_end->next = nullptr;

                while(group_begin != nullptr) {
                    destroyer = group_begin;
                    group_begin = group_begin->next;
                    delete destroyer;
                    _size--;
                }

                group_begin = after_group;
                group_end = after_group;
                after_group = after_group->next;                
                group_size = 1;
            } else {
                before_group = group_end;
                group_begin = after_group;
                group_end = after_group;
                after_group = after_group->next;
                group_size = 1;
            }
        }
    }

    if(group_size >= N) {
        // delete chain
        if(before_group == nullptr) {
            _head = after_group;
        } else {
            before_group->next = after_group;
        }

        group_end->next = nullptr;

        while(group_begin != nullptr) {
            destroyer = group_begin;
            group_begin = group_begin->next;
            delete destroyer;
            _size--;
        }
    } 
}

void Sznur::usunZPar(const int& G) {
    Node* iterator = _head;

    Node* before_pair = nullptr;
    Node* first_from_pair = nullptr;
    Node* second_from_pair = nullptr;
    Node* destroyer = nullptr;

    while(iterator != nullptr && iterator->next != nullptr) {
        first_from_pair = iterator;
        second_from_pair = iterator->next;
        iterator = iterator->next->next;

        if(first_from_pair->value + second_from_pair->value < G) {
            // delete first
            if(before_pair == nullptr) {
                _head = second_from_pair;
            } else {
                before_pair->next = second_from_pair;
            }
            delete first_from_pair;
            _size--;
            before_pair = second_from_pair;
        } else {
            // delete second
            first_from_pair->next = second_from_pair->next;
            delete second_from_pair;
            _size--;
            before_pair = first_from_pair;
        }

    }
}

void Sznur::przestawParzyste() {
    if(_size < 2) {
        return;
    }

    Node* tail_it = nullptr;
    Node* it = _head;
    Node* pred = nullptr;
    Node* after_tail = nullptr;

    while(it != nullptr) {
        tail_it = it;
        after_tail = it->next;
        it = it->next;
    }

    it = _head;

    for(int i = 0; i < _size - 1; i++) {
        if(it->value % 2 == 0) {
            tail_it->next = it;
            if(pred == nullptr) {
                _head = it->next;
            } else {
                pred->next = it->next;
            }
            it = it->next;
            tail_it->next->next = after_tail;
            after_tail = tail_it->next;

        } else {
            pred = it;
            it = it->next;
        }
    }
}


void Sznur::Odwroc(int N) {
    if(N < 0) {
        throw std::invalid_argument("N needs to be >= 0.");
    }

    if(_size < 2 || N < 2) {
        return;
    }

    Node* pred = _head;
    Node* succ = _head->next;
    Node* after_succ = succ->next;
    Node* end = _head;

    while(end->next != nullptr && N > 1) {
        end = end->next;
        N--;
    }

    // head will be the last element of the chain,
    // so point its node to after_end
    Node* after_end = end->next;
    _head->next = after_end;

    // reassign _head to end of chain
    // point _head towards next
    _head = end;

    while(succ != after_end) {
        after_succ = succ->next;
        succ->next = pred;
        pred = succ;
        succ = after_succ;
    }

}
void Sznur::Przegrupuj(Sznur& other) {
    Node* this_succ = _head;
    Node* this_pred = nullptr;
    Node* other_succ = other._head;
    Node* other_pred = nullptr;

    Node* even_begin = nullptr;
    Node* even_end = nullptr;

    Node* odd_begin = nullptr;
    Node* odd_end = nullptr;

    // even chain
    while(this_succ != nullptr || other_succ != nullptr) {
        // add one even from first Sznur
        while(this_succ != nullptr) {
            if(this_succ->value % 2 == 0) {
                // unchain
                if(this_pred == nullptr) {
                    _head = this_succ->next;
                } else {
                    this_pred->next = this_succ->next;
                }

                if(even_begin == nullptr) {
                    even_begin = this_succ;
                    even_end = this_succ;
                } else {
                    even_end->next = this_succ;
                    even_end = this_succ;
                }

                this_succ = this_succ->next;
                even_end->next = nullptr;
                break;
            } else {
                // iterate next
                this_pred = this_succ;
                this_succ = this_succ->next;
            }
        }

        // add one even from other Sznur
        while(other_succ != nullptr) {
            if(other_succ->value % 2 == 0) {
                // unchain
                if(other_pred == nullptr) {
                    other._head = other_succ->next;
                } else {
                    other_pred->next = other_succ->next;
                }

                if(even_begin == nullptr) {
                    even_begin = other_succ;
                    even_end = other_succ;
                } else {
                    even_end->next = other_succ;
                    even_end = other_succ;
                }

                other_succ = other_succ->next;
                even_end->next = nullptr;
                _size++;
                other._size--;
                break;
            } else {
                // iterate next
                other_pred = other_succ;
                other_succ = other_succ->next;
            }
        }
    }

    this_succ = _head;
    other_succ = other._head;
    this_pred = nullptr;
    other_pred = nullptr;
    // odd chain
    while(this_succ != nullptr || other_succ != nullptr) {
        // add one even from first Sznur
        while(this_succ != nullptr) {
            if(this_succ->value % 2 == 1) {
                // unchain
                if(this_pred == nullptr) {
                    _head = this_succ->next;
                } else {
                    this_pred->next = this_succ->next;
                }

                if(odd_begin == nullptr) {
                    odd_begin = this_succ;
                    odd_end = this_succ;
                } else {
                    odd_end->next = this_succ;
                    odd_end = this_succ;
                }

                this_succ = this_succ->next;
                odd_end->next = nullptr;
                _size--;
                other._size++;
                break;
            } else {
                // iterate next
                this_pred = this_succ;
                this_succ = this_succ->next;
            }
        }

        // add one even from other Sznur
        while(other_succ != nullptr) {
            if(other_succ->value % 2 == 1) {
                // unchain
                if(other_pred == nullptr) {
                    other._head = other_succ->next;
                } else {
                    other_pred->next = other_succ->next;
                }

                if(odd_begin == nullptr) {
                    odd_begin = other_succ;
                    odd_end = other_succ;
                } else {
                    odd_end->next = other_succ;
                    odd_end = other_succ;
                }

                other_succ = other_succ->next;
                odd_end->next = nullptr;
                break;
            } else {
                // iterate next
                other_pred = other_succ;
                other_succ = other_succ->next;
            }
        }
    }

    _head = even_begin;
    other._head = odd_begin;
}

void Sznur::empty() {
    Node* it = _head;
    Node* destroyer = nullptr;

    while(it != nullptr) {
        destroyer = it;
        it = it->next;
        delete destroyer;
    }

    _size = 0;
}