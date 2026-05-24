/*
Screen Files:

This is Transfer Screen of Bank System Project

This screen allows users to transfer funds between two existing clients 
in the bank system. It prompts the user to enter the account numbers of 
the source and destination clients, and if both account numbers exist, 
it displays the information of both clients. The user is then asked to 
enter the transfer amount, which must be less than or equal to the 
available balance of the source client. If all validations pass, the 
screen attempts to perform the transfer and provides feedback on whether 
the operation was successful or if there were any errors.

*/

#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExists(AccountNumber))
        {
            cout << "\nAccount Number Is Not Found, Choose Another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount: ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.GetAccountBalance())
        {
            cout << "\nAmount Exceeds The Available Balance, Enter another Amount : ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }

public:
    static void ShowTransferScreen()
    {

        _DrawScreenHeader("\tTransfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(DestinationClient);

        float Amount = ReadAmount(SourceClient);

        cout << "\nAre You Sure You Want To Perform This Operation (y/n): ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, ""))
            {
                cout << "\nTransfer Done Successfully\n";
            }
            else
            {
                cout << "\nTransfer Failed \n";
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
    }
};
