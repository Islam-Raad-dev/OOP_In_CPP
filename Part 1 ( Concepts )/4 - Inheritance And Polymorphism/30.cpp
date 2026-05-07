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

    void 

};

int main()
{

    clsiPhone iPhone1;


    return 0;
}