#ifndef STUDENT
#define STUDENT

#include<string>
#include<iostream>

class Student{
    private:
        std::string names, surname;
        int id, year, age;
        float avg;
    public:
        // constructors, destructors, assignment
        Student()=default;
        ~Student()=default;

        // setters
        void setNames(const std::string&);
        void setSurname(const std::string&);
        void setId(const std::string&);
        void setYear(const std::string&);
        void setAge(const std::string&);
        void setAvg(const std::string&);

        // getters
        std::string getNames() const;
        std::string getSurname() const;
        int getId() const;
        int getYear() const;
        int getAge() const;
        float getAvg() const;

        // operators
        bool operator==(const Student& rhs) const;
        bool operator>(const Student& rhs) const;
        friend std::ostream& operator<<(std::ostream &out, Student stud) {
            out << stud.names << " " << stud.surname << " " << stud.id << " " << stud.year 
            << " " << stud.age << " " << stud.avg << std::endl;
            return out;
        }
};

#include "student.cpp"
#endif