/*
Screen Files:

This is the login screen of Bank System Project

This file contains the implementation of the login screen of the
application, which serves as the entry point for users to access the
banking system. The login screen prompts users to enter their username and 
password, and it validates the credentials against the stored user data. 
If the login is successful, the user is granted access to the main screen 
of the application, where they can navigate to different features and 
functionalities of the banking system. The login screen also includes a 
mechanism to handle failed login attempts, allowing users a limited number 
of tries before locking them out for security reasons. The user interface 
is designed to be simple and intuitive, providing clear instructions for 
users to log in and access their accounts. Overall, the login screen is a 
crucial component of the Bank System Project, ensuring that only 
authorized users can access the system and providing a secure entry point 
for users to interact with the application.

*/

#pragma once

#include <iostream>
#include <iomanip>


#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCount = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                FaildLoginCount++;

                cout << "\nInvlaid Username/Password!";
                cout << "\nYou have " << (3-FaildLoginCount)
                     << " Trial(s) to login.\n\n";   
            }

            if (FaildLoginCount == 3)
            {
                cout << "\nYour are Locked after 3 faild trails \n\n";
                return false;
            }

            cout << "Enter Username: ";
            cin >> Username;

            cout << "Enter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("clear");
        _DrawScreenHeader("\t    Login Screen");
        return _Login();

    }

};

