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
        Var3 = 30;
    }

    friend int MySum(clsA A1);
};

int MySum(clsA A1)
{
    
    return A1.Var2 + A1.Var3 + A1._Var1;
}

int main()
{

    clsA A1;

    cout << MySum(A1) << endl;

    return 0;
}
