/*

Structure Inside Class

*/

#include <iostream>
using namespace std;

class clsPerson
{

    struct stAddress
    {
        string AddressLine1;
        string AddressLine2;
        string City;
        string State;
        string Country;
    };

public:

    string FullName;
    stAddress Address;

    clsPerson()
    {
        FullName = "Islam Raad";
        Address.AddressLine1 = "123 Main St";
        Address.AddressLine2 = "Apt 4B";
        Address.City = "Moaul";
        Address.State = "Ninawa";
        Address.Country = "Iraq";
    }

    void PrintAddress()
    {
        cout << endl << "Address Line 1 = " << Address.AddressLine1 << endl;
        cout << endl << "Address Line 2 = " << Address.AddressLine2 << endl;
        cout << endl << "City = " << Address.City << endl;
        cout << endl << "State = " << Address.State << endl;
        cout << endl << "Country = " << Address.Country << endl;
    }
};

int main()
{

    clsPerson Person1;

    Person1.PrintAddress();

    cout << Person1.Address.City << endl;



    return 0;
}