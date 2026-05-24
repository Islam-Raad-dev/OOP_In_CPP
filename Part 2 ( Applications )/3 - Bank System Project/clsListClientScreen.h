/*
Screen Files:

This is Client List Screen of Bank System Project

This screen is responsible for displaying a list of all clients in the
bank system. It retrieves the client data from the system, formats it
into a readable format, and presents it to the user. The screen also 
includes a header with the title and subtitle, as well as a table with 
columns for account number, client name, phone, email, pin code, and 
balance. If there are no clients in the system, a message is displayed 
indicating that there are no clients available.

*/

#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"


class clsClientListScreen : protected clsScreen
{

private:
   static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.GetPhone();
        cout << "| " << setw(20) << left << Client.GetEmail();
        cout << "| " << setw(10) << left << Client.GetPinCode();
        cout << "| " << setw(12) << left << Client.GetAccountBalance();

    }

public:
  

   static void ShowClientsList()
    {

        if(CheckAccessRights(clsUser::enPermissions::pListClients) == false)
        {
            return;
        }

        vector <clsBankClient> vClients = clsBankClient::GetClientList();
        string Title = "\t  Client List Screen";
        string SubTitle ="\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);
        

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};
