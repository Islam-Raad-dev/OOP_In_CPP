/*

Access Specifiers (Modifiers):

1 - Public.
2 - Praivte
3 - Protected

In C++, access specifiers (also known as access modifiers) are keywords that
define the accessibility of class members (variables and functions). The three
main access specifiers are:

*/
#include <iostream> 
using namespace std;

class clsPerson
{

private:

    int Variabl1 = 5;
    int Function1()
    {
        return 40;
    }

protected:

    int Variable2 = 100;
    int Function2()
    {
        return 50;
    }

public:



};

int main()
{
    clsPerson Person1;


    return 0;
}