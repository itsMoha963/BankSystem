#pragma once
#include <iostream>
#include <iomanip>
#include "..\utils\clsInputValidate.h"
#include "..\clsScreen.h"
#include "..\clsBankClient.h"
using namespace std;
class clsFindClientScreen : protected clsScreen
{
private:
    static void _ScreenHeader()
    {
        string Title = "\t Find Client Screen";
        _DrawScreenHeader(Title);
    }

public:
    static void showFindClientScreen()
    {
        _ScreenHeader();
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::isClientExist(AccountNumber))
        {
            char A = 'n';
            cout << "do you want to EXIT this process? y/n ";
            cin >> A;
            if (A == 'Y' || A == 'y')
                return;
            cout << "\nAccount Number Is not Found, Choose an another AccountNubmer: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client1 = clsBankClient::Find(AccountNumber);

        if (!client1.IsEmpty())
            cout << "\nClient Found :)\n";
        else
            cout << "\nClient Was not Found :(";

        _PrintClient(client1);
    }
};