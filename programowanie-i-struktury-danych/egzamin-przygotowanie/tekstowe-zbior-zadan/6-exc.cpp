// W pliku tekstowym KLUB.LST zapisana jest w porządku alfabetycznym lista członków pewnego klubu. Każdemu członkowi odpowiadają trzy linie:

// 	nazwisko i imię
// 	adres   
// 	nr telefonu

// Napisać program dopisujący do pliku nowego członka klubu o danych osobowych wprowadzanych z klawiatury. 
// Osoba ma być dopisywana w odpowiednim miejscu pliku - tak, aby utrzymać porządek alfabetyczny. (Wskazówka - należy użyć pliku pomocniczego) 

#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<stdexcept>

int main() {
    std::string filename = "6-KLUB.LST";
    std::ifstream file(filename, std::ios::in);

    if(!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string name, address, phone;
    std::cout << "Input name and surname of the person (eg. Konrad Pagacz): ";
    std::getline(std::cin, name);

    std::cout << "Input address: ";
    std::getline(std::cin, address);

    std::cout << "Input phone number: ";
    std::getline(std::cin, phone);

    std::stringstream new_file;

    std::string name_line, address_line, phone_line;

    bool written_new_person = false;
    while(std::getline(file, name_line)) {
        std::getline(file, address_line);
        std::getline(file, phone_line);

        if(!written_new_person) {
            if(name_line.compare(name) > 0) {
                // new person's name is lower in the alphabet
                // input new person here
                new_file << name << "\n" << address << "\n" << phone << "\n";
                written_new_person = true;
            }
        }
        new_file << name_line << "\n" << address_line << "\n" << phone_line << "\n";
    }

    if(!written_new_person) {
        new_file << name << "\n" << address << "\n" << phone << "\n";
    }

    file.close();

    std::ofstream output(filename, std::ios::out | std::ios::trunc);
    char c;
    while(new_file.get(c)) {
        output << c;
    }

    output.close();

    return 0;
}