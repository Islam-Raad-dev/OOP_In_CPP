/*

Nested Classes Exerise

*/
#include <iostream>
using namespace std;

class clsPerson
{

    class clsAddress
    {
    public:
        string AddressLine1;
        string AddressLine2;
        string City;
        string State;
        string Country;

        void PrintAddress()
        {
            cout << "Address:\n\n";
            cout << "Address Line 1 = " << AddressLine1 << endl;
            cout << "Address Line 2 = " << AddressLine2 << endl;
            cout << "City = " << City << endl;
            cout << "State = " << State << endl;
            cout << "Country = " << Country << endl;
        }
    };

public:

    string FullName;
    clsAddress Address;

    clsPerson()
    {
        FullName = "Islam Raad";
        Address.AddressLine1 = "123 Main St";
        Address.AddressLine2 = "Apt 4B";
        Address.City = "Moaul";
        Address.State = "Ninawa";
        Address.Country = "Iraq";
    }
};

int main()
{
    clsPerson Person1;

    Person1.Address.PrintAddress();

    return 0;
}