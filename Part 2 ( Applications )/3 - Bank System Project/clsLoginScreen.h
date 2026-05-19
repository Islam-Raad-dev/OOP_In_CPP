#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private :

  static  bool _Login()
    {
        bool LoginFaild = false;
        short LoginAttempts = 0;

        string Username, Password;
        do
        {
     
            if (LoginFaild)
            {
                LoginAttempts++;

                cout << "\nInvalid Username / Password!\n\n";
                cout << "You Have " << 3 - LoginAttempts << " Attempts Left.\n\n";
            }

            if(LoginAttempts == 3)
            {
                cout << "You Are Locked After 3 Failed Attempts.\n";
                return false;
            }

            cout << "Enter Username: ";
            cin >> Username;

            cout << "Enter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        clsMainScreen::ShowMainMenue();
        return true;

    }

public:


    static bool ShowLoginScreen()
    {
        system("clear");
        _DrawScreenHeader("\t  Login Screen");
        _Login();

    }

};

