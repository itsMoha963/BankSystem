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
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        this->_FirstName = FirstName;
        this->_LastName = LastName;
        this->_Email = Email;
        this->_Phone = Phone;
    }
    void setFirstName(string fname)
    {
        this->_FirstName = fname;
    }
    string getFirstName()
    {
        return _FirstName;
    }

    void setLastName(string lname)
    {
        this->_LastName = lname;
    }
    string getLastName()
    {
        return _LastName;
    }

    void setEmail(string Email)
    {
        _Email = Email;
    }
    string getEmail()
    {
        return _Email;
    }

    void setPhone(string Phone)
    {
        _Phone = Phone;
    }
    string getPhone()
    {
        return _Phone;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }
};