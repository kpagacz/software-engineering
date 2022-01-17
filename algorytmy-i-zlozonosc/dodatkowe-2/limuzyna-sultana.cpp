#include <iostream>
#include <vector>
#include <algorithm>

int main(int, char* []) {
	int stages_no;
	stages_no = 3;
	int* l1_stage_times = new int [] { 8, 5, 10 };
	int* l2_stage_times = new int [] { 5, 10, 1};
	int* move_times = new int [] { 0, 2, 3 };

	// l1_summ_time, l2_summ_time:
	// best times of finishing previous stages of construction
	// using line 1 and 2 for the previous stage
	// l1_summ_time - best time of finishing previous stages, if the last stage was done on line 1
	// l2_summ_time - best time of finishing previous stages, if the last stage was done on line 2
	int l1_summ_time, l2_summ_time;
	l1_summ_time = l2_summ_time = 0;
	int temp = 0;

	// paths contain information about which stages to complete on which line
	// ith position of the path indicates: complete a stage on line 1 (0), complete a stage on line 2 (1)
	int* l1_path = new int [stages_no] {0};
	int* l2_path = new int [stages_no] {0};
	int* temp_path = new int [stages_no] {0};

	for (int i = 0; i < stages_no; i++) {
		temp = l1_summ_time;
		std::memcpy(temp_path, l1_path, i);

		// update l1_summ_time and l1_path
		if (l1_summ_time + l1_stage_times[i] < l2_summ_time + move_times[i] + l1_stage_times[i]) {
			l1_summ_time += l1_stage_times[i];
			l1_path[i] = 0;
		}
		else {
			l1_summ_time = l2_summ_time + move_times[i] + l1_stage_times[i];
			std::memcpy(l1_path, l2_path, i);
			l1_path[i] = 1;
		}

		// update l2_summ_time and l2_path
		if (l2_summ_time + l2_stage_times[i] < temp + move_times[i] + l2_stage_times[i]) {
			l2_summ_time += l2_stage_times[i];
			l2_path[i] = 1;
		}
		else {
			l2_summ_time = temp + move_times[i] + l2_stage_times[i];
			std::memcpy(l2_path, temp_path, i);
			l2_path[i] = 0;
		}
	}

	// output
	if (l1_summ_time < l2_summ_time) {
		std::cout << "Minimal time: " << l1_summ_time << "\n";
		std::cout << "Complete stages on lines: ";
		for (int i = 0; i < stages_no; i++)
			std::cout << l1_path[i] << " ";
	}
	else {
		std::cout << "Minimal time: " << l2_summ_time << "\n";
		std::cout << "Complete stages on lines: ";
		for (int i = 0; i < stages_no; i++)
			std::cout << l2_path[i] << " ";
	}
	std::cout << "\n";

	return 0;
}