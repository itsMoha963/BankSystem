#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsUpdateClientScreen : protected clsScreen
{
private:
    static void _ScreenHeader()
    {
        string Title = "\t Update Client Screen";
        _DrawScreenHeader(Title);
    }
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
    static void UpdateClient()
    {
        _ScreenHeader();
        string AccountNumber = "";
        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "\nAccount number not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nUpdate Client Info:";
        cout << "\n______________________\n";

        _ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(Client1);
            break;
        case clsBankClient::enSaveResults::svFailedEmptyObject:
            cout << "\nError account was not saved its Empty\n";
            break;
        }
    }
};