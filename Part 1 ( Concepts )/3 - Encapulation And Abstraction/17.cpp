/*

Employee Exercise:

*/
#include <iostream>
using namespace std;

class clsEmployee
{

private:

    int _ID;
    string _FirstName;
    string _LastName;
    string _Title;
    double _Salary;
    string _Department;
    string _Phone;
    string _Email;

public:

    clsEmployee(int ID, string FirstName, string LastName, string Title, double Salary, string Department, string Phone, string Email)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Title = Title;
        _Salary = Salary;
        _Department = Department;
        _Phone = Phone;
        _Email = Email;
    }

    void SetID(int ID)
    {
        _ID = ID;
    }

    int GetID()
    {
        return _ID;
    }

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string GetFirstName()
    {
        return _FirstName;
    }

    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    string GetLastName()
    {
        return _LastName;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void SetTitle(string Title)
    {
        _Title = Title;
    }

    string GetTitle()
    {
        return _Title;
    }

    void SetSalary(double Salary)
    {
        _Salary = Salary;
    }

    double GetSalary()
    {
        return _Salary;
    }

    void SetDepartment(string Department)
    {
        _Department = Department;
    }

    string GetDepartment()
    {
        return _Department;
    }   







    



};