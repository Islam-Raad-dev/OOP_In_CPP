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
        cout << "Hi I'm A Employee!\n";
    }
};

class clsStudent : public clsEmployee
{

public:

    void Print(){
        cout << "J\Hi, I'm A Student!\n";
    }
};
int main()
{


    return 0;
}