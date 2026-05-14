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

void AddNewClient()
{
string AccountNumber = "";

        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExists(AccountNumber))
        {

            cout << "\nAccount Number Is Not Found, Choose Another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        ReadCleintInfo(NewClient);

        cout << "\nAdd New Client Info: ";
        cout << "\n------------------------\n";

        Client.ReadCleintInfo(Client);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = Client.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svSucceeded:
        {
            cout << "\n\nAccount Added Successfully :-\n";
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
    return 0;
}