/*

Second Principle : Abstraction

*/

#include <iostream>
using namespace std;

class clsPerson
{

private:
    string _FirstName;
    string _LastName;
    string _Phone;

public:
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string GetFirstName()
    {
        return _FirstName;
    }

    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    string GetLastName()
    {
        return _LastName;
    }

    void setPhone(string Phone)
    {
        _Phone = Phone;
    }

    string GetPhone()
    {
        return _Phone;
    }

    void PrintInfo()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\nFull Name: " << _FirstName << " " << _LastName;
        cout << "\nPhone    : " << _Phone;
        cout << "\n___________________\n";
    }


};

int main()
{
    clsPerson Person1;

    Person1.setFirstName("Islam");
    Person1.setLastName("Raad");
    Person1.setPhone("123456789");

    Person1.PrintInfo();

    return 0;
}