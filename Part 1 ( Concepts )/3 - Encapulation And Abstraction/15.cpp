/*

Static Functions (Static Methods)

*/
#include <iostream>
using namespace std;

class clsA
{

public:

    static int Function()
    {
        return 10;
    }

    static int Function2()
    {
        return 20;
    }
};

int main()
{
    cout << clsA::Function() << endl;
    cout << clsA::Function2() << endl;

    return 0;

}