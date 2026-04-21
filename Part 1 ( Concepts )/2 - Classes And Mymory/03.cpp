/*

Class Members:

Class members are the variables and functions that are defined within a class. They can be accessed and used by objects of the class.

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