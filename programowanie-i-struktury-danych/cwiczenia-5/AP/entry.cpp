/*
    Wskazniki - stos.

    Napisac biblioteke implementujaca stos liczb calkowitych (o nieograniczonym rozmiarze) przy pomocy wskazników, udostepniajaca:
        typ Stos (typ strukturalny, przechowujacy wskaznik poczatku stosu)
        konstruktor i destruktor stosu,
        funkcje wypisujaca zawartosc stosu,
        funkcje wkladajaca element na stos,
        funkcje zdejmujaca element ze stosu. Liczba zdjeta ze stosu ma zostac przekazana do programu, pamiec zajmowana przez usuwany element ma zostac zwolniona. W przypadku braku elementu do zdjecia funkcja ma zglaszac wyjatek,
        funkcje zwracajaca rozmiar (liczbe elementów) stosu,
        funkcje czyszczaca stos. Pamiec zajmowana przez elementy stosu ma zostac zwolniona,
        operator == (zwracajacy wartosc logiczna mówiaca czy dwa stosy sa takie same)
        konstruktor kopiujacy
        operator = (przypisania)
    oraz program testujacy dzialanie tej biblioteki
*/

#include <iostream>
#include "stack-unbounded.hpp"


Stack create_stack() {          ///AP: funkcja zmodyfikowana w celach demonstracjnych
        std::cout << "w funkcji CS\n";
        Stack stack;
        Stack st1;
        stack.push(7);
        stack.push(11);
        st1.push(12);
        st1.push(5);
        std::cout << "w funkcji " ; stack.print();
        int a;
        a = stack.pop() + st1.pop();
        if (a%2 == 0)
            return stack;
        else
            return st1;
    }

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

    stack1.push(1111);  //AP
    std::cout << "Stack 2 is (should be 3 2 1): " << std::endl;
    stack2.print();


    std::cout << "Stack 1 is (should be 111 3 2 1): " << std::endl;
    stack1.print();

    // copy constructor
    Stack stack3 = Stack(stack2);



     stack2.push(4444);  //AP
    std::cout << "Stack 2 is (should be 444 3 2 1): " << std::endl;
    stack2.print();

    std::cout << "Stack 3 is (should be 3 2 1): ";
    stack3.print();


stack2.pop();

    // == operator
    bool equal = stack3 == stack2;
    std::cout << "stack2 == stack3 (should be true): " << equal << std::endl;


    std::cout << "\n\n\n\n\n";
    // move assignment


    // move constructor
    std::cout << "Move constructor for stack4 (Stack stack4(create_stack())): \n";
    Stack stack4(create_stack());
    std::cout <<"STACK 4: ";
    stack4.print();

    std::cout << "\n\n\nBRAK Move constructor for stack8 (Stack stack8(stack3.costam()): \n";
    Stack stack8(stack3.costam());
    std::cout <<"STACK 8: ";
    stack8.print();

    ///AP: w powyzszym: fragmencie:
    /// uzycie (zmodyfikowanego) create_stack() powoduje wywolanie konstruktora przenoszacego
    /// uzycie costam() - nie powoduje
    /// w drugim przypadku zachdzi zjawisko nazywane "return value optimization" (RVO) albo "copy elision"
    /// Ogolnie - w niektorych przypadkach kompilator rozpoznaje ze nie ma sensu tworzenie obiektu tymczasowego
    /// i potem kopiowanie go przy return
    /// (adresy poczatkow stosow: tworzonego w funkcji costam() i stack8 sa takie same)
    ///  w funkcji costam() i w dawnej wersji create_stack() potrafil to rozpoznac, w zmodyfikowanej create_stack() juz nie
    ///  Jesli dodamy do opcji kompilatora flage  -fno-elide-constructors to tej optymalizacji nie bedzie


std::cout << "\n\n\n\n\n";
    // move assignment
    Stack stack5;
    stack5 = create_stack();
    std::cout << "Stack 5 should be 11 7: ";
    stack5.print();



    ///AP: dopisane w celach demonstracyjnych (problem z konstruktorem kopiujacym wezla)
    StackElement x (*stack5.first_element);


    return 0;
}
