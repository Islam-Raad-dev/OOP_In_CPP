/*

Passing Oject To Function By (Rev / Val)
 
*/
#include <iostream>
using namespace std;

class clsA
{

public:

    int X;

    void Print()
    {
        cout << "The Value Of X = " << X << endl;
    
    }

    void Func1(clsA A1)
    {
        A1.X = 100;
    }

    void Func2(clsA &A1)
    {
        A1.X = 200;
    }
};

int main()
{

    clsA A1;

    A1.X = 50;
    cout << "A Value Before Calling Function:\n";
    A1.Print();


    A1.Func1(A1);
    cout << "\nA Value After Calling Function 1:\n";
    A1.Print();

    A1.Func2(A1);
    cout << "\nA Value After Calling Function 2:\n";
    A1.Print();


    return 0;
}