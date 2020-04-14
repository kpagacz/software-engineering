#ifndef _UNBOUNDED_STACK
#define _UNBOUNDED_STACK
///AP: zabezpieczenia przed wielokrotnym dolaczaniem powinny byc w pliku hpp
///    (obecnie nie zadzialaja - prosze np. utworzyc plik cos.hpp dolaczajacy stack-unbounded.hpp
///    i dolaczyc go do entry.cpp -
///    kompilator uzna ze typy ze stack-unbounded sa wielokrotnie zdefiniowane)



#include <iostream>
#include <stdexcept>

#include "stack-unbounded.hpp"

// StackElement - copy constructor
StackElement::StackElement(StackElement& copied_element) {
    std::cout << "wszedlem do KKop wezla\n";
    value = copied_element.value;
    next = new StackElement(*(copied_element.next));
    std::cout << "KONSTR KOP WEZLA - utworzony wezel o adresie " << next << std::endl;
}
///AP: po pierwsze  - jest tu rekurencja bez warunku stopu
///  bo ostatnia linia wywoluje ponownie konstruktor kopiujacy wezla
///  (dopisalam probe uzycia na koncu fkcji main)
///  po drugie nie bardzo widze sens konstruktora o takim dzialaniu
///  (zazwyczaj tworzony wezel bedacy "kopia" istniejacego bierze z "oryginalu" tylko wartosc
///   a jego nastepnik ma inny adres niz nastepnik "oryginalu")



// Stack - destructor
Stack::~Stack() {
    std::cout << "Destructor called for " << this << std::endl;
    StackElement* iterator = first_element;
    while(iterator != nullptr) {
        StackElement* killer = iterator;
        iterator = iterator->next;
        delete [] killer;                   /// AP: delete killer (pokazywany obiekt nie jest tablica)
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
    std::cout << "KOPIOWANIE 1-go: zrodlo next" <<  copied_stack.first_element->next << " stos docelowy " << first_element->next  << std::endl;

    ///AP: mysle ze nie ma sensu kopiowac do nowego wezla z jego "odpowiednika" adresu nastepnika  (raczej nie bedziemy uwspolniac wezlow)
    ///    lepiej byloby ustawic w definicji StackElement domyslnie next = nullptr, wywolanie konstruktora (przy alokacji) powieliloby to ustawienie
    ///    a w powyzszej linii przepisac tylko wartosc (first_element->value = copied_stack.first_element->value)
    ///    (albo napisac konstruktor wezla taki jak na cwiczeniach / wykladzie, i wtedy byloby tylko
    ///    first_element = new StackElement(copied_stack.first_element->value)


    // then deep copy each stack element from the rhs stack
    StackElement* this_iterator = first_element;
    StackElement* rhs_iterator = copied_stack.first_element;

    while(rhs_iterator->next != nullptr) {
        this_iterator->next = new StackElement;
        *(this_iterator->next) = *(rhs_iterator->next);  ///AP: uwaga jak wyzej
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

    ///AP: operator przypisania powinien najpierw sprawdzic czy nie jest to przypisanie postaci a=a,
    ///   wtedy nie powinien robic nic (a juz zwlaszcza wywolywac clear()... )
    ///   czyli if (this == &rhs_stack)  return *this;
    ///   i dopiero jesli wiemy ze sa to rozne stosy - czyscimy "ten" stos i tworzymy wezly z odpowiednimi wartosciami

    // first, deallcoate current stack
    clear();

    // return *this, if the rhs stack is empty
    if(rhs_stack.first_element == nullptr) {
        return *this;
    }

    // copy first element
    first_element = new StackElement;
    *first_element = *rhs_stack.first_element;  ///AP: uwagi jak do konstruktora kopiujacego

    // then deep copy each stack element from the rhs stack
    StackElement* this_iterator = first_element;
    StackElement* rhs_iterator = rhs_stack.first_element;

    while(rhs_iterator->next != nullptr) {
        this_iterator->next = new StackElement;
        *(this_iterator->next) = *(rhs_iterator->next);
        rhs_iterator = rhs_iterator->next;
        this_iterator = this_iterator->next;
    }

    std::cout <<"koniec przypisania kopiujacego\n\n";
    return *this;
}


// Stack - move assigment
Stack& Stack::operator=(Stack&& rhs_stack) {
    std::cout << "Assigning from rvalue" << std::endl;

    clear();

    first_element = rhs_stack.first_element;
    rhs_stack.first_element = nullptr;
    std::cout <<"koniec przypisania przenoszacego\n\n";

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
    std::cout << "poczatek: " << first_element << "; " ;
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
        delete [] killer;  ///AP: delete killer (zbedne [] - to nie tablica)
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

    return size;   /// AP: funkcja ok, ale mozna byloby sie zastanowic czy pamietanie rozmiaru jako pola stosu nie byloby bardziej oplacalne
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


Stack Stack::costam() const  ///AP: dopisane w celach demonstracyjnych
{

    std::cout << "\npoczatek COSTAM\n";
    Stack wynik;
    wynik.push(1000);
    wynik.push(2000);
    wynik.push(first_element->value);
    wynik.print();
     std::cout << "\nkoniec COSTAM\n";
    return wynik;

}
