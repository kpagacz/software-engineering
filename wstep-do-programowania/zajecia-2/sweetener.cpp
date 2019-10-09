#include <iostream>

int main() {
	// input
	const int juice_liter_mass = 1200;
	const float sweetener_concentration = 0.0001, mouse_mass = 400, mouse_lethal_dose = 2;
	float human_mass;
	std::cout << "please, input human mass" << std::endl;
	std::cin >> human_mass;	
	
	// calculations
	float deadly_concentration = mouse_lethal_dose / mouse_mass;
	float maximum_juice_mass = deadly_concentration * human_mass / sweetener_concentration;
	float maximum_juice_volume = maximum_juice_mass / juice_liter_mass;
	
	// output
	std::cout << "Maximum non-lethal dose [l]: " << maximum_juice_volume;
	return 0; 
	
}
