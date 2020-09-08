#include "NIP.h"
#include<string>
#include<stdexcept>

void NIP::set_nip(const std::string& new_nip)
{
	std::string stripped_nip;
	for (auto c : new_nip) {
		if (c != '-') {
			stripped_nip += c;
		}
	}

	if (stripped_nip.size() != 10) {
		throw std::invalid_argument("Size of the nip is not 10");
	}

	for (int i = 0; i < 10; i++) {
		if (!isdigit(stripped_nip[i])) {
			throw std::invalid_argument("Non digits in nip");
		}
	}

	int weights[9] = { 6, 5, 7, 2, 3, 4, 5, 6, 7 };
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += (stripped_nip[i] - '0') * weights[i];
	}

	int remainder = sum % 11;
	if (remainder != stripped_nip[9] - '0') {
		throw std::invalid_argument("Wrong control digit in nip");
	}

	nip = stripped_nip;
}

std::string NIP::get_nip() const
{
	return nip;
}

void NIP::set_name(const std::string& new_name)
{
	name = new_name;
}

std::string NIP::get_name() const
{
	return name;
}
