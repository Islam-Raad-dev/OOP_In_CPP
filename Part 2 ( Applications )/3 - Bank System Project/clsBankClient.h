#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <clsString.h>
#include "clsPerson.h"
#include "clsInputValidate.h"

using namespace std;

class clsBankClient : public clsPerson
{

private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2,
        DeleteMode = 3
    };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool MarkedForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;

        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.GetFirstName() + Seperator;
        stClientRecord += Client.GetLastName() + Seperator;
        stClientRecord += Client.GetEmail() + Seperator;
        stClientRecord += Client.GetPhone() + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.GetPinCode() + Seperator;
        stClientRecord += to_string(Client.GetAccountBalance());

        return stClientRecord;
    }

    static vector<clsBankClient> _LoadClientDateFormFile()
    {
        vector<clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("/home/islam-raad/Projects/OOP_In_CPP/Part 2 ( Applications )/3 - Bank System Project/Clients.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return vClients;
    }

    static void _SaveCleintsDataToFile(vector<clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("/home/islam-raad/Projects/OOP_In_CPP/Part 2 ( Applications )/3 - Bank System Project/Clients.txt", ios::out);

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                DataLine = _ConverClientObjectToLine(C);
                MyFile << DataLine << endl;
            }

            MyFile.close();
        }
    }

    void _Update()
    {

        vector<clsBankClient> _vClient;

        _vClient = _LoadClientDateFormFile();

        for (clsBankClient &C : _vClient)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }

        _SaveCleintsDataToFile(_vClient);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    static void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("/home/islam-raad/Projects/OOP_In_CPP/Part 2 ( Applications )/3 - Bank System Project/Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return _Mode == enMode::EmptyMode;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n-----------------------------------";
        cout << "\nFirst Name      : " << GetFirstName();
        cout << "\nLast Name       : " << GetLastName();
        cout << "\nFull Name       : " << FullName();
        cout << "\nPhone           : " << GetPhone();
        cout << "\nEmail           : " << GetEmail();
        cout << "\nAccount Number  : " << _AccountNumber;
        cout << "\nPin Code        : " << _PinCode;
        cout << "\nAccount Balance : " << _AccountBalance;
        cout << "\n-----------------------------------\n";
    }

    static clsBankClient Find(string AccountNumber)
    {
        vector<clsBankClient> vClients;
        fstream MyFile;

        MyFile.open("/home/islam-raad/Projects/OOP_In_CPP/Part 2 ( Applications )/3 - Bank System Project/Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);

                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        vector<clsBankClient> vClients;
        fstream MyFile;

        MyFile.open("/home/islam-raad/Projects/OOP_In_CPP/Part 2 ( Applications )/3 - Bank System Project/Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);

                if (Client.AccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    enum enSaveResult
    {
        svFaildEmpteObject = 0,
        svSucceeded = 1,
        svFaildAccountNumberExist = 2
    };

    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:

            if (IsEmpty())
            {
                return enSaveResult::svFaildEmpteObject;
            }

        case enMode::UpdateMode:
        {
            _Update();

            return enSaveResult::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            if (clsBankClient::IsClientExists(_AccountNumber))
            {
                return enSaveResult::svFaildAccountNumberExist;
            }

            else
            {
                _AddNew();

                _Mode = enMode::UpdateMode;

                return enSaveResult::svSucceeded;
            }
        }

        default:
            return enSaveResult::svFaildEmpteObject;
        }
    }

    static bool IsClientExists(string AccountNumber)

    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        return (!Client1.IsEmpty());
    }

    bool Delete()
    {
        vector<clsBankClient> _vClient;
        _vClient = _LoadClientDateFormFile();

        for (clsBankClient &C : _vClient)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C.MarkedForDelete = true;
                break;
            }
        }
        _SaveCleintsDataToFile(_vClient);

        *this = _GetEmptyClientObject();

        return true;
    }

    void ReadCleintInfo(clsBankClient &Client)
    {
        cout << "\nEnter FirstName: ";
        Client.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName: ";
        Client.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        Client.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        Client.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter PinCode: ";
        Client.SetPinCode(clsInputValidate::ReadString());

        cout << "\nEnter Account Balance: ";
        Client.SetAccountBalance(clsInputValidate::ReadDblNumber());
    }

    static void UpdateClient()
    {

        string AccountNumber = "";

        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExists(AccountNumber))
        {

            cout << "\nAccount Number Is Not Found, Choose Another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        Client.Print();

        cout << "\nUpdate Client Info: ";
        cout << "\n------------------------\n";

        Client.ReadCleintInfo(Client);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = Client.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svSucceeded:
        {
            cout << "\n\nAccount Updated Successfully :-\n";
            Client.Print();
            break;
        }

        case clsBankClient::enSaveResult::svFaildEmpteObject:
        {
            cout << "\nError Account Was Not Saved Because It's Empty.";
            break;
        }
        }
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector<clsBankClient> GetClientList()
    {
        return _LoadClientDateFormFile();
    }

    static void AddNewClient()
    {
        string AccountNumber = "";

        cout << "\nAdd New Client Info: ";
        cout << "\n------------------------\n";

        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExists(AccountNumber))
        {

            cout << "\nThis Account Number Is Exist Found, Choose Another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        NewClient.ReadCleintInfo(NewClient);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svSucceeded:
        {
            cout << "\n\nAccount Added Successfully :-\n";
            NewClient.Print();
            break;
        }

        case clsBankClient::enSaveResult::svFaildEmpteObject:
        {
            cout << "\nError Account Was Not Saved Because It's Empty.";
            break;
        }
        }
    }

    static clsBankClient GetDeleteNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::DeleteMode, "", "", "", "", AccountNumber, "", 0);
    }

    static void DeleteClient()
    {
        string AccountNumber = "";

        cout << "\nDelete New Client Info: ";
        cout << "\n------------------------\n";

        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExists(AccountNumber))
        {

            cout << "\nAccount Number Is Not Found, Choose Another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        Client.Print();

        cout << "\nAre You Sure That You Want To Delete This Client? (y/n) ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\nClient Deleted Succeesfully. \n";

                Client.Print();
            }

            else
            {
                cout << "|nError Client Was Not Deleted.\n";
            }
        }
    }

    void PrintClientRecordIsLine(clsBankClient Client)
    {
    }

    static void ShowListClient()
    {
        vector<clsBankClient> vClient = clsBankClient::GetClientList();

        cout << "\n\t\t\t\t\tClient List (" << vClient.size() << ") Clients\n\n";
        cout << "_________________________________________________________________________________________________\n";

        cout << "| " << left << setw(15) << "AccoutNumber";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";

        cout << "\n_________________________________________________________________________________________________"
             << endl;

        for (clsBankClient Client : vClient)
        {
            cout << "| " << left << setw(15) << Client.AccountNumber();
            cout << "| " << left << setw(20) << Client.FullName();
            cout << "| " << left << setw(12) << Client.GetPhone();
            cout << "| " << left << setw(20) << Client.GetEmail();
            cout << "| " << left << setw(10) << Client.GetPinCode();
            cout << "| " << left << setw(12) << Client.GetAccountBalance();
            cout << endl;
        }

        cout << "_________________________________________________________________________________________________\n"
             << endl;
    }
};