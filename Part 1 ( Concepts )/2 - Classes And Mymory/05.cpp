/*

Access Specifiers (Modifiers):

In C++, access specifiers (also known as access modifiers) are keywords that define the accessibility of class members (variables and functions). The three main access specifiers are:

*/
#include <iostream> 
using namespace std;

class clsPerson 
{

private:
    short Age;

public:
    string FirstName;
    string LastName;

    string FullName()
    {
        return FirstName + " " + LastName;
    }

};

int main()
{
    clsPerson Person1;

    Person1.FirstName = "Islam";
    Person1.LastName = "Raad";

    cout << Person1.FullName() << endl;


    return 0;
}