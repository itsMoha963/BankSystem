#pragma once
#include <iostream>
#include <iomanip>
#include "utils\clsInputValidate.h"
#include "clsScreen.h"
#include "ClientScreen\clsClientListScreen.h"
#include "ClientScreen\clsAddNewClientScreen.h"
#include "ClientScreen\clsDeleteClientScreen.h"
#include "ClientScreen\clsUpdateClientScreen.h"
#include "ClientScreen\clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "ClientScreen\clsLogsScreen.h"
#include "clsCurrencyScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenueOptions
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eSchowTransactionsMenue = 6,
        eManageUsers = 7,
        eLogsMenue = 8,
        eCurrencyMenue = 9,
        eExit = 10
    };
    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]";
        short choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Invalid Please Enter A Number Between 1 and 10");
        return choice;
    }
    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("PAUSE");
        ShowMainMenue();
    }
    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }
    static void _ShowAddNewClientScreen()
    {
        clsAddNewClientScreen::AddNewClient();
    }
    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClient();
    }
    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::showFindClientScreen();
    }
    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::UpdateClient();
    }
    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
    }
    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();
    }
    static void _ShowLogsScreen()
    {
        clsLogsScreen::ShowLoginRegisterScreen();
    }
    static void _ShowCurrencyScreen()
    {
        clsCurrencyScreen::ShowCurrencyMenue();
    }
    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
        // clsLoginScreen::ShowLoginScreen();
    }
    static void _PerformMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eSchowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eLogsMenue:
            system("cls");
            _ShowLogsScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eCurrencyMenue:
            system("cls");
            _ShowCurrencyScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }
    }

public:
    static void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen", "");
        cout << "\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Menue.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};