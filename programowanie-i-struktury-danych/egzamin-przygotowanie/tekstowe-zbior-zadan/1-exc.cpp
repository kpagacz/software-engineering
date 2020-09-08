// Napisać program zapisujący wprowadzony z klawiatury tekst do pliku tekstowego.
//Struktura linii pliku powinna odpowiadać wprowadzanemu tekstowi, 
//a małe litery występujące we wprowadzonym tekście powinny być zamienione na wielkie.

#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include<cstring>

int main() {
	char c;
	std::ofstream file;
	std::string file_name = "1-output.txt";

	file.open(file_name, std::ios::in | std::ios::trunc);

	if (!file.is_open()) {
		throw std::runtime_error("Could not open file");
	}

	while (std::cin.get(c)) {
		if (isalpha(c)) {
			c = toupper(c);
		}
		file << c;
	}

	file.close();

	return 0;
}