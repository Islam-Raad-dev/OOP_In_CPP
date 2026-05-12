/*

Bank Project

*/
#include <iostream>
#include<clsPerson.h>
#include <clsBankClient.h>

using namespace std;

int main()
{
    clsBankClient Client1 = clsBankClient::Find("A100");
    Client1.Print();

    return 0;

}