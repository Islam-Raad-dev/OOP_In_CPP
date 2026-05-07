/*

Static Early Binding Vs Dynamic Late Binding
 
*/

#include <iostream>
using namespace std;

class clsPerson
{

public:
    virtual void Print()
    {
        cout << "Hi, I'm A Perosn\n";
    }
};

class clsEmployee : public clsPerson
{

public:
    void Print()
    {
        cout << "Hi, I'm A Employee!\n";
    }
};

class clsStudent : public clsPerson
{

public:
    void Print()
    {
        cout << "Hi, I'm A Student!\n";
    }
};
int main()
{
    clsEmployee Employee1;
    clsStudent Student1;

    // Early Static Binding
    Employee1.Print();
    Student1.Print();

    // Dynamic Late Binding
    clsPerson *Person1 = &Employee1;
    clsPerson *Peront2 = &Student1;
    Person1->Print();
    Peront2->Print();

    return 0;
}