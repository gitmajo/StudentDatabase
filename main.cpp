#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
};

class Database
{
    private:
        std::vector <Student> data;

    public:
        void addStudent(const std::string name, const std::string surname, const int index);
        void delStudent(const std::string name, const std::string surname, const int index);
     
};

void Database::addStudent(std::string name, std::string surname, int index)
{
    Student student(name, surname, index);
    data.push_back(student);
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
    
    Database studentBase; 

    studentBase.addStudent("Adam",  "Malinowski",  12345);
    studentBase.addStudent("Tomek", "Kowalski",    55555);
    studentBase.addStudent("Kamil", "Dabrowski",   33333);
    studentBase.addStudent("Ada",   "Kwiatkowska", 22222);




return 0;
}
