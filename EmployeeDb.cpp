#include"EmployeeDb.h"
#include"Employee.h"
#include <iostream>
#include<fstream>
#include<algorithm>
using namespace std;
vector<Employee>employee;
EmployeeDb::EmployeeDb() {}

void EmployeeDb::LoadInfo(string filePath)
{
    ifstream myfile(filePath);
    if (!myfile) {
        throw runtime_error("Error opening file");
    }
    string Name;
    string Position;
    int Id;
    double Salary;
    while (myfile >> Name >> Position >> Id >> Salary)
    {
        employee.emplace_back(Name, Position, Id, Salary);

    }
    myfile.close();
}


void EmployeeDb::AddEmployee(Employee& e)
{
    employee.push_back(e);

}
void EmployeeDb::SaveEmployee(string filepath)
{
    ofstream myfile(filepath);
    if (!myfile) {
        throw runtime_error("Error opening file");
    }
    for (const auto& e : employee)
    {
        myfile << e.getName() << " " << e.getPosition() << " " << e.getId() << " " << e.getSalary();
    }

}
void EmployeeDb::Editemployee(int Id, Employee& e)
{
    employee[Id] = e;

}
void EmployeeDb::deleteEmployee(int Id)
{
    employee.erase(employee.begin() + Id);
}
void EmployeeDb::DisplayEmployeeInfo()
{
    for (auto& e : employee)
    {
        cout << "\n -----Employee----- \n";
        e.display();
    }
}
void EmployeeDb::DisplayBySalary() {
    vector<Employee> sortedEmployees = employee;
    sort(sortedEmployees.begin(), sortedEmployees.end(), [](const Employee& a, const Employee& b) {
        return a.getSalary() < b.getSalary();
        });
    for (const Employee& e : sortedEmployees) {
        cout << "\n -----Employee----- \n";
        e.display();
    }
}

void EmployeeDb::SortByName()
{
    sort(employee.begin(), employee.end());

}
void EmployeeDb::SortBySalary()
{
    sort(employee.begin(), employee.end(), [](const Employee& a, const Employee& b) {
        return a.getSalary() < b.getSalary();
        });
}
Employee& EmployeeDb::SearchByName(string name)
{
    for (auto& e : employee) {
        if (e.getName() == name) {
            return e;
        }
    }
    throw runtime_error("Employee not found");

}

Employee& EmployeeDb::SearchByPosition(string position)
{
    for (auto& e : employee) {
        if (e.getPosition() == position) {
            return e;
        }
        else {
            throw runtime_error("Employee not found");
        }
    }
    
}
Employee& EmployeeDb::SearchBySalary(double Min, double Max)
{
    for (auto& e : employee) {
        if (e.getSalary() >= Min && e.getSalary() <= Max) {
            return e;
        }
    }
    throw runtime_error("Employee not found");

}
Employee& EmployeeDb::SearchById(int Id) {
    for (auto& e : employee) {
        if (e.getId() == Id) {
            return e;
        }
    }
    throw runtime_error("Employee not found");
}

void EmployeeDb::AdjustByAmount(double amount)
{
    for (auto& e : employee) {
        e.setSalary(amount + e.getSalary());
    }
}
void EmployeeDb::AdjustByPercentage(double percentage)
{
    for (auto& e : employee) {
        e.setSalary((1 + percentage / 100) * e.getSalary());
    }
}



