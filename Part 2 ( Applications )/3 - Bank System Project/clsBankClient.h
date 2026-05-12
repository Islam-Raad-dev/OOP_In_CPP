#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<clsString.h>
#include<clsPerson.h>

using namespace std;

class clsBankClient : public clsPerson
{

private:

    enum enMode {EmptyMode = 0, UpdateMode = 1};
    enMode _Mode;


    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;

public:



};