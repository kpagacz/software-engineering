//Napisać program czytający istniejący plik tekstowy i wypisujący jego zawartość na ekranie.
//Puste linie(zawierające jedynie znak końca linii) i linie wypełnione tylko spacjami nie powinny być wypisywane;
//poza tym układ tekstu wypisywanego na ekranie powinien odpowiadać układowi tekstu w pliku.Program ma działać dla dowolnego pliku tekstowego, 
//zatem nazwa pliku powinna być podawana przez użytkownika.
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<stdexcept>

int main() {
	std::string line, file_name;

	std::cout << "Input file name: ";
	std::cin >> file_name;

	std::ifstream file;
	file.open(file_name, std::ios::out);

	if (file.is_open()) {
		while(std::getline(file, line)) {
			if(line.find_first_not_of(" ") == std::string::npos) {
				continue;
			} else {
				std::cout << line << "\n";
			}
		}

	}
	else {
		throw std::runtime_error("Could not open file");
	}
	return 0;
}
