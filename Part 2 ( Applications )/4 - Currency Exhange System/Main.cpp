/*

Currency Exchange System

Author: Islam Raad
Date: 17-5-2026

Currency Exchange System is a console-based application that allows users 
to view and update currency exchange rates. The project is designed to 
demonstrate the use of file handling, object-oriented programming
concepts, and data manipulation in C++.

*/

#include <iostream>

#include "clsCurrency.h"

using namespace std;

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

int main()

{
    clsCurrency Currency1 = Currency1.FindByCode("iqd");

    if (Currency1.IsEmpty())
    {
        cout << "\nCurrency Is Not Found!\n";
    }
    else
    {
        _PrintCurrency(Currency1);
    }

    cout << "Currency1 after updating Rate:\n";
    Currency1.UpdateRate(1500);
    _PrintCurrency(Currency1);


    return 0;
}
