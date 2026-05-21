#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "Global.h"
#include "clsInputValidate.h"
#include "clsListClientScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsMangeUsersScreen.h"
#include "clsLoginScreen.h"
#include "clsLoginRegisterScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{

private:
    enum enMainMenueOptions
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenue = 6,
        eManageUsers = 7,
        eLoginRegister = 8,
        eCurrncyExchange = 9,
        eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose What Do You Want To Do [1 to 10]: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "\t\t\t\tEnter Number Between 1 to 10: ");
        return Choice;
    }

    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\nPress any key to go back to Main Menue...\n";
        cin.ignore();
        cin.get();
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
        _GoBackToMainMenue();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
        _GoBackToMainMenue();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
        _GoBackToMainMenue();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
        _GoBackToMainMenue();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
        _GoBackToMainMenue();
    }

    static void _ShowTransactionsMenue()
    {
       clsTransactionsScreen::ShowTransactionsMenue();
       _GoBackToMainMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
        _GoBackToMainMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
        _GoBackToMainMenue();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        //clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
        _GoBackToMainMenue();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("clear");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("clear");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("clear");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("clear");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("clear");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("clear");
            _ShowTransactionsMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("clear");
            _ShowManageUsersMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("clear");
            _ShowLoginRegisterScreen();
            break;

        case enMainMenueOptions::eCurrncyExchange:
            system("clear");
            _ShowCurrencyExchangeScreen();
            break;

        case enMainMenueOptions::eExit:
            system("clear");
            _Logout();
            break;
        }
    }

public:
    static void ShowMainMenue()
    {

        system("clear");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[01] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[02] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[03] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[04] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[05] Find Client.\n";
        cout << setw(37) << left << "" << "\t[06] Transactions.\n";
        cout << setw(37) << left << "" << "\t[07] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[08] Login Resister.\n";
        cout << setw(37) << left << "" << "\t[09] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};