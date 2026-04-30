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

    clsPerson()
    {


    }

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

    string GetFirstName()
    {
        cout << _FirstName << endl;
        return _FirstName;
    }
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    string GetLastName()  
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

    string GetPhone()
    {
        cout << _Phone << endl;
        return _Phone;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
        
    }

    string GetEmail()
    {
        cout << _Email << endl;
        return _Email;
    }

    void SetID(int ID)
    {
        _ID = ID;
    }

    int GetID()
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
        cout << "INFO :" << endl;
        cout << "______________________________" << endl;
        cout << "First Name: " << _FirstName ;
        cout << "\nLast Name: " << _LastName ;
        cout << "\nFull Name: " << FullName();
        cout << "\nPhone: " << _Phone;
        cout << "\nEmail: " << _Email;
        cout << "\nID: " << _ID ;  
        cout << "\n______________________________" << endl;

    }

};

class clsEmployee : public clsPerson
{

private:

    string _Title;
    string _Department;
    double _Salary;

public:

    void SetTitle(string Title)
    {
        _Title = Title;
    }

    string GetTitle()
    {
    
        return _Title;
    }

    void SetDepartment(string Department)
    {
        _Department = Department;
    }

    string GetDepartment()
    {
    
        return _Department;
    }

    void SetSalary(double Salary)
    {
        _Salary = Salary;
    }

    double GetSalary()
    {
    
        return _Salary;
    }


    

}; 

int main()
{ 
    clsEmployee Employee1;

    Employee1.SetFirstName("Islam");
    Employee1.SetLastName("Raad");

    Employee1.PrintInfo();

    Employee1.SetSalary(3200);
    cout << Employee1.GetSalary() << endl;

    return 0;  

}