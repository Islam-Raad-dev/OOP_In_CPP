/*

Classes And Objects:

Classes: A Blueprint For Creating Objects That Defines The Properties And Behaviors Of The Objects.

Objects: An Instance Of A Class That Contains The Data And Functions Defined In The Class.

*/

#include <iostream>
using namespace std;

class clsPerson 
{
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

    Person1.FirstName = "John";
    Person1.LastName = "Doe";

    cout << Person1.FullName();


    return 0;
}