#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;
class clsClientListScreen : protected clsScreen
{
private:
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        // prints each client in a row
        cout << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.getPhone();
        cout << "| " << setw(15) << left << Client.getEmail();
        cout << "| " << setw(10) << left << Client.getPinCode();
        cout << "| " << setw(12) << left << Client.getAccountBalance();
    }

public:
    static void ShowClientsList()
    {

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t Client List Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s).";
        _DrawScreenHeader(Title, SubTitle);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(15) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                _PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }
};