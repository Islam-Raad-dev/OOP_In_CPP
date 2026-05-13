#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <clsString.h>
#include "clsPerson.h"

using namespace std;

class clsBankClient : public clsPerson
{

private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1
    };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;

        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
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
        MyFile.open("/home/islam-raad/Projects/OOP_In_CPP/Part 2 ( Applications )/3 - Bank System Project/Clients.txt", ios::in); // read Mode

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
        MyFile.open("/home/islam-raad/Projects/OOP_In_CPP/Part 2 ( Applications )/3 - Bank System Project/Clients.txt", ios::out); // overwrite

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
        svSucceeded = 1
    };

    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            return enSaveResult::svFaildEmpteObject;

        case enMode::UpdateMode:
            _Update();
            return enSaveResult::svSucceeded;
        }

        return enSaveResult::svFaildEmpteObject;
    }

    static bool IsClientExists(string AccountNumber)

    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        return (!Client1.IsEmpty());
    }
};