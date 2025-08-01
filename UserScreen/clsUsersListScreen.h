#pragma once
#include <iostream>
#include "..\clsScreen.h"
#include "..\clsUser.h"
#include <iomanip>
#include "..\Global.h"

using namespace std;

class clsUsersListScreen : protected clsScreen
{
private:
    static void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(8) << left << "" << "| " << setw(12) << left << User.getUserName();
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.getPhone();
        cout << "| " << setw(20) << left << User.getEmail();
        cout << "| " << setw(10) << left << User.getPassword();
        cout << "| " << setw(12) << left << User.getPermissions();
    }

public:
    static void ShowUsersList()
    {
        vector<clsUser> vUsers = clsUser::GetUsersList();
        string Title("\t   User List Screen");
        string Subtitle = "\t   (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, Subtitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n"
             << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n"
             << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else
            for (clsUser User : vUsers)
            {
                _PrintUserRecordLine(User);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n"
             << endl;
        cout << "encrypted: " << clsUtil::EncryptText(vUsers[0].getPassword()) << "\n";
        cout << "decrypted: " << clsUtil::DecrypText(clsUtil::EncryptText(vUsers[0].getPassword())) << "\n";
    }
};
