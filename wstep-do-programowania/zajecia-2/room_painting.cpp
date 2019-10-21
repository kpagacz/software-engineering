#include <iostream>
#include <iomanip>

int main() {
	// input
	float room_length, room_width, room_height, window_width, window_height, door_width, door_height;
	int windows_number, doors_number;
	const float paint_liter_area = 5;
	std::cout << "Please input room length, width and height. Then number of windows, their, width and height. Then number of doors, their width and height." << std::endl;
	std::cin >> room_length >> room_width >> room_height >> windows_number >> window_width >> window_height >> doors_number >> door_width >> door_height;
	
	
	// calculations
	float total_room_area = 2 * room_length * room_height + 2 * room_width * room_height + room_width * room_height;
	float window_area = windows_number * window_width * window_height;
	float door_area = doors_number * door_width * door_height;

	float area_to_paint = total_room_area - window_area - door_area;
	float paint_volume = area_to_paint / paint_liter_area;

	// output
	std::cout << "Volume of paint needed: " << std::setprecision(2) << std::fixed << paint_volume;
	return 0;
}
