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
        void addstudent(std::string name, std::string surname, int index);
        void delstudent(std::string name, std::string surname, int index);
     
};
std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << std::left << std::setw(13) << student._surname << " "
       << std::left << std::setw(9) << student._name << " "
       << std::left << std::setw(7) << student._index << "\n";
    return os;
}




int main(){
    std::cout << "\nProject1: StudentDatabase\n\n";
    
    Student Adam("Adam", "Malinowski",  12345);
    Student Tomek("Tomek", "Kowalski",  55555);
    Student Kamil("Kamil", "Dabrowski", 33333);
    Student Ada("Ada", "Kwiatkowska",   22222);

    std::cout << Adam << Tomek << Kamil << Ada;

return 0;
}
