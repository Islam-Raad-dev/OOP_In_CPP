/*

Pure Virtual Functions and Abstract Classes

*/

#include <iostream>
using namespace std;

class clsMobile
{

    virtual void Dial(string PhoneNumber) = 0;
    virtual void SendSMS(string Text) = 0;
    virtual void TakePicture() = 0;

};

int main()
{

    return 0;
}