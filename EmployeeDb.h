#ifndef EMPLOYEEDB_H_INCLUDED
#define EMPLOYEEDB_H_INCLUDED
#include <string>
#include <vector>
#include"Employee.h"

using namespace std;
class EmployeeDb : public Employee
{
public:
    EmployeeDb();
    void LoadInfo(string filePath);//send obj
    void AddEmployee(Employee& e);
    void SaveEmployee(string filepath);
    void Editemployee(int Id, Employee& e);
    void deleteEmployee(int Id);
    void DisplayEmployeeInfo();
    void DisplayBySalary();
    void SortByName();
    void SortBySalary();
    Employee& SearchByName(string name);
    Employee& SearchByPosition(string position);
    Employee& SearchBySalary(double Min, double Max);
    Employee& SearchById(int Id);
    void AdjustByAmount(double amount);
    void AdjustByPercentage(double percentage);
    /*
    void DisplayPosition()const;
    void DisplayName()const;*/
private:
    // vector<Employee>employee;//object;
};
#endif // EMPLOYEE_H_INCLUDED
