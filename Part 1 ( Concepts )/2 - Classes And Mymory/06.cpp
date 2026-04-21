/*

Properties Get / Set:

In C++, properties are not a built-in language feature like in some other
programming languages (e.g., C#). However, you can achieve similar
functionality using getter and setter functions. These functions allow you to
control access to class members (variables) and provide a way to read and
modify their values while maintaining encapsulation.

*/
#include <iostream> 
using namespace std;

class clsPerson
{

private:


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

    Person1.setFirstName("Islam");
    Person1.setLastName("Raad");

    cout << "First Name: " << Person1.FirstName() << endl;
    cout << "Last Name: " << Person1.LastName() << endl;
    cout << "Full Name: "<< Person1.FullName()<< endl;


    return 0;
}