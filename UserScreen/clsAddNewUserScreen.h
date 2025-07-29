#pragma once
#include <iostream>
#include "..\clsScreen.h"
#include "..\utils\clsInputValidate.h"
#include "..\clsUser.h"
#include <iomanip>

class clsAddNewUserScreen : protected clsScreen
{
private:
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
        cout << "\n Logs Register List ? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
            Permissons += clsUser::enPermissons::PLogRegisterList;

        return Permissons;
    }

public:
    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("\t  Add New User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFailedEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;
        }
        case clsUser::enSaveResults::svFailedUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;
        }
        }
    }
};