#include<iostream>
#include<stdexcept>
#include<fstream>
#include<string>
#include<sstream>
#include "list.hpp"
#include "student.hpp"

void appendStudent(const Student& stud);
void printStudentsFromYear(const SortedList<Student>& list, int year);
float calculateMeanAge(const SortedList<Student>& list);
void printHighestAvg(const SortedList<Student>& list);
void saveSortedList(const SortedList<Student>& list, std::string output_file);


int main() {
    std::string user_input="continue";
    std::string names, surname, id, year, age, avg, line;

    while(user_input != "exit") {
        std::cout << "Input file name (input exit to end): ";
        std::cin >> user_input;

        // exit clause
        if(user_input == "exit") break;


        SortedList<Student> list;
        // file reading
        std::ifstream input_file (user_input, std::ifstream::in); 
        while(input_file.good()) {
            getline(input_file, line);

            // finding the position of space character after names
            int counter = 5;
            int after_names_position = line.length();
            while(counter > 0 && after_names_position != std::string::npos) {
                printf("Looking\n");
                after_names_position = line.rfind(" ", after_names_position - 1);
                counter--; 
            }

            std::cout << "Position: " << after_names_position << std::endl;
            // invalid input - wrong number of elements to read
            if(after_names_position == std::string::npos) {
                std::cout << "Could not find the end of names in line: " << line << std::endl;
                continue;
            }

            // parse the line
            std::istringstream partial(line.substr(after_names_position + 1));
            names = line.substr(0, after_names_position);
            partial >> surname >> id >> year >> age >> avg;

            try {
                Student new_student;
                new_student.setNames(names);
                new_student.setSurname(surname);
                new_student.setId(id);
                new_student.setYear(year);
                new_student.setAge(age);
                new_student.setAvg(avg);
            } catch(std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }

        std::cout << "What do you want to do with the file?\n";
        std::cout << "Append student "

    };

    return 0;
}