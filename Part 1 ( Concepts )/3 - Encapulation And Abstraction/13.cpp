/*

Destructors:

A destructor is a special member function of a class that is executed when an
object of that class goes out of scope or is explicitly deleted. The purpose
of a destructor is to perform any necessary cleanup tasks, such as releasing
resources or memory that the object may have acquired during its lifetime.

*/
#include <iostream>
using namespace std;

class clsPerson
{
private:
    string _FullName;

public:
    // Constructor
    clsPerson()
    {
        cout << "Hi, I'm Constructor" << endl;
    }

    // Destructor
    ~clsPerson()
    {
        cout << "Hi, I'm Destructor" << endl;
    }
};

void Function()
{
    clsPerson Person1;
}

int main()
{
    Function();

    return 0;
};