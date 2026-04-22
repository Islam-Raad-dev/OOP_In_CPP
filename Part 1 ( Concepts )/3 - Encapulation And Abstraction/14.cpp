/*

Static Members

*/
#include <iostream>
#include <string>
using namespace std;

class clsA
{

public:

    int var;
    static int counter;

    clsA()
    {
        counter++;
    }

    void Print(){
        cout << "\nvar: " << var ;
        cout << "\n counter: " << counter << endl;
    }


};

int main()
{
    clsA a1;
    a1.var = 10;
    a1.Print();

    clsA a2;
    a2.var = 20;
    a2.Print();

    clsA a3;
    a3.var = 30;
    a3.Print();

    return 0;
};