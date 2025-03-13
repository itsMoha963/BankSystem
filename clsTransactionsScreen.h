#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactionsMenueOption
    {
        eDeposit = 1,
        eWithdraw = 2,
        eTotalBalances = 3,
        eMainMenue = 4
    };

    static short _ReadTransactionMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]";
        short choice = clsInputValidate::ReadIntNumberBetween(1, 4, "Invalid Please Enter A Number Between 1 and 4");
        return choice;
    }
    static void _GoBackToTransactionsMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("PAUSE");
        ShowTransactionsMenue();
    }

    static void _ShowDepositScreen()
    {
        cout << "nothing for now";
    }

    static void _ShowWithdrawScreen()
    {
        cout << "nothing for now";
    }

    static void _ShowTotalBalancesScreen()
    {
        cout << "nothing for now";
    }

    static void _PerformTransactionMenueOption(enTransactionsMenueOption TransactionOption)
    {
        switch (TransactionOption)
        {
        case enTransactionsMenueOption::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionsMenueOption::eWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionsMenueOption::eTotalBalances:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionsMenueOption::eMainMenue:
        {
        }
        }
    }

public:
    static void ShowTransactionsMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\tTransactions Screen", "");
        cout << "\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionMenueOption((enTransactionsMenueOption)_ReadTransactionMenueOption());
    }
};