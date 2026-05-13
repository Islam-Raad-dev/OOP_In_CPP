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
    Client.SetFirstName(clsInputValidate::ReadString());

    cout << "\nEnter LastName: ";
    Client.SetLastName(clsInputValidate::ReadString());

    cout << "\nEnter Email: ";
    Client.SetEmail(clsInputValidate::ReadString());

    cout << "\nEnter Phone: ";
    Client.SetPhone(clsInputValidate::ReadString());

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
    {
        cout << "\n\nAccount Updated Successfully :-\n";
        Client.Print();
        break;

    }

    case clsBankClient::enSaveResult::svFaildEmpteObject:
    {
        cout << "\nError Account Was Not Saved Because It's Empty.";  
        break;

    }

    }
}

int main()
{
    UpdateClient();
    return 0;
}