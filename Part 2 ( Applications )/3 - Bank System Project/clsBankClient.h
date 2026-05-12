#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <clsString.h>
#include <clsPerson.h>

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

    static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
    {
    }
    static clsBankClient _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
    }

    static clsBankClient _GetEmptyClientObject()
    {
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

    bool IsUpdate()
    {
        return _Mode == enMode::UpdateMode;
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



    

};