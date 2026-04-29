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

    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }
    string GetPhone()
    {
        return _Phone;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
    }

    string GetEmail()
    {
        return _Email;
    }

    void PrintInfo()
    {
        cout << "\nInfo:" << endl;
        cout << "______________________________" << endl;
        cout << "First Name: " << _FirstName;
        cout << "\nLast Name: " << _LastName;
        cout << "\nFull Name: " << FullName();
        cout << "\nTitle: " << _Title;
        cout << "\nSalary: " << _Salary;
        cout << "\nDepartment: " << _Department;
        cout << "\nPhone: " << _Phone;
        cout << "\nEmail: " << _Email;
        cout << "\nID: " << _ID;
        cout << "\n______________________________" << endl;
    }

    void SendEmail(string Subject, string Body)
    {
        cout << "\n\nThe Folloing Message Sent Seccesfully To Email:" << _Email << endl;
        cout << "Subject: " << Subject << endl;
        cout << "Body: " << Body << endl;
    }

    void SendSMS(string TextMessage)
    {
        cout << "\n\nThe Folloing Message Sent Seccesfully To Phone: " << _Phone << "\n" << endl;
        cout << TextMessage << endl;
    }


};