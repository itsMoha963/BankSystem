#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "Global.h"

using namespace std;

class clsCurrencyListScreen : protected clsScreen
{
private:
    static void _PrintCurrencyRecordLine(clsCurrency curr)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << curr.Country();
        cout << "| " << setw(8) << left << curr.CurrencyCode();
        cout << "| " << setw(45) << left << curr.CurrencyName();
        cout << "| " << setw(10) << left << curr.Rate();
    }

public:
    static void ShowCurrenciesListScreen()
    {
        vector<clsCurrency> vCurrs = clsCurrency::GetCurrencisList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrs.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n"
             << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n"
             << endl;

        if (vCurrs.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency : vCurrs)
            {

                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n"
             << endl;
    }
};
