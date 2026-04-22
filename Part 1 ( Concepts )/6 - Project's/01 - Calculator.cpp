/*

Simple Calculator Project: 

*/

#include<iostream>

using namespace std;

class clsCalculator
{
private:

    float _Result = 0;
    float _LastNumber = 0;
    string _LastOperation = "Clear";
    float _PrevoiusResult = 0;

    bool _IsZero(float Number){
        return (Number == 0);
    }


public:

    void Add(float Number)
    {
        _LastNumber = Number;
        _PrevoiusResult = _Result;
        _LastOperation = "Adding";
        _Result += Number;
    }

    void Subtract(float Number)
    {
        _LastNumber = Number;
        _PrevoiusResult = _Result;
        _LastOperation = "Subtracting";
        _Result -= Number;
    }

    void Multiply(float Number)
    {
        _LastNumber = Number;
        _PrevoiusResult = _Result;
        _LastOperation = "Multiplying";
        _Result *= Number;
    }

    void Divide(float Number)
    {
        if (_IsZero(Number))
        {
            return;
        }
        _LastNumber = Number;
        _PrevoiusResult = _Result;
        _LastOperation = "Dividing";
        _Result /= Number;
    }

    void CancelLastOpertion()
    {
        _LastNumber = 0;
        _LastOperation = "Cancelling Last Operation";
        _Result = _PrevoiusResult;

    }

    void PrintResult()
    {
        cout << "Result ";
        cout << "After " << _LastOperation << " " << _LastNumber << "is: " << _Result;

    }
};

int main()
{

    clsCalculator Calculator1;

    return 0;
}