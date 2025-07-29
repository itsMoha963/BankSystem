#pragma once
#include <iostream>
#include "clsScreen.h"
#include "utils\clsInputValidate.h"
#include "clsUser.h"
#include <iomanip>

class clsDeleteUserScreen : protected clsScreen
{

public:
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\t Delete User Screen");
        string UserName = "";
        cout << "\nPlease Enter a User Name: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\n User Name is not Found, choose another UserName";
            UserName = clsInputValidate::ReadString();
        }
        clsUser us = clsUser::Find(UserName);

        _PrintUser(us);

        cout << "\nAre you sure you want to delete this User name? y/n ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            if (us.Delete())
            {
                cout << "\n User deleted successfully\n";
                _PrintUser(us);
            }
            else
                cout << "\n client is not deleted\n";
        }
    }
};