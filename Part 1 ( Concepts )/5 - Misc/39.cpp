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

int main()
{

    vector<clsA> V1;
    short NumberOfObject = 5;

    for (short i = 0; i < NumberOfObject; i++)
    {
        V1.push_back(clsA(i));
    }


    for(short i = 0; i < NumberOfObject; i++)
    {
        V1[i].Print();
    }

    return 0;
}