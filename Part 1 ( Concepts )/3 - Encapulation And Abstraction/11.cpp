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

    clsAddress()
    {
        _AddresLine1 = "N/A";
        _AddressLine2 = "N/A";
        _POBox = "N/A";
        _ZipCode = "N/A";
    }
    
    void SetAddressLine1(string AddressLine1)
    {
        _AddresLine1 = AddressLine1;
    }

    string AddressLine1()
    {
        return _AddresLine1;
    }

    void SetAddressLine2(string AddressLine2)
    {
        _AddressLine2 = AddressLine2;
    }

    string AddressLine2()
    {
        return _AddressLine2;
    }

    void SetPOBox(string POBox)
    {
        _POBox = POBox;
    }

    string POBox()
    {
        return _POBox;
    }

    void SetZipCode(string ZipCode)
    {
        _ZipCode = ZipCode;
    }

    string ZipCode()
    {
        return _ZipCode;
    }

    void Print()
    {
        cout <<"Address Details: "<< endl;
        cout << "----------------" << endl;
        cout << "Address Line 1 : " << _AddresLine1 << endl;
        cout << "Address Line 2 : " << _AddressLine2 << endl;
        cout << "PO Box         : " << _POBox << endl;
        cout << "Zip Code       : " << _ZipCode << endl;
    }
};

int main()
{
    clsAddress Address;

    Address.Print();

    return 0;
}
