#include <iostream>
#include "LCG_generator.h"

int main() {
	LCG_generator gen(17);
	std::cout << gen.random() << "\n";
	return 0;
}