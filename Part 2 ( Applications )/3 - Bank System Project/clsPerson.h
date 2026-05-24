/*
Core Files:

This is the Person Class of Bank System Project

This class represents a person in the bank system, which can be a client 
or a user. It contains properties such as first name, last name, email, 
and phone number. The class provides getter and setter methods for each 
property, as well as a method to return the full name of the person and a 
method to print the person's information. This class serves as a base 
class for other classes that represent specific types of people in the 
bank system, such as clients and users. It encapsulates common attributes 
and behaviors that are shared among different types of people in the 
system, allowing for code reuse and better organization of the codebase.

*/

#pragma once

#include <iostream>
#include <string>

using namespace std;

class clsPerson  
{

private:
   
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
 
    clsPerson( string FirstName, string LastName, string Email, string Phone)
    {
        
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    //Property Set
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    //Property Get
    string GetFirstName()
    {
        return _FirstName;
    }

    //Property Set
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    //Property Get
    string GetLastName()
    {
        return _LastName;
    }

    //Property Set
    void SetEmail(string Email)
    {
        _Email = Email;
    }

    //Property Get
    string GetEmail()
    {
        return _Email;
    }


    //Property Set
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    //Property Get
    string GetPhone()
    {
        return _Phone;
    }


    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\nFull Name: " << FullName();
        cout << "\nEmail    : " << _Email;
        cout << "\nPhone    : " << _Phone;
        cout << "\n___________________\n";

    }

};
