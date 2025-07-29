#pragma once
#include <iostream>
#include "..\utils\clsInputValidate.h"
#include "..\clsScreen.h"
#include "..\clsUser.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:
    static void _ScreenHeader()
    {
        string Title = "\t Find User Screen";
        _DrawScreenHeader(Title);
    }

public:
    static void ShowFindUserScreen()
    {
        _ScreenHeader();
        cout << "\nEnter a user Name to Find\n";
        string UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name Was NOT FOUND PLEASE ENTER ANOTHER USER NAME\n";
            UserName = clsInputValidate::ReadString();
        }

        clsUser user = clsUser::Find(UserName);
        if (!user.IsEmpty())
            cout << "\nUser Found :)\n";
        else
            cout << "\nUser NOT Found :)\n";

        _PrintUser(user);
    }
};
