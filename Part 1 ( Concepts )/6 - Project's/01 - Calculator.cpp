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
    }

};

int main()
{

    clsCalculator Calculator1;

    return 0;
}