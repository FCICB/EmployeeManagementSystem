#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;
Employee::Employee() {}
 
Employee::Employee(string name, string position, int id, double salary)
    :Name(name), Position(position), Id(id), Salary(salary) {} //intialize

string Employee::getName() const
{
    return this->Name;
}
string Employee::getPosition()const
{
    return this->Position;
}
int Employee::getId()const
{
    return Id;
}
double Employee::getSalary()const
{
    return Salary;
}
void Employee::setName(string name)
{
    Name = name;
}
void Employee::setPosition(string position)
{
    Position = position;
}
void Employee::setId(int id)
{
    Id = id;
}
void Employee::setSalary(double salary)
{
    Salary = salary;
}
void Employee::display()const
{
    cout << "Name : " << Name << endl;
    cout << "Position : " << Position << endl;
    cout << "ID : " << Id << endl;
    cout << "Salary :" << Salary << endl;
}
bool Employee::operator<(const Employee& other)const
{
    return this->Name < other.Name;
}
 
bool Employee::operator>(const Employee& other)const
{
    return this->Name > other.Name;
}
bool Employee::operator==(const Employee& other)const
{
    return this->Name == other.Name;
}
