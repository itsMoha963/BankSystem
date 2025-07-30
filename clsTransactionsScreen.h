#pragma once
#include <iostream>
#include <iomanip>
#include "utils\clsInputValidate.h"
#include "clsScreen.h"
#include "TransactionScreen\clsDepositScreen.h"
#include "TransactionScreen\clsWithdrawScreen.h"
#include "TransactionScreen\clsTotalBalancesScreen.h"
#include "TransactionScreen\clsTransferScreen.h"
#include "TransactionScreen\clstransferLogScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactionsMenueOption
    {
        eDeposit = 1,
        eWithdraw = 2,
        eTotalBalances = 3,
        eTransfer = 4,
        eTransferLog = 5,
        eMainMenue = 6
    };

    static short _ReadTransactionMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]";
        short choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Invalid Please Enter A Number Between 1 and 6");
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
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }
    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
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
        case enTransactionsMenueOption::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
        case enTransactionsMenueOption::eTransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
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
        cout << setw(37) << left << "" << "\t[4] Tansfer.\n";
        cout << setw(37) << left << "" << "\t[5] Tansfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionMenueOption((enTransactionsMenueOption)_ReadTransactionMenueOption());
    }
};