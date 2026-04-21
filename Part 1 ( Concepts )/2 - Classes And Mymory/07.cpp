/*

Read Only Property:

A read-only property is a property that can only be read (accessed) but cannot
be modified (written to) after it has been initialized. In C++, you can create
a read-only property by providing only a getter function and omitting the
setter function. This way, the value of the property can be accessed but not
changed directly.

*/
#include <iostream> 
using namespace std;

class clsPerson
{

private:

    int _ID = 10;
    string _FirstName;
    string _LastName;

public:

    void setFirstName(string FirstName)// Set
    {
        _FirstName = FirstName;

    }

    string FirstName()// Get
    {
        return _FirstName;
    }

    void setLastName(string LastName)// Set
    {
        _LastName = LastName;
    }

    string LastName()// Get
    {
        return _LastName;
    }

    
    string FullName()
    {
        return FirstName() + " " + LastName();
    }
    

};

int main()
{
    clsPerson Person1;

    Person1.setFirstName("Islam");
    Person1.setLastName("Raad");

    cout << "First Name: " << Person1.FirstName() << endl;
    cout << "Last Name: " << Person1.LastName() << endl;
    cout << "Full Name: "<< Person1.FullName()<< endl;


    return 0;
}