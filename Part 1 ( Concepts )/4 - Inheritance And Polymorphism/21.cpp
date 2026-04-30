/*

Developer Exerise

*/
#include<iostream>  
using namespace std; 

class clsDeveloper
{
    
private:
    string _FirstName;
    string _LastName;
    string _Phone;
    string _Email;
    int _ID;
    string _Title;
    string _Department;
    double _Salary;
    string _MainProgrammingLanguage;


public:


    clsDeveloper(int ID, string FirstName, string LastName, string Phone, string Email, string Title, string Department, double Salary, string MainProgrammingLanguage)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Phone = Phone;
        _Email = Email;
        _Title = Title;
        _Department = Department;
        _Salary = Salary;
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string FirstName()
    {
        return _FirstName;
    }
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    string LastName()  
    {

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

        return _Phone;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
        
    }

    string Email()
    {

        return _Email;
    }


    int ID()
    {

        return _ID;
    
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

    void SetMainProgrammingLanguage(string MainProgrammingLanguage)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    string MainProgrammingLanguage()
    {
        return _MainProgrammingLanguage;
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
        cout << "\nTitle: " << _Title;
        cout << "\nDepartment: " << _Department;
        cout << "\nSalary: " << _Salary;
        cout << "\nMain Programming Language: " << _MainProgrammingLanguage;
        cout << "\n______________________________\n" << endl;

    }

};

int main()
{ 
    clsDeveloper Developer1(10, "Islam", "Raad", "07718277643", "islamraad43", "ML Ops", "Artificial Intelligence", 4000, "C++");

    Developer1.PrintInfo();

    return 0;  

}