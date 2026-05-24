/*
Screen Files:

This is Currency Exchange Screen of Bank System Project

This screen is responsible for providing the user with a menu to perform
various currency-related operations, such as listing all available
currencies,finding a specific currency, updating currency exchange rates
and using currency calculator to convert amounts between different
currencies. It serves as a central hub for all currency exchange
functionalities in the application, allowing users to easily access and
manage currency information and perform

*/

#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{

private:
    enum enCurrencyExchangeMenueOptions
    {
        eListCurrencies = 1,
        eFindCurrency = 2,
        eUpdateCurrency = 3,
        eCurrencyCalculator = 4,
        eMainMenue = 5
    };

    static short ReadCurrencyExchangeMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "\t\t\t\tEnter Number between 1 to 5? ");
        return Choice;
    }

    static void _ShowListCurrenciesScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();

    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();

    }

    static void _ShowUpdateCurrencyScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();

    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }

    static void _GoBackToCurrencyExchangeMenue()
    {
        cout << setw(37) << left << "" << "\nPress any key to go back to Currency Exchange Menue...\n";
        cin.ignore();
        cin.get();
        ShowCurrencyExchangeMenue();
    }

    static void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeMenueOptions CurrencyExchangeMenueOption)
    {
        switch (CurrencyExchangeMenueOption)
        {
        case enCurrencyExchangeMenueOptions::eListCurrencies:
        {
            system("clear");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }

        case enCurrencyExchangeMenueOptions::eFindCurrency:
        {
            system("clear");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }

        case enCurrencyExchangeMenueOptions::eUpdateCurrency:
        {
            system("clear");
            _ShowUpdateCurrencyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }

        case enCurrencyExchangeMenueOptions::eCurrencyCalculator:
        {
            system("clear");
            _ShowCurrencyCalculatorScreen();
             _GoBackToCurrencyExchangeMenue();
            break;
        }

        case enCurrencyExchangeMenueOptions::eMainMenue:
        {
            // Nothing here Because The Main Screen Will Handle It :-) ;
        }
        }
    }

public:
    static void ShowCurrencyExchangeMenue()
    {

        system("clear");

        if(!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }

        _DrawScreenHeader("\t  Currency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenueOption((enCurrencyExchangeMenueOptions)ReadCurrencyExchangeMenueOption());
    }

};