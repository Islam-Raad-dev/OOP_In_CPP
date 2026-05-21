/*

Bank System Project
  
Author: Islam Raad
Date: 21-5-2026

Bank System Project is a console-based application that simulates a simple
banking system. It allows users to log in, view their account details, and
perform various banking operations such as deposits, withdrawals, and
transfers. The project is designed to demonstrate the use of object-oriented
programming concepts in C++.
        
*/
#include <iostream>   
#include "clsLoginScreen.h"
using namespace std;
              
int main()
{
    while(true)
    {
        if(!clsLoginScreen::ShowLoginScreen())
            break;
    }
    return 0;
}