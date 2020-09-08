#include<iostream>
#include<fstream>
#include<string>

#include "IBAN.h"
#include "SortedList.h"


int main() {
	// File name is supposed to be user input
	std::string file_name;
	std::cout << "Input file name: ";
	std::cin >> file_name;

	// File handling setup
	// Throws if file could not be opened
	std::ifstream file;
	file.open(file_name, std::ios::in);
	if(!file.is_open()) {
		throw std::runtime_error("Could not open file");
	}


	// Algorithm:
	// read line by line
	// try to initialize an IBAN number with the number read in line
	// if success: add to the sorted list
	// if fail: next line
	// validation of input is handled in the step of constructing the IBAN instance

	std::string line;
	SortedList<IBAN> list;

	while(std::getline(file, line)) {
		try
		{
			IBAN iban(line);
			list.insert(iban);
		}
		catch(const std::exception& e)
		{
			std::cout << "IBAN failed to add." << e.what();
		}
	}

	std::ofstream out1020, out1140, out2490;
	std::string filename1 = "1020.txt", filename2 = "1140.txt", filename3 = "2490.txt";

	out1020.open(filename1, std::ios::in | std::ios::trunc);
	out1140.open(filename2, std::ios::in | std::ios::trunc);
	out2490.open(filename3, std::ios::in | std::ios::trunc);

	if(out1020.is_open() && out1140.is_open() && out2490.is_open()) {
		std::string bank_id;
		IBAN iban;
		for(int i = 0; i < list.get_size(); i++) {
			iban = list.pop_front();

			out1020 << iban;
		}
	}

	return 0;
}