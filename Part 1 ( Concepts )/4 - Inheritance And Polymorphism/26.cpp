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

};

int main()
{

    return 0;
}