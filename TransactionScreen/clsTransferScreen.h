#pragma once
#include <iostream>
#include "..\clsScreen.h"
#include "..\clsBankClient.h"
#include "..\utils\clsInputValidate.h"

class clsTransferScreen : clsScreen
{
private:
    static void _PrintClientCard(clsBankClient client)
    {
        cout << "\nClient Card";

        cout << "\n______________________\n\n";

        cout << "|Full Name: " << left << client.FullName() << "\n";
        cout << "|Acc. Number: " << left << client.getAccountNumber() << "\n";
        cout << "|Balance: " << left << client.getAccountBalance();
        cout << "\n______________________";
    }
    static void _ScreenHeader()
    {
        string Title = "\t Transfer Screen";
        _DrawScreenHeader(Title);
    }
    static string _ReadAccountNumber(string msg)
    {
        string AccountNumber = "";
        cout << msg;

        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is not Found, Choose an another Account Number";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.getAccountBalance())
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadPositiveDblNumber();
        }
        return Amount;
    }

public:
    static void ShowTransferScreen()
    {
        _ScreenHeader();
        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter An Account Number To Transfer From: "));
        _PrintClientCard(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter An Account Number To Transfer To: "));
        _PrintClientCard(DestinationClient);

        double Amount = _ReadAmount(SourceClient);

        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
    }
};