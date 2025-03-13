#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"

class clsTotalBalancesScreen : clsScreen
{
private:
    static void _PrintClientRecordBalancecLine(clsBankClient client)
    {
        cout << "| " << setw(15) << left << client.getAccountNumber();
        cout << "| " << setw(40) << left << client.FullName();
        cout << "| " << setw(12) << left << client.getAccountBalance();
    }

public:
    static void ShowTotalBalances()
    {
        _DrawScreenHeader("\t   Total Balance Screen");
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
            for (clsBankClient &cli : vClients)
            {
                _PrintClientRecordBalancecLine(cli);
                cout << endl;
            }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
        cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
        cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
    }
};