/*

Acces Specifiers (Modifiers) In Inheritance

*/
#include<iostream>  
using namespace std;

class clsA
{

private:

    int Var1;
    void Function1()
    {
        cout << "Function 1.";
    }

protected:

    int Var1;
    void Function2()
    {
        cout << "Function 2.";
    }

public:



};

class clsB : public clsA
{

public:

    int Var3;
    void Function3()
    {
        cout << "Function 3.";
    }

};

int main()
{

    clsA A;

    return 0;
}