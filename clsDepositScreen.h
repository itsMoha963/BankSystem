#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"

class clsDepositScreen : protected clsScreen
{
private:
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
    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is not Found, Choose an another AccountNubmer";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

public:
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");

        string AccountNumber = _ReadAccountNumber();

        clsBankClient cli = clsBankClient::Find(AccountNumber);
        _PrintClient(cli);

        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        Amount = clsInputValidate::ReadPositiveDblNumber();

        cout << "\n Are you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            cli.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << cli.getAccountBalance();
        }
        else
            cout << "\nOperation was canelled.\n";
    }
};