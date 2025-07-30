#pragma once
#include <iostream>
#include "utils\clsInputValidate.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;
class clsCurrencyScreen : protected clsScreen
{
private:
    enum enCurrencyMenueOptions
    {
        eListCurrencies = 1,
        eFindCurrency = 2,
        eUpdateCurrency = 3,
        eCurrencyCalculator = 4,
        eMainMenue = 5
    };
    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]";
        short choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Invalid Please Enter A Number Between 1 and 5");
        return choice;
    }
    static void _GoBackToCurrencyMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Menue...\n";
        system("PAUSE");
        ShowCurrencyMenue();
    }
    static void ShowListCurrneciesScreen()
    {
        clsCurrencyListScreen::ShowCurrenciesListScreen();
    }
    static void ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void ShowUpdateCurrencyScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }
    static void ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }
    static void _PerformCurrencyMenueOption(enCurrencyMenueOptions CurrencyMenueOption)
    {
        switch (CurrencyMenueOption)
        {
        case enCurrencyMenueOptions::eListCurrencies:
            system("cls");
            ShowListCurrneciesScreen();
            _GoBackToCurrencyMenue();
            break;
        case enCurrencyMenueOptions::eFindCurrency:
            system("cls");
            ShowFindCurrencyScreen();
            _GoBackToCurrencyMenue();
            break;
        case enCurrencyMenueOptions::eUpdateCurrency:
            system("cls");
            ShowUpdateCurrencyScreen();
            _GoBackToCurrencyMenue();
            break;
        case enCurrencyMenueOptions::eCurrencyCalculator:
            system("cls");
            ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyMenue();
            break;
        case enCurrencyMenueOptions::eMainMenue:
        {
        }
        }
    }

public:
    static void ShowCurrencyMenue()
    {
        if (!CheckAccesRights(clsUser::enPermissons::PCurrencyMenue))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t\tCurrency Screen", "");
        cout << "\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrency Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyMenueOption((enCurrencyMenueOptions)_ReadMainMenueOption());
    }
};