/*

Object And Vector

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