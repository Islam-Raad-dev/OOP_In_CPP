/*

Bank Project   

*/
#include <iostream>
#include "clsBankClient.h"
#include<clsInputValidate.h>

using namespace std;

int main()
{
    clsBankClient Client1 = clsBankClient::Find("A101");
    Client1.Print();


    return 0;

}