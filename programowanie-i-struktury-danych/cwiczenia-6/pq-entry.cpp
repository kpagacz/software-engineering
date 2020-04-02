#include <iostream>

#include "process_queue.hpp"


int main() {
    ProcessQueue queue;
    
    std::cout << "Process queue! Welcome!\nChoose your action:\na - add process\np - prioritize process\no - output process queue\ne - exit routine\n";
    char choice;

    do {
        std::cout << "Your input: ";
        std::cin >> choice;
        unsigned int id, threads;
        switch(choice) {
            case 'a' :
                std::cout << "Input process id and number of threads: ";
                std::cin >> id >> threads;
                queue.addProcess(id, threads);
                continue;
            case 'p' :
                std::cout << "Input process id: ";
                std::cin >> id;
                queue.prioritizeProcess(id);
                continue;
            case 'o' :
                queue.print();
                continue;
        }
    } while (choice != 'e');
    return 0;
}