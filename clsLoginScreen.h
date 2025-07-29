#pragma once
#include <iostream>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "utils\clsInputValidate.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;
class clsLoginScreen : protected clsScreen
{
private:
    static void _ScreenHeader()
    {
        string Title = "\t Find Client Screen";
        _DrawScreenHeader(Title);
    }

    static void _Login()
    {
        bool LoginFailed = false;
        string Username, Password;
        do
        {
            if (LoginFailed)
                cout << "\nInvalid Username/Password\n";

            cout << "\nEnter Username: ";
            Username = clsInputValidate::ReadString();
            cout << "\nEnter Password: ";
            Password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(Username, Password);

            LoginFailed = CurrentUser.IsEmpty();
        } while (LoginFailed);

        clsMainScreen::ShowMainMenue();
    }

public:
    static void ShowLoginScreen()
    {
        system("cls");
        _ScreenHeader();
        _Login();
    }
};
