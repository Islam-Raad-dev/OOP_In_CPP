/*

Person Exercise

*/
#include <iostream>
using namespace std;

class clsPerson
{
    clsPerson()
    {
        _ID = 10;
        _FirstName = "Islam";
        _LastName = "Raad";
        _Phone = "123456789";
        _Email = "IslamRaad@gmail.com";
        
    }
    
private:
    string _FirstName;
    string _LastName;
    string _Phone;
    string _Email;
    int _ID;

public:

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string GetFirstName()
    {
        cout << _FirstName << endl;
        return _FirstName;
    }
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    string GetLastName()
    {
        cout << _LastName << endl;
        return _LastName;
    }

    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    string GetPhone()
    {
        cout << _Phone << endl;
        return _Phone;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
        
    }

    string GetEmail()
    {
        cout << _Email << endl;
        return _Email;
    }

    void SetID(int ID)
    {
        _ID = ID;
    }

    int GetID()
    {
        cout << _ID << endl;
        return _ID;
    
    }

    void SendEmail(string Message)
    {
        cout << "The Folloing Message "<< Message << " Sent Seccesfully To Email:" << _Email << endl;
    }

    void SendSMS()
    {
        cout << "Sending SMS..." << endl;
    }


    void PrintInfo()
    {
        cout << "INFO :" << endl;
        cout << "______________________________" << endl;
        cout << "First Name: " << _FirstName ;
        cout << "\nLast Name: " << _LastName ;
        cout << "\nPhone: " << _Phone;
        cout << "\nEmail: " << _Email;
        cout << "\nID: " << _ID ;
        cout << "\n______________________________" << endl;

    }

};

int main(){

    clsPerson Person1(10, "Islam", "Raad", "123456789", "IslamRaad@gmail.com");

    Person1.PrintInfo();

    Person1.SendEmail("Hi, How Are You?");
    Person1.SendSMS("Hi, How Are You Nigga");

    return 0;

}