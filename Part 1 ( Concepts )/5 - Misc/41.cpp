/*

Object With Paramerterized Constuctor And Array

*/
#include <iostream>
#include <vector>
using namespace std;

class clsA
{

    public:

    clsA(int Value)
    {
        X = Value;
    }

    int X;

    void Print()
    {
        cout << "The Value Of X = " << X << endl;
    }

};

int main()
{

    clsA obj[] = { clsA(10), clsA(20), clsA(30)};

    for(int i = 0; i < 3; i++)
    {
        obj[i].Print();
    }

    return 0;

}
