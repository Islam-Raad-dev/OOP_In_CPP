/*

Properties Get And Set Through "=":

*/
#include <iostream>
using namespace std;

class clsPerson
{

private:

    int _ID = 10;

    string _FirstName;
    string _LastName;

public:


    int ID()// Get: This Is Read Only Property Because We Don't Have Set Function For It
    {
        return _ID;
    }

    void setFirstName(string FirstName)// Set
    {
        _FirstName = FirstName;

    }

    string FirstName()// Get
    {
        return _FirstName;
    }

    void setLastName(string LastName)// Set
    {
        _LastName = LastName;
    }

    string LastName()// Get
    {
        return _LastName;
    }

    
    string FullName()
    {
        return FirstName() + " " + LastName();
    }
    

};

int main()
{
    clsPerson Person1;

    Person1.setFirstName("Islam");
    Person1.setLastName("Raad");

    cout << "First Name: " << Person1.FirstName() << endl;
    cout << "Last Name: " << Person1.LastName() << endl;
    cout << "Full Name: "<< Person1.FullName()<< endl;
    cout << "ID: " << Person1.ID() << endl;



    return 0;
}