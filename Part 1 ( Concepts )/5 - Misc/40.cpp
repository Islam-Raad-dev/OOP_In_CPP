/*


Object And Dynamic Array


*/
#include <iostream>
using namespace std;

class clsA
{

public:

    clsA()
    {
    }

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

    int NumberOfObject = 5;
    clsA *arrA = new clsA[NumberOfObject];

    for (short i = 0; i < NumberOfObject; i++)
    {
        arrA[i] = clsA(i);
    }

    for (short i = 0; i < NumberOfObject; i++)
    {
        arrA[i].Print();
    }

    delete[] arrA;

    return 0;
}