#pragma once
#include <iostream>
#include <iomanip>
#include "..\utils\clsInputValidate.h"
#include "..\clsScreen.h"
#include "..\clsBankClient.h"

class clsWithdrawScreen : protected clsScreen
{
private:
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
    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");

        string AccountNumber = _ReadAccountNumber();
        clsBankClient cli = clsBankClient::Find(AccountNumber);
        _PrintClient(cli);

        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate::ReadPositiveDblNumber();

        cout << "\n Are you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (cli.WithDraw(Amount))
            {
                cout << "\nAmount Withdrawed Successfully.\n";
                cout << "\nNew Balance Is: " << cli.getAccountBalance();
            }
            else
            {
                cout << "Cannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmount to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << cli.getAccountBalance();
            }
        }
        else
            cout << "\nOperation was canelled.\n";
    }
};