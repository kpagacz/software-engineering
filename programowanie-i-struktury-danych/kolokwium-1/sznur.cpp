#include<iostream>
#include<stdexcept>
#include "sznur.hpp"


Rope::~Rope() {
    Node *it = head, *destroyer = nullptr;
    while(it != nullptr) {
        destroyer = it;
        it = it->next;
        delete destroyer;
    }
    size = 0;
};

void Rope::push(const int& el) {
    Node *succ = head, *pred = nullptr, *creator = new Node(el);

    while(succ != nullptr) {
        if(creator->value <= succ->value) {
            pred = succ;
            succ = succ->next;
        } else {
            break;
        }
    }

    if(pred == nullptr) {
        head = creator;
    } else {
        pred->next = creator;
    }

    creator->next = succ;
    size++;
};

void remove(Rope &rope, const int &K) {
    if(rope.size < 3) {
        return;
    }

    Rope::Node *pred_triple = nullptr, *first = nullptr, *second = nullptr, *third = nullptr, *destroyer = nullptr;
    int counter = 3;
    
    for(int i = 0; i < rope.size / 3; i++) {
        if(pred_triple == nullptr) {
            first = rope.head;
        } else {
            first = pred_triple->next;
        }
        second = first->next;
        third = second->next;
        // std::cout << "Third: " << first->value << " " << second->value << " " << third->value << std::endl;

        if((1.0 * first->value + second->value + third->value) / 3 < K) {
            // remove the first node
            destroyer = first;
            first = nullptr;
            delete destroyer;
            rope.size--;

            if(pred_triple == nullptr) {
                rope.head = second;
            } else {
                pred_triple->next = second;
            }
        }
        pred_triple = third;
    }
}

int Rope::getSize() const {
    return size;
}

void Rope::moveChainToTarget(Rope::Node* pred_chain, Rope::Node* begin_chain, Rope::Node* end_chain, 
                                Rope::Node* succ_chain, Rope::Node* pred_target, Rope::Node* succ_target) {
    // fixing target location
    if(pred_target == nullptr) {
        head = begin_chain;
    } else {
        pred_target->next = begin_chain; 
    }
    end_chain->next = succ_target;

    // fixing chain location
    if(pred_chain == nullptr) {
        head = succ_chain;
    } else {
        pred_chain->next = succ_chain;
    }
}

void move(Rope &rope){
    Rope::Node *new_head = nullptr, *beginning_chain_end = nullptr,
        *old_tail = nullptr;

    Rope::Node *pred_pair = nullptr, *first = nullptr, *second = nullptr, *succ_pair = nullptr;

    Rope::Node *it = rope.head;

    // finding original tail
    while(it->next != nullptr) {
        it = it->next;
    } 
    old_tail = it;

    // iterating through the pairs
    for(int i = 0; i < rope.getSize() / 2; i++) {
        // setting pointers to the new pair
        if(pred_pair == nullptr) {
            first = rope.head;
        } else {
            first = pred_pair->next;
        }
        second = first->next;
        succ_pair = second->next;

        // same check
        if(first->value == second->value) {
            // values are the same
            // fix the excision
            if(pred_pair != nullptr) {
                pred_pair->next = succ_pair;
            } else {
                rope.head = succ_pair;
            }

            // link
            if(new_head == nullptr) {
                new_head = first;
                beginning_chain_end = second;
            } else {
                beginning_chain_end->next = first;
            }

            second->next = rope.head;

        } else {
            // different values
            // excise
            first->next = succ_pair;

            // link
            second->next = old_tail->next;
            old_tail->next = second;

            // set pred_pair properly
            pred_pair = first;
        }

    }
    if(new_head != nullptr) {
        rope.head = new_head;
    }

}

void exchangeConstantSequences(Rope &r1, Rope &r2) {
    Rope::Node *r1_pred_chain = nullptr, *r1_succ_chain = r1.head, *r1_begin = nullptr, *r1_end = nullptr;
    Rope::Node *r2_pred_chain = nullptr, *r2_succ_chain = r2.head, *r2_begin = nullptr, *r2_end = nullptr;

    bool constant_sequence_flag = 1;

    while(r1_succ_chain != nullptr && r2_succ_chain != nullptr) {
        if(constant_sequence_flag) {
            // look for constant sequence
            lookForConstant(r1_pred_chain, r1_begin, r1_end, r1_succ_chain);
            lookForConstant(r2_pred_chain, r2_begin, r2_end, r2_succ_chain);

            // relink them
            if(r1_pred_chain == nullptr) {
                r1.head = r2_begin;
            } else {
                r1_pred_chain->next = r2_begin;
            }
            r2_end->next = r1_succ_chain;

            if(r2_pred_chain == nullptr) {
                r2.head = r1_begin;
            } else {
                r2_pred_chain->next = r1_begin;
            }
            r1_end->next = r2_succ_chain;

            // reset pointers
            r1_pred_chain = r2_end;
            r2_pred_chain = r1_end;
            
            r1_begin = nullptr;
            r1_end = nullptr;

            r2_begin = nullptr;
            r2_end = nullptr;

        } else {
            // look for variable sequence
            lookForVariable(r1_pred_chain, r1_begin, r1_end, r1_succ_chain);
            lookForVariable(r2_pred_chain, r2_begin, r2_end, r2_succ_chain);

            // skip those sequences - reset pointers smartly
            if(r1_begin != nullptr) {
                r1_pred_chain = r1_end;
            }
            if(r2_begin != nullptr) {
                r2_pred_chain = r2_end;
            }
            r1_begin = nullptr;
            r1_end = nullptr;
            r2_begin = nullptr;
            r2_end = nullptr;
        }
        constant_sequence_flag = !constant_sequence_flag;
    }
};

void lookForConstant(Rope::Node*& pred, Rope::Node*& begin, Rope::Node*& end, Rope::Node*& succ) {
    // pre-conditions:
    // succ is not nullptr

    if(succ == nullptr) {
        throw std::invalid_argument("succ cannot be nullptr");
    }

    while(succ != nullptr) {
        if(begin == nullptr) {
            begin = succ;
            end = succ;
            succ = succ->next;
        } else {
            if(succ->value == end->value) {
                end = succ;
                succ = succ->next;
            } else {
                break;
            }
        }
    }
}

void lookForVariable(Rope::Node*& pred, Rope::Node*& begin, Rope::Node*& end, Rope::Node*& succ) {
    // sequence of different values must be of length 0 or >=2, cannot be one
    // exploits short-circuit evaluation of ||
    if(succ == nullptr || succ->next == nullptr) {
        return;
    }

    if(succ->value == succ->next->value) {
        return;
    }

    begin = succ;
    end = succ->next;
    succ = end->next;

    while(succ != nullptr) {
        bool isUnique = true;
        Rope::Node *it = begin;
        // check if next value in Rope is unique
        while(it != succ) {
            if(succ->value == it->value) {
                isUnique = false;
                break;
            }
            it = it->next;
        }

        // if is unique extend the sequence
        if(isUnique) {
            end = succ;
            succ = succ->next;
        } else {
            break;
        }
    }
}
