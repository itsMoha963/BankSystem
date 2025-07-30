#pragma once
#include <iostream>
#include "..\clsScreen.h"
#include "..\clsUser.h"
using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:
    static void _printLogs(clsBankClient::stLogTransferRecord log)
    {
        cout << setw(8) << left << "" << "| " << setw(10) << left << log.DateTime;
        cout << "| " << setw(12) << left << log.SourceAccountNumber;
        cout << "| " << setw(12) << left << log.DestinationAccountNumber;
        cout << "| " << setw(12) << left << log.Amount;
        cout << "| " << setw(12) << left << log.SourceBalance;
        cout << "| " << setw(12) << left << log.DestinationBalance;
        cout << "| " << setw(12) << left << log.UserName;
    }

public:
    static void ShowTransferLogScreen()
    {
        vector<clsBankClient::stLogTransferRecord> vTrLog = clsBankClient::GetLogTransferList();
        string Title = "\t Transfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTrLog.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
        cout << setw(8) << left << "" << "| " << left << setw(15) << "Date/Time";
        cout << "| " << left << setw(15) << "s.Acct";
        cout << "| " << left << setw(12) << "d.Acct";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(12) << "s.Balance";
        cout << "| " << left << setw(12) << "d.Balance";
        cout << "| " << left << setw(12) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
        if (vTrLog.size() == 0)
            cout << "\t\t\t\tNo Transfer Log Available In the System!";
        else
            for (clsBankClient::stLogTransferRecord Record : vTrLog)
            {
                _printLogs(Record);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }
};
