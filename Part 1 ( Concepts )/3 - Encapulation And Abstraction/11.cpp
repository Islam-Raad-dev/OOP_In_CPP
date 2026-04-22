/*

Constructors:

*/
#include <iostream>
using namespace std;

class clsAddress
{
private:
    string _AddresLine1;
    string _AddressLine2;
    string _POBox;
    string _ZipCode;

public:
    void SetAddressLine1(string AddressLine1)
    {
        _AddresLine1 = AddressLine1;
    }

    string AddressLine1()
    {
        return _AddresLine1;
    }
};

int main()
{
    clsAddress Address;

    Address.Print();

    return 0;
}
