/*

Sparate Class In Library:


*/
/*

Parameterized Constructor Of The Base Class

*/
#include<iostream>  
using namespace std; 



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