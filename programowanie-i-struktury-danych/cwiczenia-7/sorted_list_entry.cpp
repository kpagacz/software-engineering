#include <iostream>

#include "sorted_list_unbounded.hpp"


int main() {
    std::cout << "Testing constructors." << std::endl;
    List list1, list2;

    std::cout << "Testing inserting." << std::endl;
    list1.insert(8);
    std::cout << "Testing printing" << std::endl;
    std::cout << "List1 (should be 8): ";
    list1.print();

    list1.insert(8);
    list1.insert(1);
    list1.insert(10);

    std::cout << "List1 (should be 1 8 8 10): " ;
    list1.print();

    std::cout << "Testing removal." << std::endl;
    list1.insert(7);
    list1.print();
    list1.remove(7);
    list1.print();
    int size0 = list1.size();
    std::cout << "list1 size: " << size0 << std::endl;
    list1.remove(1);
    list1.print();
    int size1 = list1.size();
    std::cout << "list1 size: " << size1 << std::endl;
    list1.remove(10);
    list1.print();

    std::cout << "Testing removal of all" << std::endl;
    list1.remove_all_instances(8);
    list1.print();

    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);
    list1.insert(2);
    list1.print();
    list1.remove_all_instances(4);
    list1.print();

    list1.remove_all_instances(1);
    list1.print();
    int size2 = list1.size();
    std::cout << "list1 size: " << size2 << std::endl;

    int at0 = list1.at(0);
    int at1 = list1.at(1);

    std::cout << "list1: at position 0: " << at0 << " at position 1: " << at1 << std::endl;
    
    try
    {
        list1.at(2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    list2.insert(2);
    list2.insert(3);

    list1.print();
    list2.print();
    bool equal = list1 == list2;
    std::cout << "list1 == list2: " << equal << std::endl;

    std::cout << "Copy constructor list3" << std::endl;
    List list3(list1);
    list3.print();
    int size3 = list3.size();
    std::cout << "list3 size: " << size3 << std::endl;
    std::cout << "Copy assignment list3 = list2" << std::endl;
    list3 = list2;
    std::cout << "list3: ";
    list3.print();
    return 0;
}