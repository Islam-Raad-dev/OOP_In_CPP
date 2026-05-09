/*

This Pointer In C++
                              
*/
#include <iostream>
using namespace std;

class clsEmployee
{

public:

    int ID;
    string Name;
    float Salary;

    clsEmployee(int ID, string Name, float Salary)
    {
        this->ID = ID;
        this->Name = Name;
        this->Salary = Salary;

    
    }

    static void Func1(clsEmployee Employee1)
    {
        Employee1.Print();
    }

    void Func2()
    {
        Func1(*this);
    }

    void Print()
    {

        cout << ID << " " << Name << " " << Salary << endl;
        cout << this->ID << " " << this->Name << " " << this->Salary << endl;

    }
};

int main()
{
    clsEmployee Employee1(1212, "Islam Raad" , 3500.5);

    Employee1.Print();



    return 0;
}