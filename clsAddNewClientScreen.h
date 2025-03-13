#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient &Client)
    {
        string temp;
        float Ftemp;
        cout << "\nEnter Firstname:";
        temp = clsInputValidate::ReadString();
        Client.setFirstName(temp);
        cout << "\nEnter Laststname:";
        temp = clsInputValidate::ReadString();
        Client.setLastName(temp);
        cout << "\nEnter Email:";
        temp = clsInputValidate::ReadString();
        Client.setEmail(temp);
        cout << "\nEnter Phone:";
        temp = clsInputValidate::ReadString();
        Client.setPhone(temp);
        cout << "\nEnter Pincode:";
        temp = clsInputValidate::ReadString();
        Client.setPinCode(temp);
        cout << "\nEnter Account Balance:";
        Ftemp = clsInputValidate::ReadFloatNumber();
        Client.setAccountBalance(Ftemp);
    }
    static void _ScreenHeader()
    {
        string Title = "\t Add New Client Screen";
        _DrawScreenHeader(Title);
    }
    static void _PrintClient(clsBankClient cli)
    {
        cout << "\nClient Card:";
        cout << "\n____________________________________________";
        cout << "\nFirstName     : " << cli.getFirstName();
        cout << "\nLastName      : " << cli.getLastName();
        cout << "\nFullName      : " << cli.FullName();
        cout << "\nEmail         : " << cli.getEmail();
        cout << "\nPhone         : " << cli.getPhone();
        cout << "\nAcc. Number   : " << cli.getAccountNumber();
        cout << "\nPassword      : " << cli.getPinCode();
        cout << "\nBalance       : " << cli.getAccountBalance();
        cout << "\n____________________________________________\n";
    }

public:
    static void AddNewClient()
    {
        _ScreenHeader();
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::isClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose an another AccountNubmer";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClinetObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        case clsBankClient::enSaveResults::svFailedEmptyObject:
            cout << "\nError account was not saved its Empty\n";
            break;
        case clsBankClient::enSaveResults::svFailedAccountNumberExists:
            cout << "\nFailed to Save, Account is already in use\n";
            break;
        }
    }
};