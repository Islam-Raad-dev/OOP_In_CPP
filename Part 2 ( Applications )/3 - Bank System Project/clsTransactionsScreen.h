/*
Screen Files:

This is Transactions Screen of Bank System Project

This screen serves as a central hub for various banking transactions that 
users can perform in the bank system. It provides a menu with options for 
depositing funds, withdrawing funds, viewing total balances, transferring 
funds between accounts, and viewing the transfer log. The screen checks 
the user's access rights before allowing them to perform any transactions. 
Each option in the menu leads to a specific screen that handles the 
corresponding transaction type, ensuring a structured and organized flow 
for users to manage their banking activities effectively.

*/

#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include "clsUser.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{

private:
    enum enTransactionsMenueOptions
    {
        eDeposit = 1,
        eWithdraw = 2,
        eShowTotalBalance = 3,
        eTransfer = 4,
        eTransferLog = 5,
        eShowMainMenue = 6
    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "\t\t\t\tEnter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
        _GoBackToTransactionsMenue();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
        _GoBackToTransactionsMenue();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
        _GoBackToTransactionsMenue();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
        _GoBackToTransactionsMenue();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
        _GoBackToTransactionsMenue();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        cin.ignore();
        cin.get();
        ShowTransactionsMenue();
    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("clear");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("clear");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("clear");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransfer:
        {
            system("clear");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransferLog:
        {
            system("clear");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowMainMenue:
        {
            // Nothing here Because The Main Screen Will Handle It :-) ;
        }
        }
    }

public:
    static void ShowTransactionsMenue()
    {

        system("clear");

        if(!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }

        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }
};
