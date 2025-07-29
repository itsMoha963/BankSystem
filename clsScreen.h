#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsUser.h"
#include "Global.h"
#include "utils\clsDate.h"
using namespace std;
class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {

        cout << "\t\t\t\t\t_____________________________________";
        cout << "\n\n\t\t\t\t\t   " << Title;
        if (SubTitle != "")
            cout << "\n\t\t\t\t\t   " << SubTitle;
        cout << "\n\t\t\t\t\t_____________________________________\n\n";
        cout << "\t\t\t\t\tUser: " << CurrentUser.getUserName() << "\n";
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n";
        /*clsDate().GetDay();
         clsDate().GetMonth();
         clsDate().GetYear();*/
        //! valid way to create an object directly by calling the constructor Temporary!!!!!
    }
    static void _PrintClient(clsBankClient cli)
    {
        cout << "\nClient Card:";
        cout << "\n____________________________________________";
        cout << "\nFirstName     : " << cli.getFirstName();
        cout << "\nLastName      : " << cli.getLastName();
        cout << "\nFullName      : " << cli.FullName();
        cout << "\nEmail         : " << cli.getEmail();
        cout << "\nPhone         : " << cli.getPhone();
        cout << "\nAcc. Number   : " << cli.getAccountNumber();
        cout << "\nPassword      : " << cli.getPinCode();
        cout << "\nBalance       : " << cli.getAccountBalance();
        cout << "\n____________________________________________\n";
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.getFirstName();
        cout << "\nLastName    : " << User.getLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.getEmail();
        cout << "\nPhone       : " << User.getPhone();
        cout << "\nUser Name   : " << User.getUserName();
        cout << "\nPassword    : " << User.getPassword();
        cout << "\nPermissions : " << User.getPermissions();
        cout << "\n___________________\n";
    }

    static bool CheckAccesRights(clsUser::enPermissons Permisson)
    {
        if (!CurrentUser.CheckAccessPermission(Permisson))
        {
            cout << "\t\t\t\t\t__________________________________";
            cout << "\n\n\t\t\t\t\t Access Denied! Contact your Admin :(";
            cout << "\n\t\t\t\t\t__________________________________";
            return false;
        }
        else
            return true;
    }
};