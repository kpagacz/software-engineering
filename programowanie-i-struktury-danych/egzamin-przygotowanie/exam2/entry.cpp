#include "List.h"
#include "NIP.h"

#include<iostream>
#include<fstream>
#include<stdexcept>

int main() {
	std::string locations[3] = { "771", "772", "773" };
	// input file
	std::string file_name = "nipy.txt";
	std::ifstream input;
	input.open(file_name, std::ios::in);

	if (!input.is_open()) {
		throw std::runtime_error("Could not open file");
	}

	// parse lines
	List<NIP> nipy;
	std::string line, nip_part, name_part;
	
	while (std::getline(input, line)) {
		int first_space = line.find(" ");
		nip_part = line.substr(0, first_space);
		name_part = line.substr(first_space + 1, std::string::npos);

		NIP single_nip;
		try {
			single_nip.set_name(name_part);
			single_nip.set_nip(nip_part);
		}
		catch (std::exception& e) {
			std::cout << "Wrong NIP. Error: " << e.what() << "\n" << line << "\n";
			continue;
		}

		std::string location_part = single_nip.get_nip().substr(0, 3);
		bool wrong_location = true;
		for (auto location : locations) {
			if (location_part.compare(location) == 0) {
				wrong_location = false;
				break;
			}
		}

		if (wrong_location) {
			std::cout << "Wrong location in line: \n" << line << "\n";
		}
		else {
			nipy.insert(single_nip);
		}
	}

	// setup output files
	std::string piotrkow_filename = "piotrkow.txt", radomsko_filename = "radomsko.txt", tomaszow_filename = "tomaszow.txt";
	std::ofstream piotrkow(piotrkow_filename), radomsko(radomsko_filename), tomaszow(tomaszow_filename);

	if (piotrkow.is_open() && radomsko.is_open() && tomaszow.is_open()) {
		NIP out_nip;
		int nipy_size = nipy.size();
		for (int i = 0; i < nipy_size; i++) {
			out_nip = nipy.pop_front();
			std::string location_part = out_nip.get_nip().substr(0, 3);
			if (location_part == "771") {
				piotrkow << out_nip.get_name() << "\n";
			}
			if (location_part == "772") {
				radomsko << out_nip.get_name() << "\n";
			}
			if (location_part == "773") {
				tomaszow << out_nip.get_name() << "\n";
			}
		}
	}
	else {
		std::cout << "Could no open output files";
	}

	input.close();
	piotrkow.close();
	radomsko.close();
	tomaszow.close();	
	return 0;
}