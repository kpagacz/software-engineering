#include "Beverages.h"
#include <iostream>

int main() {
	HotBeverage* what_do_i_point_to = new MilkTea(50, 500);
	what_do_i_point_to->identify();

	HotMilkshake* what_do_i_point_to2 = new MilkTea(25, 100);
	what_do_i_point_to2->identify();

	return 0;
}