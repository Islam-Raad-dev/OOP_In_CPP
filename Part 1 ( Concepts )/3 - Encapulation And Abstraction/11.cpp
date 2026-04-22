/*

Constructors:

A constructor is a special member function of a class that is automatically
called when an object of the class is created. It is used to initialize the
object's data members and set up any necessary resources. Constructors have
the same name as the class and do not have a return type, not even void. They
can be defined with parameters to allow for different ways of initializing
objects. If no constructor is explicitly defined, the compiler provides a
default constructor that initializes data members to default values
Constructors can also be overloaded, meaning that a class can have multiple
constructors with different parameter lists to provide various ways of
initializing objects. The main purpose of a constructor is to ensure that an
object is in a valid state when it is created, and to simplify the process of
object initialization for the programmer.

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
