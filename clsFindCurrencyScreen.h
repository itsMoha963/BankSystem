#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "utils\clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";
    }
    static void _ShowResults(clsCurrency curr)
    {
        if (!curr.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(curr);
        }
        else
            cout << "\nCurrency Was not Found :-(\n";
    }

public:
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ? ";
        short Answer = 1;

        cin >> Answer;
        if (Answer == 1)
        {
            string currCode;
            cout << "\nPlease Enter CurrencyCode: ";
            currCode = clsInputValidate::ReadString();
            clsCurrency curr = clsCurrency::FindByCode(currCode);
            _ShowResults(curr);
        }
        else
        {
            string Country;
            cout << "\nPlease Enter Country Name: ";
            Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }
    }
};