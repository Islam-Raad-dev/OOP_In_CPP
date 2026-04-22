/*

First Principle : Encapsulation

*/

#include <iostream>
using namespace std;

class clsPerson
{

private:

    string _FirstName;

public:

    void setFirstName(string FirstName)// Set
    {
        _FirstName = FirstName;

    }

    string GetFirstName()// Get
    {
        return _FirstName;
    }

};

int main()
{
    clsPerson Person1;

    Person1.setFirstName("Islam");
    cout << Person1.GetFirstName() << endl;


    return 0;
}