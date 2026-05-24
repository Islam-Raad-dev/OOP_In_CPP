/*
Screen Files:

This is Find Currency Screen of Bank System Project

This screen is responsible for allowing the user to find a currency in the
bank system. It prompts the user to enter either the currency code or the
country name, verifies that the currency exists, and then displays the
currency's information.

*/

#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{

private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";
    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was Not Found :-(\n";
        }
    }

public:
    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country: ";
        short Answer = 1;

        cin >> Answer;

        while (Answer != 1 && Answer != 2)
        {
            cout << "\nInvalid Choice, Choose 1 or 2 only.\n";
            cout << "\nFind By: [1] Code or [2] Country: ";
            cin >> Answer;
        }

        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\nPlease Enter Currency Code: ";
            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else if (Answer == 2)
        {
            string Country;
            cout << "\nPlease Enter Country Name: ";
            Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }
    }
};
