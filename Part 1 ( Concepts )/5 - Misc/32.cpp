/*

Friend Functions

*/
#include <iostream>
using namespace std;

class clsA
{

private:

    int _Var1;

protected:

    int Var3;

public:

    int Var2;
    clsA()
    {
        _Var1 = 10;
        Var2 = 20;
    }

    friend void Display(clsA A1);
};

void Display(clsA A1)
