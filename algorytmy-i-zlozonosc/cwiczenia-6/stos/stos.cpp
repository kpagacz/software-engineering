#include<iostream>
#include<stdexcept>

struct node
{
    int num;
    node* next;
    node(int _num, node* _next) : num(_num), next(_next) {};
    node() = default;
};


void Put(node*& h, int k)
{
    node* temp = new node;
    temp->num = k;
    temp->next = h;
    h = temp;
}

int Get(node*& h) {
    if (h == nullptr) throw std::out_of_range("Empty");
    int result = h->num;
    node* destr = h;
    h = h->next;
    delete destr;
    destr = nullptr;
    return result;
}


int main()
{
    node* head = nullptr;
    Put(head, 7);
    Put(head, 8);
    Put(head, 9);
    Put(head, 10);

    node* it = head;
    while (it != nullptr) {
        std::cout << it->num << " ";
        it = it->next;
    }
    std::cout << "\n";

    Get(head);
    it = head;
    while (it != nullptr) {
        std::cout << it->num << " ";
        it = it->next;
    }

    return 0;
}