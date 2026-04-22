/*

Simple Calculator Project:

*/

#include <iostream>

using namespace std;

class clsCalculator
{
private:
    float Result = 0;
    float LastNumber = 0;
    string LastOperation = "Clear";
    float PrevoiusResult = 0;

    bool _IsZero(float Number)
    {
        return (Number == 0);
    }

public:
    void Add(float Number)
    {
        LastNumber = Number;
        PrevoiusResult = Result;
        LastOperation = "Adding";
        Result += Number;
    }

    void Subtract(float Number)
    {
        LastNumber = Number;
        PrevoiusResult = Result;
        LastOperation = "Subtracting";
        Result -= Number;
    }

    void Multiply(float Number)
    {
        LastNumber = Number;
        PrevoiusResult = Result;
        LastOperation = "Multiplying";
        Result *= Number;
    }

    void Divide(float Number)
    {

        LastNumber = Number;

        if (_IsZero(Number))
        {
            Number = 1;
        }

        PrevoiusResult = Result;
        LastOperation = "Dividing";
        Result /= Number;
    }

    void Clear()
    {
        LastNumber = 0;
        PrevoiusResult = 0;
        LastOperation = "Clear";
        Result = 0;
    }

    float GetFinalResult()
    {
        return Result;
    }
    void CancelLastOpertion()
    {
        LastNumber = 0;
        LastOperation = "Cancelling Last Operation";
        Result = PrevoiusResult;
    }

    void PrintResult()
    {
        cout << "Result ";
        cout << "After " << LastOperation << " " << LastNumber << "is: " << Result;
    }
};

int main()
{

    clsCalculator Calculator1;

    Calculator1.Clear();

    Calculator1.Add(10);

    Calculator1.PrintResult();

    return 0;
}