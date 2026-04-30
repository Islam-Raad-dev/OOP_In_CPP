/*

Parameterized Constructor Of The Base Class

*/
#include<iostream>  
using namespace std; 

class clsPerson
{
    
private:
    string _FirstName;
    string _LastName;
    string _Phone;
    string _Email;
    int _ID;


public:


    clsPerson(int ID, string FirstName, string LastName, string Phone, string Email)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Phone = Phone;
        _Email = Email;
    }

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string FirstName()
    {
        cout << _FirstName << endl;
        return _FirstName;
    }
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    string LastName()  
    {
        cout << _LastName << endl;
        return _LastName;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }


    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    string Phone()
    {
        cout << _Phone << endl;
        return _Phone;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
        
    }

    string Email()
    {
        cout << _Email << endl;
        return _Email;
    }

    void SetID(int ID)
    {
        _ID = ID;
    }

    int ID()
    {
        cout << _ID << endl;
        return _ID;
    
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


    void PrintInfo()
    {
        cout << "Info :" << endl;
        cout << "______________________________" << endl;
        cout << "\nFirst Name: " << _FirstName ;
        cout << "\nLast Name: " << _LastName ;
        cout << "\nFull Name: " << FullName();
        cout << "\nPhone: " << _Phone;
        cout << "\nEmail: " << _Email;
        cout << "\nID: " << _ID ;  
        cout << "\n______________________________\n" << endl;

    }

};

class clsEmployee : public clsPerson
{

private:

    string _Title;
    string _Department;
    double _Salary;

public:

    clsEmployee(int ID, string FirstName, string LastName, string Phone, string Email, string Title, string Department, double Salary) 
        : clsPerson(ID, FirstName, LastName, Phone, Email)
    {
        _Title = Title;
        _Department = Department;
        _Salary = Salary;

    }

    void SetTitle(string Title)
    {
        _Title = Title;
    }

    string Title()
    {
    
        return _Title;
    }

    void SetDepartment(string Department)
    {
        _Department = Department;
    }

    string Department()
    {
    
        return _Department;
    }

    void SetSalary(double Salary)
    {
        _Salary = Salary;
    }

    double Salary()
    {
    
        return _Salary;
    }

}; 

int main()
{ 
    clsEmployee Employee1(10, "Islam", "Raad", "07718277643", "islamraad43", "ML Ops", "Artificial Intelligence", 4000);

    Employee1.PrintInfo();
    cout << Employee1.Salary() << endl;


    return 0;  

}