#include <iostream>
#include <iomanip>

int main() {
	// input
	int jump_length_cm, distance_to_cover, rest_threshold_cm;
	
	std::cout << "Input jump length (cm), length of jumps at which the frog needs to rest (cm) and  total distance to cover by the frog (m):" << std::endl;

	std::cin >> jump_length_cm >> rest_threshold_cm >> distance_to_cover;
	
	// changing cm to m
	float jump_length = jump_length_cm / 100.0;
	float rest_threshold = rest_threshold_cm / 100.0;

	// input validation
	if (jump_length <= 0 || rest_threshold <= 0 || distance_to_cover <= 0) {
		std::cout << "Inputs need to be positive integers!";
		return 0;
	}

	// calculations
	float distance_covered = 0;
	float current_jump = jump_length;
	int jump_number = 0;


	while (distance_covered < distance_to_cover && current_jump > rest_threshold) {
		int i = 0;
		// make 5 jumps
		while (distance_covered < distance_to_cover && i < 5) {
			distance_covered += current_jump;	
			jump_number++;
			i++;
		}
		// decrease the jump length
		current_jump *= (jump_number / 5.0) / (jump_number / 5.0 + 1.0);
	}

	// output
	if (distance_covered >= distance_to_cover) {
		std::cout << "The frog will reach the destination in " << jump_number << " jumps." << std::endl; 
	} else {
		std::cout << "The frog cannot reach the destination unless it rests." << std::endl;
	}

	return 0;
}
