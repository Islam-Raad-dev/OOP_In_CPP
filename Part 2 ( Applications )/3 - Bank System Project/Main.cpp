/*

Bank Project

*/
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;
void ReadCleintInfo(clsBankClient &Client)
{

    cout << "\nEnter FirstName: ";
    Client.GetFirstName() = clsInputValidate::ReadString();

    cout << "\nEnter LastName: ";
    Client.GetLastName() = clsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    Client.GetEmail() = clsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    Client.GetPhone() = clsInputValidate::ReadString();

    cout << "\nEnter PinCode: ";
    Client.SetPinCode(clsInputValidate::ReadString());

    cout << "\nEnter Account Balance: ";
    Client.SetAccountBalance(clsInputValidate::ReadDblNumber());
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

    case clsBankClient::enSaveResult::svFaildEmpteObject:
    
        break;

    default:
        break;
    }
}

int main()
{
    UpdateClient();
    return 0;
}