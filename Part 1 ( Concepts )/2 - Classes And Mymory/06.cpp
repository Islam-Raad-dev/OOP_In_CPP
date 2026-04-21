/*

Properties Get / Set:

In C++, properties are not a built-in language feature like in some other
programming languages (e.g., C#). However, you can achieve similar
functionality using getter and setter functions. These functions allow you to
control access to class members (variables) and provide a way to read and
modify their values while maintaining encapsulation.

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