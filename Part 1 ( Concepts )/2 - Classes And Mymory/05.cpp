/*

Access Specifiers (Modifiers):

1 - Public,
2 - Private,
3 - Protected.

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

    int Variabl2 = 100;

    int Function2()
    {
        return 50;
    }

public:

    string FirstName;
    string LastName;

    string FullName()
    {
        return FirstName + " " + LastName;
    }

    float Function3()
    {
        return Function1() * Variabl1 * Variabl2;
    }
    

};

int main()
{
    clsPerson Person1;

    Person1.FirstName = "Islam";
    Person1.LastName = "Raad";

    cout << "Preson1: "<< Person1.FullName()<< endl;

    cout << Person1.Function3() << endl;


    return 0;
}