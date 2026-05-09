/*

Fourth Principle Of OOP : Plymorphism
 
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