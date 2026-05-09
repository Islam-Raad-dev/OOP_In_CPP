/*

Sparate Class In Library:


*/
/*

Parameterized Constructor Of The Base Class

*/
#include<iostream> 
#include"clsPerson.h" 
#include"clsEmployee.h"
using namespace std; 

 

int main()
{ 
    clsEmployee Employee1(10, "Islam", "Raad", "07718277643", "islamraad43", "ML Ops", "Artificial Intelligence", 4000);

    Employee1.PrintInfo();
    cout << Employee1.Salary() << endl;
 

    return 0;  

}