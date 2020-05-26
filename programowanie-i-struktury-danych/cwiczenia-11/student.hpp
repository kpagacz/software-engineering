#ifndef STUDENT
#define STUDENT

#include<string>

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
};
#endif