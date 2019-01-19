#include <iostream>
#include <string>

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


int main(){
    std::cout << "\nProject1: StudentDatabase\n\n";
    
    Student Adam("Adam", "Malinowski",  12345);
    Student Tomek("Tomek", "Kowalski",  55555);
    Student Kamil("Kamil", "Dabrowski", 33333);
    Student Ada("Ada", "Kwiatkowska",   22222);


return 0;
}
