#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"

class clsDeleteClientScreen : protected clsScreen
{
private:
    static void _ScreenHeader()
    {
        string Title = "\t Delete Client Screen";
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
    static void DeleteClient()
    {
        _ScreenHeader();
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is not Found, Choose an another AccountNubmer";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(client1);

        cout << "\nAre you sure you want to delete this Account? y/n";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' | Answer == 'Y')
        {
            if (client1.Delete())
            {
                cout << "\n client delete successfully\n";
                _PrintClient(client1);
            }
            else
                cout << "\n client is not deleted\n";
        }
    }
};