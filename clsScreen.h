#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t_____________________________________";
        cout << "\n\n\t\t\t\t\t   " << Title;
        if (SubTitle != "")
            cout << "\n\t\t\t\t\t   " << SubTitle;
        cout << "\n\t\t\t\t\t_____________________________________\n\n";
    }
    static void _PrintClient(clsBankClient cli)
    {
        cout << "\nClient Card:";
        cout << "\n____________________________________________";
        cout << "\nFirstName     : " << cli.getFirstName();
        cout << "\nLastName      : " << cli.getLastName();
        cout << "\nFullName      : " << cli.FullName();
        cout << "\nEmail         : " << cli.getEmail();
        cout << "\nPhone         : " << cli.getPhone();
        cout << "\nAcc. Number   : " << cli.getAccountNumber();
        cout << "\nPassword      : " << cli.getPinCode();
        cout << "\nBalance       : " << cli.getAccountBalance();
        cout << "\n____________________________________________\n";
    }
};