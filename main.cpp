#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

class Student
{
    private:
        std::string _name {""};
        std::string _surname {""};
        int _index {0};
    
    public:
        Student(std::string name, std::string surname, int index)
            : _name(name), _surname(surname), _index(index) {}

        friend std::ostream& operator<<(std::ostream& os, const Student& student);
        friend bool compare(const Student& leftSide, const Student& rightSide);
};

bool compare(const Student& leftSide, const Student& rightSide);

class Database
{
    private:
        std::vector <Student> data;

    public:
        void addStudent(const std::string name, const std::string surname, const int index);
        void delStudent(const std::string name, const std::string surname, const int index);
        void sortStudents();
        void printStudents();
};



void Database::addStudent(std::string name, std::string surname, int index)
{
    Student student(name, surname, index);
    data.push_back(student);
}

void Database::sortStudents()
{
    std::sort(data.begin(), data.end(), compare);
}

void Database::printStudents()
{
    for(const auto& student : data)
        std::cout << student;
    std::cout << "\n";
}

bool compare(const Student& leftSide, const Student& rightSide)
{
    return leftSide._index < rightSide._index;
}


std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << std::left << std::setw(13) << student._surname << " "
       << std::left << std::setw(9) << student._name << " "
       << std::left << std::setw(7) << student._index << "\n";
    return os;
}



int main(){
    std::cout << "\nProject1: StudentDatabase\n\n";
    
    Database base;

    base.addStudent("Adam",  "Malinowski",  12345);
    base.addStudent("Tomek", "Kowalski",    55555);
    base.addStudent("Kamil", "Dabrowski",   33333);
    base.addStudent("Ada",   "Kwiatkowska", 22222);

    base.printStudents();
    base.sortStudents();
    base.printStudents();

return 0;
}
