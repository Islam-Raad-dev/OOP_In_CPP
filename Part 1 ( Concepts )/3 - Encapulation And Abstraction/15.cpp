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

    int Function2()
    {
        return 20;
    }
};

int main()
{
    clsA A;

    cout << clsA::Function() << endl;
    cout << A.Function2() << endl;

    return 0;

}