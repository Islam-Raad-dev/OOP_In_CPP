/*

Properties Get And Set Through "=":

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

    __declspec(property(get = GetFirstName, put = setFirstName)) string FirstName;

};

int main()
{
    clsPerson Person1;

    Person1.setFirstName("Islam");
    cout << Person1.GetFirstName() << endl;

    Person1.FirstName = "Raad";
    cout << Person1.FirstName << endl;



    return 0;
}