#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsFindClientScreen : protected clsScreen
{
private:
    static void _ScreenHeader()
    {
        string Title = "\t Find Client Screen";
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
    static void showFindClientScreen()
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

        if (!client1.IsEmpty())
            cout << "\nClient Found :)\n";
        else
            cout << "\nClient Was not Found :(";

        _PrintClient(client1);
    }
};