#pragma once
#include <iostream>
#include <iomanip>
#include "..\utils\clsInputValidate.h"
#include "..\clsScreen.h"
#include "..\clsUser.h"

using namespace std;
class clsUpdateUserScreen : protected clsScreen
{
private:
    static void _ScreenHeader()
    {
        string Title = "\t Update User Screen";
        _DrawScreenHeader(Title);
    }
    static void _ReadUserInfo(clsUser &User)
    {
        cout << "\nEnter FirstName: ";
        User.setFirstName(clsInputValidate::ReadString());
        cout << "\nEnter LastName: ";
        User.setLastName(clsInputValidate::ReadString());
        cout << "\nEnter Email: ";
        User.setEmail(clsInputValidate::ReadString());
        cout << "\nEnter Phone: ";
        User.setPhone(clsInputValidate::ReadString());
        cout << "\nEnter Password: ";
        User.setPassword(clsInputValidate::ReadString());
        cout << "\nEnter Permission: ";
        User.setPermissions(_ReadPermissionsToSet());
    }

    static int _ReadPermissionsToSet()
    {
        int Permissons = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full acces y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            return -1;

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissons += clsUser::enPermissons::pListClients;

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissons += clsUser::enPermissons::pAddNewClient;

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissons += clsUser::enPermissons::pDeleteClient;

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissons += clsUser::enPermissons::pUpdateClient;

        cout << "\nFind Client? y/n ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissons += clsUser::enPermissons::pFindClient;

        cout << "\nTransactions? y/n ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissons += clsUser::enPermissons::pTransactions;

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissons += clsUser::enPermissons::pManageUsers;

        return Permissons;
    }

public:
    static void ShowUpdateUserScreen()
    {
        _ScreenHeader();
        cout << "\nPlease Enter a user name to Update: ";
        string UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name Not Found, choose another User Name: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser us = clsUser::Find(UserName);
        _PrintUser(us);
        cout << "\nAre you sure you want to update this User? y/n ";
        char a = 'n';
        cin >> a;
        if (a == 'Y' || a == 'y')
        {
            cout << "\nUpdate User Info:";
            cout << "\n______________________\n";

            _ReadUserInfo(us);

            clsUser::enSaveResults SaveResult;

            SaveResult = us.Save();

            switch (SaveResult)
            {
            case clsUser::enSaveResults::svSucceeded:
                cout << "\nUser Updated Successfully :-)\n";
                _PrintUser(us);
                break;
            case clsUser::enSaveResults::svFailedEmptyObject:
                cout << "\nUser Was NOT Updated  :-(\n";
                break;
            }
        }
    }
};