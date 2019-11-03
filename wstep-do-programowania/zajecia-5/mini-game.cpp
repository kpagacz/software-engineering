#include <iostream>
#include <stdlib.h>

bool single_round(int& correct_number) {
	int guess;
	std::cout << "What is your guess?\n";
	std::cin >> guess;
	std::cout << "Your guess was: " << guess << ".\n";
	if (correct_number == guess) {
		std::cout << "You guessed correctly!\n";
		return true;
	} else if (correct_number > guess) {
		std::cout << "Your guess was too low!\n";
		return false;
	} else {
		std::cout << "Your guess was too high!\n";
		return false;
	}
}


int main(){
	// input
	char choice;

	std::cout << "Guess the number between 1 and 100!!!!" << std::endl;
	std::cout << "Pick the game mode:" << std::endl;
	std::cout << "a - you have 8 tries" << std::endl;
	std::cout << "b - input number of tries" << std::endl;
	std::cout << "c - you have progressively fewer tries (strting from 32)" << std::endl;
	std::cout << "Input a single letter corresponding to a game mode:" << std::endl;
	std::cin >> choice;
	

	int number_of_tries;
	int guess;
	bool guessed = false;
	int correct_number;

	switch (choice) {
		case 'a':
			number_of_tries = 8;
			correct_number = (int)rand() % 100 + 1;

			while (number_of_tries > 0) {
				guessed = single_round(correct_number);
				if (guessed == true) {
					std::cout << "You won.";
					return 0;
				}
				number_of_tries--;
			}

			std::cout << "You lost.\n";
			return 0;
		case 'b':
			do {
				std::cout << "Enter number of tries (positive integer): ";
				std::cin >> number_of_tries;
			} while (number_of_tries <= 0);
			correct_number = (int)rand() % 100 + 1;
			while (number_of_tries > 0) {
				guessed = single_round(correct_number);
				if (guessed == true) {
					std::cout << "You won.";
					return 0;
				}
				number_of_tries--;
			}
			std::cout << "You lost.\n";
			return 0;
		case 'c':
			number_of_tries = 32;
			while (true) {
				correct_number = (int)rand() % 100 + 1;
				int inner_tries = number_of_tries;
				while (inner_tries > 0) {
					guessed = single_round(correct_number);
					if (guessed) {
						std::cout << "You won.";
						break;
					}
					inner_tries--;
				}
				number_of_tries = 1 > number_of_tries / 2 ? 1 : number_of_tries / 2;
			}
		default:
			std::cout << "Choose a game mode - a, b or c." << std::endl;
	}	
	return 0;
}
