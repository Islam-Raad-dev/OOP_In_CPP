/*
Core Files:

This is Bank Client Class of Bank System Project 

This Class is responsible for managing the bank client data and operations
such as finding clients, adding new clients, updating client information,
deleting clients, and handling transactions. It also includes
functionality for logging transfer transactions between clients.

*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#include <clsString.h>
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsDate.h"

using namespace std;

class clsBankClient : public clsPerson
{

public:

    struct stTrnsferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float srcBalanceAfter;
        float destBalanceAfter;
        string UserName;

    };

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

    static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
    {
        stTrnsferLogRecord TrnsferLogRecord;

        vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
        TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
        TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
        TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
        TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
        TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
        TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
        TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

        return TrnsferLogRecord;

    }

        string _PrepareTransferLogRecord(float Amount,clsBankClient DestinationClient,string UserName, string Seperator = "#//#")
    {
        string TransferLogRecord = "";
        
        TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
        TransferLogRecord += AccountNumber() + Seperator;
        TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
        TransferLogRecord += to_string(Amount) + Seperator;
        TransferLogRecord += to_string(_AccountBalance) + Seperator;
        TransferLogRecord += to_string(DestinationClient.GetAccountBalance()) + Seperator;
        TransferLogRecord += UserName;

        return TransferLogRecord;
    }


    void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
    {
        string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

        fstream MyFile;
        MyFile.open("/home/islam-raad/Projects/OOP_In_CPP/Part 2 ( Applications )/3 - Bank System Project/TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

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
        {
            if (IsEmpty())
            {

                return enSaveResult::svFaildEmpteObject;
            }
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

            break;
        }

        default:
            return enSaveResult::svFaildEmpteObject;

        }

         return enSaveResult::svFaildEmpteObject;
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }

        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
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

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector<clsBankClient> GetClientList()
    {
        return _LoadClientDateFormFile();
    }

    static double GetTotalBalance()
    {

        vector<clsBankClient> vClient = clsBankClient::GetClientList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClient)
        {
            TotalBalances += Client._AccountBalance;
        }

        return TotalBalances;
    }

    static clsBankClient GetDeleteNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::DeleteMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Transfer(float Amount, clsBankClient &DestinationClient, string UserName)
    {
        if (Amount > GetAccountBalance())
        {
            return false;
        }
    
        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        _RegisterTransferLog(Amount, DestinationClient, UserName);
        return true;
    }

    static  vector <stTrnsferLogRecord> GetTransfersLogList()
    {
        vector <stTrnsferLogRecord> vTransferLogRecord;

        fstream MyFile;
        MyFile.open("/home/islam-raad/Projects/OOP_In_CPP/Part 2 ( Applications )/3 - Bank System Project/TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stTrnsferLogRecord TransferRecord;

            while (getline(MyFile, Line))
            {

                TransferRecord = _ConvertTransferLogLineToRecord(Line);

                vTransferLogRecord.push_back(TransferRecord);

            }

            MyFile.close();

        }

        return vTransferLogRecord;

    }
};