/*


Virtual Functions


*/
#include <iostream>
using namespace std;

class clsPerson
{

public:
    void Print()
    {
        cout << "Hi I'm A Perosn\n";
    }
};

class clsEmployee : public clsPerson
{

public:
    void Print()
    {
        cout << "Hi I;m A Employee!\n";
    }
};

int main()
{


    return 0;
}