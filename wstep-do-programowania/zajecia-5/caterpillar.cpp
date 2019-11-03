#include <iostream>


int main() {
	// input
	int plant_height, step_length_cm, drop_length_cm;

	std::cout << "Input plant height (m), step length (cm) and drop length (cm):" << std::endl;

	std::cin >> plant_height >> step_length_cm >> drop_length_cm;

	float step_length = step_length_cm / 100.0;
	float drop_length = drop_length_cm / 100.0;

	// input validation
	if (plant_height <= 0 || step_length <= 0 || drop_length <= 0) {
		std::cout << "All inputs must be positive integers!" << std::endl;
		return 0;
	}

	// calculations
	float current_step = step_length;
	float height_climbed = 0;
	int step_number = 0;

	while (height_climbed < plant_height && drop_length < 7 * current_step) {
		int i = 0;
		while (height_climbed < plant_height && i < 7) {
			i++;
			height_climbed += current_step;
			step_number++;
		}

		if (height_climbed >= plant_height) {
			break; // break the outer while loop if the caterpillar climbed the plant
		}
		current_step *= 0.9;
		height_climbed -= drop_length;		
	}

	// output
	if (height_climbed >= plant_height) {
		std::cout << "The caterpillar will climb on top of the plant in " << step_number << " steps." << std::endl; 
	} else {
		std::cout << "The caterpillar will never climb on top of the plant." << std::endl;
	}
	return 0;
}
