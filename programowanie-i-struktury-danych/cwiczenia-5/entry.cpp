/*
    Wskaźniki - stos.

    Napisać bibliotekę implementującą stos liczb całkowitych (o nieograniczonym rozmiarze) przy pomocy wskaźników, udostępniającą:
        typ Stos (typ strukturalny, przechowujący wskaźnik początku stosu)
        konstruktor i destruktor stosu,
        funkcję wypisującą zawartość stosu,
        funkcję wkładającą element na stos,
        funkcję zdejmującą element ze stosu. Liczba zdjęta ze stosu ma zostać przekazana do programu, pamięć zajmowana przez usuwany element ma zostać zwolniona. W przypadku braku elementu do zdjęcia funkcja ma zgłaszać wyjątek,
        funkcję zwracającą rozmiar (liczbę elementów) stosu,
        funkcję czyszczącą stos. Pamięć zajmowana przez elementy stosu ma zostać zwolniona,
        operator == (zwracający wartość logiczną mówiącą czy dwa stosy są takie same)
        konstruktor kopiujący
        operator = (przypisania) 
    oraz program testujący działanie tej biblioteki 
*/

#include <iostream>
#include "stack-unbounded.hpp"

Stack create_stack() {
        Stack stack;
        stack.push(7);
        stack.push(11);
        return stack;
    };

int main() {

    // testing constructors
    Stack stack1, stack2;

    std::cout << "Stack 1 is: ";
    stack1.print();

    std::cout << "Stack 2 is: ";
    stack2.print();

    // pushing onto stack
    stack1.push(7);
    std::cout << "Stack 1 is now: ";
    stack1.print();
    std::cout << "Stack 2 is still: ";
    stack2.print();

    // clearing
    std::cout << "Clearing stack1" << std::endl;
    stack1.clear();
    stack1.clear();
    std::cout << "Stack 1 (should be empty): ";
    stack1.print();

    // size test
    stack1.push(7);
    stack1.push(8);
    std::cout << "Size of stack 1 (should be 2): " << stack1.size() << std::endl;
    
    // pop test
    std::cout << "At the top of stack 1 (should be 8): " << stack1.pop() << std::endl;
    std::cout << "Size of stack 1 (should be 1): " << stack1.size() << std::endl;
    stack1.pop();
    std::cout << "Trying to pop an empty stack (should throw an exception): " << std::endl;
    try
    {
        stack1.pop();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    
    // copy assignment
    std::cout << "Stack 2 is: ";
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack2.print();
    std::cout << "Stack 1 is: ";
    stack1.print();

    std::cout << "Copy assignment stack2 = stack1: " << std::endl;
    stack2 = stack1;
    std::cout << "Stack 2 is (should be 3 2 1): " << std::endl;
    stack2.print();

    // copy constructor
    Stack stack3 = Stack(stack2);
    std::cout << "Stack 3 is (should be 3 2 1): ";
    stack3.print();

    // == operator
    bool equal = stack3 == stack2;
    std::cout << "stack2 == stack3 (should be true): " << equal << std::endl;


    // move constructor
    std::cout << "Move constructor for stack4 (Stack stack4(create_stack())): ";
    Stack stack4(create_stack());
    stack4.print();

    // move assignment
    Stack stack5;
    stack5 = create_stack();
    std::cout << "Stack 5 should be 11 7: ";
    stack5.print();
    return 0;
}