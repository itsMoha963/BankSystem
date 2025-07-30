#pragma once
#include <iostream>
#include "..\clsScreen.h"
#include "..\clsUser.h"

class clsLogsScreen : protected clsScreen
{
private:
    static void _PrintLogs(clsUser::stLoginRegisterRecord log)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << log.DateTime;
        cout << "| " << setw(20) << left << log.UserName;
        cout << "| " << setw(20) << left << log.Password;
        cout << "| " << setw(10) << left << log.Permissions;
    }

public:
    static void ShowLoginRegisterScreen()
    {
        if (!CheckAccesRights(clsUser::enPermissons::PLogRegisterList))
        {
            return;
        }
        vector<clsUser::stLoginRegisterRecord> vLogs = clsUser::GetLoginRegisterlist();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vLogs.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
        if (vLogs.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord Record : vLogs)
            {

                _PrintLogs(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }
};
