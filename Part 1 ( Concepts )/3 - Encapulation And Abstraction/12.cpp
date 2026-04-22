/*

Copy Constructor:

A copy constructor is a special constructor in C++ that is used to create a
new object as a copy of an existing object. It is called when an object is
initialized with another object of the same class, passed by value, or
returned from a function by value.

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

    clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode)
    {
        _AddresLine1 = AddressLine1;
        _AddressLine2 = AddressLine2;
        _POBox = POBox;
        _ZipCode = ZipCode;
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
    clsAddress Address("14 Main St", "Apt 4B", "PO Box 123", "41001");

    Address.Print();

    return 0;
}
