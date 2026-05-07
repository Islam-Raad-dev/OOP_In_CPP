/*


Up Casting Vs Down Casting


*/

#include<iostream>
using namespace std;

class clsPerson
{
public:

    string FullName = "Islam Raad Fathi";

};

class clsEmployee : public clsPerson
{

public:

    string Title = "CEO";
};

int main()
{

    clsEmployee Employee1;

    cout << Employee1.FullName << endl;

    //Up Casting
    clsPerson * Person1 = &Employee1;
    cout << Person1->FullName << endl;

    //Down Casting
    clsPerson Person2;
    clsEmployee *Employee2 = &Person2;

    return 0;
}