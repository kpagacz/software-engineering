#include <iostream>
#include <stdexcept>
#include "spis-towarow.hpp"

Spis_towarow::Towar::Towar(int _kod_towaru, float _ilosc) {
    if(_kod_towaru < 1) {
        throw std::invalid_argument("Kod towaru ma byc dodatni.");
    }

    if(_ilosc < 0) {
        throw std::invalid_argument("Ilosc ma byc nieujemna.");
    }

    kod_towaru = _kod_towaru;
    ilosc = _ilosc;
    next_towar = nullptr;
}

Spis_towarow::Towar Spis_towarow::zrob_towar(int _kod_towaru, float _ilosc) {
    return Towar(_kod_towaru, _ilosc);
}

void Spis_towarow::print() const {
    Towar* it = _head;

    if (it != nullptr) {
        std::cout << "Spis towarow: " << it << std::endl;
    }

    while(it != nullptr) {
        std::cout << "Kod towaru: " << it->kod_towaru << " Ilosc towaru: " << it->ilosc << std::endl;
        it = it->next_towar;
    }
    
}

void Spis_towarow::wstaw(const Spis_towarow::Towar& towar) {
    Towar* predecessor = nullptr;
    Towar* successor = _head;

    Towar* nowy_towar = new Towar(towar.kod_towaru, towar.ilosc);

    if(_size == 0) {
        _head = nowy_towar;
        _tail = nowy_towar;
        _size++;
        return;
    }

    // iterate to find the place to insert
    while(successor != nullptr) {
        if(towar.kod_towaru < successor->kod_towaru) {
            break;
        } else {
            predecessor = successor;
            successor = successor->next_towar;
        }
    }

    // case: insert at the beginning
    if(successor == _head) {
        nowy_towar->next_towar = _head;
        _head = nowy_towar;
        _size++;
        return;
    }

    // case: insert at the end
    if(predecessor == _tail) {
        _tail->next_towar = nowy_towar;
        _tail = nowy_towar;
        _size++;
        return;
    }

    // case: insert in the middle
    predecessor->next_towar = nowy_towar;
    nowy_towar->next_towar = successor;
    _size++;
    return;
}

void Spis_towarow::wstaw_roznowartosciowo(const Spis_towarow::Towar& towar) {
    // almost the same as normal wstaw, but with additional check on
    // equal kod towaru
    Towar* predecessor = nullptr;
    Towar* successor = _head;

    Towar* nowy_towar = new Towar(towar.kod_towaru, towar.ilosc);

    if(_size == 0) {
        _head = nowy_towar;
        _tail = nowy_towar;
        _size++;
        return;
    }

    // iterate to find the place to insert
    while(successor != nullptr) {
        if(towar.kod_towaru < successor->kod_towaru) {
            break;
        } else {
            predecessor = successor;
            successor = successor->next_towar;
        }
    }

    // case: insert at the beginning
    if(successor == _head) {
        nowy_towar->next_towar = _head;
        _head = nowy_towar;
        _size++;
        return;
    }

    // case: insert at the end
    if(predecessor == _tail) {
        if(predecessor->kod_towaru == nowy_towar->kod_towaru) {
            _tail->ilosc += nowy_towar->ilosc;
        } else {
            _tail->next_towar = nowy_towar;
            _tail = nowy_towar;
            _size++;
        }
        return;
    }

    // case: insert in the middle
    if(predecessor->kod_towaru == nowy_towar->kod_towaru) {
        predecessor->ilosc += nowy_towar->ilosc;
    } else {
        predecessor->next_towar = nowy_towar;
        nowy_towar->next_towar = successor;
        _size++;
    }
    return;    
}

void Spis_towarow::odejmij_ze_spisu(const Spis_towarow& other) {
    if(_head == nullptr) {
        return;
    }

    skompresuj();

    // subtracting ilosc
    Towar* this_it = _head;
    Towar* other_it = other._head;

    while(other_it != nullptr && this_it != nullptr) {
        if(this_it->kod_towaru == other_it->kod_towaru) {
            this_it->ilosc -= other_it->ilosc;
            other_it = other_it->next_towar;
        } else {
            if(other_it->kod_towaru > this_it->kod_towaru) {
                this_it = this_it->next_towar;
            } else {
                other_it = other_it->next_towar;
            }
        }
    }

    // removing nodes with negative ilosc
    Towar* pred_node = nullptr;
    Towar* current_node = _head;

    while(current_node != nullptr) {
        if(current_node->ilosc < 0) {
            usunTowar(pred_node, current_node);
        } else {
            pred_node = current_node;
            current_node = current_node->next_towar;
        }
    }    

}

void Spis_towarow::usunTowar(Towar*& pred_node, Towar*& to_destroy) {
    if(to_destroy == _head) {
        _head = to_destroy->next_towar;
        delete to_destroy;
        to_destroy = _head;
        _size--;
        return;
    }

    if(to_destroy == _tail) {
        _tail = pred_node;
        _tail->next_towar = nullptr;
        Towar* destroyer = to_destroy;
        to_destroy = to_destroy->next_towar;

        delete destroyer;
        _size--;
        return;
    }

    pred_node->next_towar = to_destroy->next_towar;
    delete to_destroy;
    to_destroy = pred_node->next_towar;
    _size--;
    return;
}

void Spis_towarow::skompresuj() {
    Towar* it = _head;
    Towar* destroyer = nullptr;

    // case: size < 2
    if(_size < 2) {
        return;
    }

    while(it->next_towar != nullptr) {
        if(it->next_towar->kod_towaru == it->kod_towaru) {
            // retrieve needed data
            it->ilosc += it->next_towar->ilosc;
            it->next_towar = it->next_towar->next_towar;
            
            // reassign _tail if needed
            if(it->next_towar == _tail) {
                _tail = it;
            }

            // load the gun and fire
            destroyer = it->next_towar;
            delete destroyer;
            continue;
        } else {
            it = it->next_towar;
        }
    }
}

int Spis_towarow::zliczIlosc(Towar* begin_counting, Towar* end_counting) {
    int sum_of_ilosc;
    Towar* it = begin_counting;
    while(it != end_counting->next_towar) {
        sum_of_ilosc += it->ilosc;
        it = it->next_towar;
    }

    return sum_of_ilosc;
}


// constructors
Spis_towarow::Spis_towarow(const Towar& towar) {
    Towar* nowy_towar = new Towar(towar.kod_towaru, towar.ilosc);
    _head = nowy_towar;
    _tail = nowy_towar;
    _size++;
}

Spis_towarow::Spis_towarow(const Spis_towarow& other) {
    Towar* it = other._head;

    _head = nullptr;
    _tail = nullptr;
    _size = 0;

    while(it != nullptr) {
        Towar* creator = new Towar(it->kod_towaru, it->ilosc);
        wstaw(*creator);
        it = it->next_towar;
    }
    
}

Spis_towarow::Spis_towarow(Spis_towarow&& other) {
    _head = other._head;
    _tail = other._tail;
    _size = other._size;

    other._head = nullptr;
    other._tail = nullptr;
    other._size = 0;
}

Spis_towarow::~Spis_towarow() {
    Towar* destroyer = _head;
    Towar* it = _head;

    while(it != nullptr) {
        destroyer = it;
        it = it->next_towar;
        delete destroyer;
    }

}

Spis_towarow& Spis_towarow::operator=(const Spis_towarow& other) {
    // self-assignment check
    if(&other == this) {
        return *this;
    }

    // free up allocated memory
    Towar* this_it = _head;
    Towar* destroyer = _head;
    while(this_it != nullptr) {
        destroyer = this_it;
        delete destroyer;
        this_it = this_it->next_towar;
    }


    _head = nullptr;
    _tail = nullptr;
    _size = 0;

    // copy other resources
    Towar* it = other._head;
    
    while(it != nullptr) {
        Towar* creator = new Towar(it->kod_towaru, it->ilosc);
        wstaw(*creator);
        it = it->next_towar;
    }

    return *this;
}

Spis_towarow& Spis_towarow::operator=(Spis_towarow&& other) {
    // free up allocated memory
    Towar* this_it = _head;
    Towar* destroyer = _head;
    while(this_it != nullptr) {
        destroyer = this_it;
        delete destroyer;
        this_it = this_it->next_towar;
    }

    // consume other resources
    _head = other._head;
    _tail = other._tail;
    _size = other._size;

    // reset other resources
    other._head = nullptr;
    other._tail = nullptr;
    other._size = 0;

    return *this;
}