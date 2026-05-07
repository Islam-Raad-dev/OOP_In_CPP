/*


Inheritance Visibility Modes:


*/
#include <iostream>
using namespace std;

class clsA
{

private:

    int V1;
    int Fun1(){
        return 1;
    }

protected:

    int V2;
    int Fun2(){
        return 2;
    }

public:

    int V3;
    int Fun3(){
        return 3;
    }

};

class clsB : private clsA
{

public:

    int V4;
    int Fun4()
    {
        clsA::
        return 4;
    }


};

int main()
{
    clsB B1;
    return 0;
}