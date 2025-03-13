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
};