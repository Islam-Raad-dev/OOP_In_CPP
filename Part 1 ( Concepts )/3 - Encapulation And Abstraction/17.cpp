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

    







    



};