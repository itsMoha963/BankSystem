#pragma once
#include <iostream>
#include <iomanip>
#include "utils\clsInputValidate.h"
#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"

class clsManageUsers : protected clsScreen
{
private:
    enum enManageUsersMenueOption
    {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenue = 6
    };

    static short _ReadManageUsersMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]";
        short choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Invalid Please Enter A Number Between 1 and 6");
        return choice;
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("PAUSE");
        ShowManageUsersMenue();
    }
    static void _ShowListUsersScreen()
    {
        clsUsersListScreen::ShowUsersList();
    }
    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }
    static void _ShowDeleteUserScreen()
    {
        cout << "not implemented yet";
    }
    static void _SchowUpdateUserScreen()
    {
        cout << "not implemented yet";
    }
    static void _ShowFindUserScreen()
    {
        cout << "not implemented yet";
    }
    static void _PerformManageUsersMenueOption(enManageUsersMenueOption MUOption)
    {
        switch (MUOption)
        {
        case enManageUsersMenueOption::eListUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        case enManageUsersMenueOption::eAddNewUser:
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        case enManageUsersMenueOption::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        case enManageUsersMenueOption::eUpdateUser:
            system("cls");
            _SchowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        case enManageUsersMenueOption::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        case enManageUsersMenueOption::eMainMenue:
        {
        }
        }
    }

public:
    static void ShowManageUsersMenue()
    {
        system("cls");
        _DrawScreenHeader("\t   Manage Users Screen", "");
        cout << "\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tManage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOption)_ReadManageUsersMenuOption());
    }
};
