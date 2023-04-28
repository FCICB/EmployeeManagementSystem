#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include <string>
using namespace std;
class Employee
{
public:
    Employee();
    Employee(string Name, string Position, int Id, double Salary);
    void setName(string Name);
    void setPosition(string Position);
    void setId(int Id);
    void setSalary(double Salary);
    string getName()const;
    string getPosition()const;
    int getId()const;
    double getSalary()const;
    void display()const;  
    bool operator <(const Employee& other)const;
    bool operator >(const Employee& other)const;
    bool operator ==(const Employee& other)const;


private:
    string Name;
    string Position;
    int Id;
    double Salary;

};


#endif  
