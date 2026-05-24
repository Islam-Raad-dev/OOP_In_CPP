/*
Screen Files:

This is the Base Screen of Bank System Project

This class serves as a base class for all screens in the Bank System 
Project. It provides common functionalities such as drawing the screen 
header and checking access rights for different features. The 
_DrawScreenHeader function is used to display the title and subtitle of 
the screen, along with the current user's name and the current date. The 
CheckAccessRights function checks if the current user has the necessary 
permissions to access a specific feature or screen, and displays an access 
denied message if they do not have the required permissions. This class 
helps to maintain consistency across different screens and ensures that 
access control is implemented effectively throughout the application.

*/

#pragma once

#include <iostream>

#include "clsDate.h"
#include "Global.h"
#include "clsUser.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
            cout << "\n\t\t\t\t\t______________________________________\n";
        cout << "\n\t\t\t\t\tUser: " << CurrentUser.GetUserName() << "\n";
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate())
            << "\n\n";
    }
    
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }
};