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
};

int main()
{

    clsPerson Person1;


    return 0;
}