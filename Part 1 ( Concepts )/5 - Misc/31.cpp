/*

Friend Classes

*/
#include <iostream>
using namespace std;

class clsA
{

private:
    int _Var1;

public:
    int Var2;
    clsA()
    {
        _Var1 = 10;
        Var2 = 20;
    }
};

class clsB
{

public:
    void Display(clsA A1)
    {
        cout << endl << "The Value Of X = " << A1.Var2 << endl;
    }
};

int main()
{
    clsA A1;
    clsB B1;

    B1.Display(A1);

    return 0;
}