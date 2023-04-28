#include <iostream>
#include"EmployeeDb.h"
#include<fstream>
#include<string>
void DisplayMenue();
int getChoice();
int main()
{
    EmployeeDb db;
    Employee e;
    string filepath = "data.txt";
    db.LoadInfo(filepath);
    while (true) {
        cout << "-------Employee Management System------\n"
            "1-ADD Employee \n"
            "2-Edit Employee Record \n"
            "3-Delete Employee Record \n"
            "4-Search for Employee Record By Name \n"
            "5-Search Employee Record By Position \n"
            "6-Search Employee Record By Salary \n"
            "7-Display Employee Information \n"
            "8-Display Employee Information By Salary \n"
            "9-Sort Employee By Name \n"
            "10-Sort Employee By Salary \n"
            "11-Adjust Employee Record By Fixed Amount \n"
            "12-Adjust Employee Record By Percentage \n"
            "13-Exit \n"
            "====Enter your Choice==== : \n";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
        {
            cout << "Enter Employee Details :(Name->Position->Id->Salary) \n";
            string Name, Position;
            int Id;
            double Salary;
            cin >> Name >> Position >> Id >> Salary;
            Employee e(Name, Position, Id, Salary);
            db.AddEmployee(e);
            db.SaveEmployee(filepath);
            cout << "Employee Record Added Successfully ! \n";
            break;
        }
        case 2:
        {
            int Id;
            cout << "Enter Employee Id : \n";
            cin >> Id;
            Employee a = db.SearchById(Id);
            //a.display();
            string Name, Position;
            double Salary;
            cout << "Enter Your New Information :(Name->Position->Salary) \n";
            cin >> Name >> Position >> Salary;
            a.setName(Name);
            a.setPosition(Position);
            a.setSalary(Salary);
            db.Editemployee(Id, a);
            db.SaveEmployee(filepath);
            a.display();
            cout << "Employee Record Edited ! \n";
            break;
        }
        case 3:
        {
            int Index;
            cout << "Enter Employee Index : \n";
            cin >> Index;
            db.deleteEmployee(Index);
            db.SaveEmployee(filepath);
            cout << "Employee Record Deleted Successfully ! \n";
            break;
        }
        case 4:
        {
            string name;
            cout << "Enter Name :\n";
            cin >> name;
            Employee e = db.SearchByName(name);
            e.display();
            break;
        }

        case 5:
        {
            string position;
            cout << "Enter position :\n";
            cin >> position;
            Employee e = db.SearchByPosition(position);
            e.display();
            break;
        }
        case 6:
        {
            double Min, Max;
            cout << "Enter Range (Min & Max) :\n";
            cin >> Min >> Max;
            Employee e = db.SearchBySalary(Min, Max);
            e.display();
            break;
        }
        case 7:
        {
            db.DisplayEmployeeInfo();
            break;

        }
        case 8:
        {
            db.DisplayBySalary();
            break;

        }
        case 9:
        {
            db.SortByName();
            db.SaveEmployee(filepath);
            cout << "Record has been Sorted ! \n";
            break;
        }
        case 10:
        {
            db.SortBySalary();
            db.SaveEmployee(filepath);
            cout << "Record has been Sorted ! \n";
            break;

        }
        case 11:
        {
            double amount;
            cout << "Enter amount : \n";
            cin >> amount;
            db.AdjustByAmount(amount);
            db.SaveEmployee(filepath);
            cout << "Salary is adjusted ! \n";
            break;
        }
        case 12:
        {
            double percentage;
            cout << "Enter percentage : \n";
            cin >> percentage;
            db.AdjustByPercentage(percentage);
            db.SaveEmployee(filepath);
            cout << "Salary is adjusted ! \n";
            break;
        }
        case 13:
            return 0;
        default:
            cout << "invalid info !\n";
            break;

        }



    }


}
 
