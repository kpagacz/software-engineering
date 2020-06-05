#include<iostream>
#include<stdexcept>
#include<fstream>
#include<string>
#include<sstream>
#include "list.hpp"
#include "student.hpp"

void appendStudentToFile(const Student& new_student, const std::string& file_name);
void printStudentsFromYear(SortedList<Student> list, int year);
float calculateMeanAge(SortedList<Student> list);
void printHighestAvg(SortedList<Student> list);
void saveSortedList(const SortedList<Student>& list, std::string output_file);
SortedList<Student> read_file(const std::string& input_file);

int main() {
    std::string user_input="continue";

    while(true) {
        // input choice
        char choice;
        std::cout << "What do you want to do?\n";
        std::cout << "A - Append student to the file" << std::endl;
        std::cout << "P - print students from a specific year" << std::endl;
        std::cout << "M - calculate the mean of grades!" << std::endl;
        std::cout << "B - print a student with the highest grade average" << std::endl;
        std::cout << "S - create a new file with students data sorted by id" << std::endl;
        std::cout << "e - end the program" << std::endl;
        std::cin >> choice;

        switch(choice)
        {
        case 'A':
        {
            std::string file_name;
            std::string names, surname, id, year, age, avg, line;
            std::cout << "Input file name: ";
            std::cin >> file_name;

            std::cout << "Input names, surname, id, year, age and avg of a student to append" << std::endl;
            std::cin.ignore();
            getline(std::cin, line);
            // finding the position of space character after names
            int counter = 5;
            int after_names_position = line.length();
            while(counter > 0 && after_names_position != std::string::npos) {
                after_names_position = line.rfind(" ", after_names_position - 1);
                counter--; 
            }

            // invalid input - wrong number of elements to read
            if(after_names_position == std::string::npos) {
                std::cout << "Could not find the end of names in line: " << line << std::endl;
                continue;
            }

            // parse the line
            std::istringstream partial(line.substr(after_names_position + 1));
            names = line.substr(0, after_names_position);
            partial >> surname >> id >> year >> age >> avg;

            Student new_student;
            try {
                new_student.setNames(names);
                new_student.setSurname(surname);
                new_student.setId(id);
                new_student.setYear(year);
                new_student.setAge(age);
                new_student.setAvg(avg);
            } catch(std::exception &e) {
                std::cout << e.what() << std::endl;
            }

            appendStudentToFile(new_student, file_name);
            std::cout << "Succesfully appended student to the file." << std::endl;
            break;
        }

        case 'P':
        {
            std::cout << "Input file name:";
            std::string file_name;
            std::cin >> file_name;
            SortedList<Student> list = read_file(file_name);
            int year;
            std::cout << "Input year: ";
            std::cin >> year;
            printStudentsFromYear(list, year);
        }
            break;   

        case 'M':
        {
            std::cout << "Input file name:";
            std::string file_name;
            std::cin >> file_name;
            SortedList<Student> list = read_file(file_name);
            float mean = calculateMeanAge(list);
            std::cout << "Mean of all ages: " << mean << std::endl;
        }
            break;

        case 'B':
        {
            std::cout << "Input file name:";
            std::string file_name;
            std::cin >> file_name;
            SortedList<Student> list = read_file(file_name);
            std::cout << "Highest grade student: " << std::endl;
            printHighestAvg(list);
        }
            break;

        case 'S':
        {
            std::cout << "Input file name:";
            std::string file_name;
            std::cin >> file_name;
            SortedList<Student> list = read_file(file_name);
            std::string output_file;
            std::cout << "Input output file name: ";
            std::cin >> output_file;
            saveSortedList(list, output_file);            
        }
            break;

        case 'e':
            return 0;

        default:
            std::cout << "Wrong input!" << std::endl;
            break;
        }

    };

    return 0;
}


void appendStudentToFile(const Student& new_student, const std::string& file_name) {
    std::ofstream ofs(file_name, std::ofstream::app);
    if(!ofs.good()) {
        throw std::invalid_argument("File not found.");
    }
    ofs << new_student.getNames() << " " << new_student.getSurname() << " " << new_student.getId() << " " 
        << new_student.getYear() << " " << new_student.getAge() << " " << new_student.getAvg() << std::endl;
    ofs.close();
};

SortedList<Student> read_file(const std::string& user_input) {
    // list initialization
    SortedList<Student> list;
    std::string names, surname, id, year, age, avg, line;

    // file reading
    std::ifstream input_file (user_input, std::ifstream::in); 
    while(input_file.good()) {
        getline(input_file, line);

        // finding the position of space character after names
        int counter = 5;
        int after_names_position = line.length();
        while(counter > 0 && after_names_position != std::string::npos) {
            // printf("Looking\n");
            after_names_position = line.rfind(" ", after_names_position - 1);
            counter--; 
        }

        // std::cout << "Position: " << after_names_position << std::endl;
        // invalid input - wrong number of elements to read
        if(after_names_position == std::string::npos) {
            std::cout << "Could not find the end of names in line: " << line << std::endl;
            continue;
        }

        // parse the line
        std::istringstream partial(line.substr(after_names_position + 1));
        names = line.substr(0, after_names_position);
        partial >> surname >> id >> year >> age >> avg;

        Student new_student;
        try {
            new_student.setNames(names);
            new_student.setSurname(surname);
            new_student.setId(id);
            new_student.setYear(year);
            new_student.setAge(age);
            new_student.setAvg(avg);
            list.push(new_student);
        } catch(std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return list;
};

void printStudentsFromYear(SortedList<Student> list, int year){
    SortedList<Student>::InputIt it = list.begin();
    while(it != nullptr) {
        if(it.operator->().getYear() == year) {
            std::cout << it.operator->();
        }
        it.next();
    }
};

float calculateMeanAge(SortedList<Student> list) {
    SortedList<Student>::InputIt it = list.begin();
    float age = 0;
    int size = list.getSize();
    while(it != nullptr) {
        age += it.operator->().getAge();
        it.next();
    }

    return age / size;
};

void printHighestAvg(SortedList<Student> list) {
    SortedList<Student>::InputIt it = list.begin();
    int highestIndex = 0;
    float highest_avg = 0;
    while(it != nullptr) {
        if(it.operator->().getAvg() > highest_avg) {
            highestIndex = it.operator->().getId();
            highest_avg = it.operator->().getAvg();
        }
        it.next();
    }

    it = list.begin();
    while(it != nullptr) {
        if(it.operator->().getId() == highestIndex) {
            std::cout << it.operator->();
            break;
        }
        it.next();
    }    
};

void saveSortedList(const SortedList<Student>& list, std::string output_file) {
    std::ofstream ofs(output_file, std::ios::out);
    if(!ofs.is_open()) {
        std::cout << "Cannot open file" << std::endl;
        return;
    }
    ofs << list;
    ofs.close();
};
