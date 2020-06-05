#include <iostream>
#include<stdexcept>
#include<string>

// setters
void Student::setNames(const std::string& new_names) {
    names = new_names;
};
void Student::setSurname(const std::string& new_surname) {
    surname = new_surname;
};
void Student::setId(const std::string& new_id) {
    id = std::stoi(new_id);
};
void Student::setYear(const std::string& new_year)  {
    year = std::stoi(new_year);
};
void Student::setAge(const std::string& new_age) {
    age = std::stoi(new_age);
};
void Student::setAvg(const std::string& new_avg) {
    avg = std::stof(new_avg);
};

// getters
std::string Student::getNames() const {
    return names;
};
std::string Student::getSurname() const {
    return surname;
};
int Student::getId() const {
    return id;
};
int Student::getYear() const {
    return year;
};
int Student::getAge() const {
    return age;
};
float Student::getAvg() const {
    return avg;
};

// operators
bool Student::operator==(const Student& rhs) const {
    return id == rhs.id;
}
bool Student::operator>(const Student& rhs) const {
    return id > rhs.id;
}