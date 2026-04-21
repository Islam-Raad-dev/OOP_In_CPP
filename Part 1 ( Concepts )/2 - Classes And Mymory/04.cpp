/*

Object In Memory: 

When We Create An Object From A Class, The Object Is Stored In Memory. The Memory Used By The Object Depends On The Data Members Defined In The Class.

*/
#include <iostream> 
using namespace std;

class clsPerson 
{

private:
    short Age;

public:
    string FirstName;
    string LastName;

    string FullName()
    {
        return FirstName + " " + LastName;
    }

};

int main()
{
    clsPerson Person1;

    Person1.FirstName = "Islam";
    Person1.LastName = "Raad";

    cout << Person1.FullName() << endl;


    return 0;
}