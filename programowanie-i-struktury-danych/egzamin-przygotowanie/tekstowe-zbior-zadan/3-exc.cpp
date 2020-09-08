//  Napisać program czytający dwa istniejące pliki (PL1, PL2) i tworzący nowy (PL3), 
//  w którym zapisana jest zawartość pliku PL1, a po niej - pliku PL2. 
//  Nazwy plików powinny być wprowadzane z klawiatury. 
#include<fstream>
#include<string>
#include<iostream>
#include<stdexcept>


int main() {
    std::string file_name1, file_name2, output_file_name;
    std::cout << "Input file name 1: ";
    std::cin >> file_name1;
    std::cout << "Input file name 2: ";
    std::cin >> file_name2;
    std::cout << "Input output file name: ";
    std::cin >> output_file_name;

    std::ifstream file1, file2;
    std::ofstream output;

    file1.open(file_name1, std::ios::out);
    file2.open(file_name2, std::ios::out);
    output.open(output_file_name, std::ios::in | std::ios::trunc);

    if(file1.is_open() && file2.is_open() && output.is_open()) {
        char c;
        while(file1.get(c)) {
            output << c;
        }

        while(file2.get(c)) {
            output << c;
        }
    }
    
    file1.close();
    file2.close();
    output.close();

    return 0;    
}