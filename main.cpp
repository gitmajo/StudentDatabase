#include <iostream>
#include <string>
#include <vector>

class Student
{
	std::string name;
	std::string surname;
	int index;
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

return 0;
}
