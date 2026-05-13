/*

Bank Project

*/
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;
void ReadCleintInfo(clsBankClient &Client)
{

    
}

void UpdateClient()
{

    string AccountNumber = "";

    cout << "\nPlease Enter Client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExists(AccountNumber))
    {

        cout << "\nAccount Number Is Not Found, Choose Another One: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "\nUpdate Client Info: ";
    cout << "\n------------------------\n";

    ReadCleintInfo(Client);

    clsBankClient::enSaveResult SaveResult;

    SaveResult = Client.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResult::svSucceeded:

        break;

    case clsBankClient::enSaveResult::svFailed:

        break;

    default:
        break;
    }
}

int main()
{
    clsBankClient Client1 = clsBankClient::Find("A101");
    Client1.Print();

    UpdateClient();
    return 0;
}