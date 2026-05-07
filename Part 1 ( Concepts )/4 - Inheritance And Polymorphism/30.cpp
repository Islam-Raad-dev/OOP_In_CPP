/*

Pure Virtual Functions and Abstract Classes

*/

#include <iostream>
using namespace std;

class clsMobile//Abstact Class / Interface
{

    virtual void Dial(string PhoneNumber) = 0;
    virtual void SendSMS(string PhoneNumber, string Text) = 0;
    virtual void TakePicture() = 0;

};

class clsiPhone : public clsMobile
{

public:

    void Dial(string PhoneNumber)
    {
        cout << "Dialing " << PhoneNumber << endl;

    }

    void SendSMS(string PhoneNumber, string Text)
    {
        cout << "Send SMS " << PhoneNumber << endl;
    }

    void TakePicture()
    {
        cout << "Taking Picture" << endl;
    }


};

int main()
{

    clsiPhone iPhone1;

    iPhone1.Dial("07718277643");
    iPhone1.SendSMS("07718277643", "Hello World");
    iPhone1.TakePicture();



    return 0;
}