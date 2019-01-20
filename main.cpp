#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

class Database
{
    private:
        struct Student
        {
            std::string _name {""};
            std::string _surname {""};
            int _index {0};

            Student(std::string name, std::string surname, int index)
            : _name(name), _surname(surname), _index(index) {}
        };
    private:
        std::vector<Student> data;
        std::vector<Student>::iterator getIteratorToStudent(const int index);
    public:
        void addStudent(const std::string name, const std::string surname, const int index);
        void printStudents();
        void sortStudents();
        bool findStudentByIndex(const int index);
        bool delStudentByIndex(const int index);

        friend std::ostream& operator<<(std::ostream& os, const Student& student);
        friend bool compare(const Student& leftSide, const Student& rightSide);
};

void Database::addStudent(std::string name, std::string surname, int index)
{
    Student student(name, surname, index);
    data.push_back(student);
}

void Database::printStudents()
{
    for(const auto& student : data)
        std::cout << student;
    std::cout << "\n";
}

bool compare(const Database::Student& leftSide, const Database::Student& rightSide)
{
    return leftSide._index < rightSide._index;
}

void Database::sortStudents()
{
    std::sort(data.begin(), data.end(), compare);
}

bool Database::findStudentByIndex(const int index)
{
    auto iterator = getIteratorToStudent(index);
    
    if(iterator != data.end())
    {
        std::cout << *iterator << "\n";
        return true;
    }
    else
    {
        std::cout << index << " not found in database\n";
        return false;
    }
}

std::vector<Database::Student>::iterator Database::getIteratorToStudent(const int index)
{
    //lambda expression
    auto iterator = std::find_if(data.begin(), data.end(),
                                [&index](const Student& student)
                                { return student._index == index; }
                                );
    return iterator;
}

bool Database::delStudentByIndex(const int index)
{
    auto iterator = getIteratorToStudent(index);

    if(iterator != data.end())
    {
        data.erase(iterator);
        return true;
    }
    else
    {
        std::cout << "Invalid index\n";
        return false;
    }
}


std::ostream& operator<<(std::ostream& os, const Database::Student& student)
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
    
    std::cout << "--Print all:--\n";
    base.printStudents();
    std::cout << "--Sort all:--\n";
    base.sortStudents();
    base.printStudents();

    std::cout << "--Find:--\n";
    base.findStudentByIndex(33333);

    std::cout << "--Delete:--\n";
    base.printStudents();
    base.delStudentByIndex(33333);
    base.printStudents();

return 0;
}
