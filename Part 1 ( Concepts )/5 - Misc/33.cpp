/*

Structure Inside Class

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

    struct clsB
    {

        int Var3;
        int Var4;

        clsB()
        {
            Var3 = 30;
            Var4 = 40;
        }
    };

    clsB B1;
};

int main()
{

    clsA A1;

    cout << A1.Var2 << endl;
    cout << A1.B1.Var3 << endl;
    cout << A1.B1.Var4 << endl;

    return 0;
}