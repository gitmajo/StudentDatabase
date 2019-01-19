#include <iostream>
#include <string>
#include <vector>

class Student
{
    private:
        std::string _name {""};
        std::string _surname {""};
        int _index {0};
    
    public:
        Student(std::string name, std::string surname, int index)
            : _name(name), _surname(surname), _index(index) {}
};

class Database
{
    public:
    void addstudent(std::string name, std::string surname, int index);
    void delstudent(std::string name, std::string surname, int index);

    private:
    std::vector <Student> data;
         
};


int main(){
    std::cout << "\nProject1: StudentDatabase\n\n";
    
    Student Adam("Adam", "Malinowski",  12345);
    Student Tomek("Tomek", "Kowalski",  55555);
    Student Kamil("Kamil", "Dabrowski", 33333);
    Student Ada("Ada", "Kwiatkowska",   22222);


return 0;
}
