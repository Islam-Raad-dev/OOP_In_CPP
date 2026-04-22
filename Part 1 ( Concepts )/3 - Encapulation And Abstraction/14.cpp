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
        cout << "var: " << var ;
        cout << "\ncounter: " << counter << endl;
    }


};

int clsA::counter = 0;

int main()
{
    clsA A1;

    A1.Print();

    return 0;
};