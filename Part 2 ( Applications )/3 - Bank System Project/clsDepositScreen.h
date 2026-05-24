/*
Screen Files:

This is Deposit Screen of Bank System Project

This screen is responsible for allowing the user to deposit money into a
client's account. It prompts the user to enter the account number of
the client they wish to deposit money into, verifies that the account
number exists, and then displays the client's information. The user is
then asked to enter the amount they wish to deposit. If confirmed, the
amount is added to the client's account balance and a success message is
displayed. If not confirmed, the transaction is canceled.

*/

#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{

private:
    
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExists(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] Does Not Exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease Enter Deposit Amount: ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre You Sure That You Want To Preforme This Transaction(y/n): ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.GetAccountBalance();

        }
        else
        {
            cout << "\nOperation Was Cancelled.\n";
        }

    }

};
