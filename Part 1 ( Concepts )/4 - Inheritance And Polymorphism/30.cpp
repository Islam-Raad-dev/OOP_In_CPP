/*

Pure Virtual Functions and Abstract Classes

*/

#include <iostream>
using namespace std;

class clsPerson
{

public:
    virtual void Print() = 0;
};

class clsEmployee : public clsPerson
{

public:
    void Print()
    {
        cout << "Hi, I'm A Employee!\n";
    }
};

int main()
{

    clsEmployee Employee1;
    Employee1.Print();

    return 0;
}