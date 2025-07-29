#pragma once
#include <iostream>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "utils\clsInputValidate.h"
#include "utils\clsDate.h"
#include "utils\clsString.h"
#include <fstream>
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

    static bool _Login()
    {
        bool LoginFailed = false;
        string Username, Password;
        short counter = 3;
        do
        {
            if (LoginFailed)
            {
                cout << "\nInvalid Username/Password\n";
                counter--;
                cout << "you have " << counter << " Trials to login\n";
            }
            if (counter == 0)
            {
                cout << "you are locked after 3 failed trailes";
                return false;
            }

            cout << "\nEnter Username: ";
            Username = clsInputValidate::ReadString();
            cout << "\nEnter Password: ";
            Password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(Username, Password);

            LoginFailed = CurrentUser.IsEmpty();
        } while (LoginFailed);
        CurrentUser.LogFile();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:
    static bool ShowLoginScreen()
    {
        system("cls");
        _ScreenHeader();
        return _Login();
    }
};
