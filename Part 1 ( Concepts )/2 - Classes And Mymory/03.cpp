/*

Class Members:

*/
#include <iostream> 
using namespace std;

class clsPerson 
{

private:
    int Age;

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