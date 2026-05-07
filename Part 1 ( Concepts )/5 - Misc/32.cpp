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

    friend void Display(clsA A1);
};

int MySum(clsA A1){

    return 0;

}

int main()
{
    return 0;
}
