#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"

class frontend : protected clsScreen
{
public:
    static void ReadClientInfo(clsBankClient &Client)
    {
        string temp;
        float Ftemp;
        cout << "\nEnter Firstname:";
        temp = clsInputValidate::ReadString();
        Client.setFirstName(temp);
        cout << "\nEnter Laststname:";
        temp = clsInputValidate::ReadString();
        Client.setLastName(temp);
        cout << "\nEnter Email:";
        temp = clsInputValidate::ReadString();
        Client.setEmail(temp);
        cout << "\nEnter Phone:";
        temp = clsInputValidate::ReadString();
        Client.setPhone(temp);
        cout << "\nEnter Pincode:";
        temp = clsInputValidate::ReadString();
        Client.setPinCode(temp);
        cout << "\nEnter Account Balance:";
        Ftemp = clsInputValidate::ReadFloatNumber();
        Client.setAccountBalance(Ftemp);
    }

    static void UpdateClient()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "\nAccount number not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nUpdate Client Info:";
        cout << "\n______________________\n";

        ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(Client1);
            break;
        case clsBankClient::enSaveResults::svFailedEmptyObject:
            cout << "\nError account was not saved its Empty\n";
            break;
        }
    }

    static void AddNewClient()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::isClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose an another AccountNubmer";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClinetObject(AccountNumber);

        ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        case clsBankClient::enSaveResults::svFailedEmptyObject:
            cout << "\nError account was not saved its Empty\n";
            break;
        case clsBankClient::enSaveResults::svFailedAccountNumberExists:
            cout << "\nFailed to Save, Account is already in use\n";
            break;
        }
    }

    static void DeleteClient()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is not Found, Choose an another AccountNubmer";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(client1);

        cout << "\nAre you sure you want to delete this Account? y/n";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' | Answer == 'Y')
        {
            if (client1.Delete())
            {
                cout << "\n client delete successfully\n";
                _PrintClient(client1);
            }
            else
                cout << "\n client is not deleted\n";
        }
    }

    static void showClientCard()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::isClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is not Found, Choose an another AccountNubmer";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(client1);
    }

    static void PrintClientRecordLine(clsBankClient Client)
    {
        // prints each client in a row
        cout << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.getPhone();
        cout << "| " << setw(15) << left << Client.getEmail();
        cout << "| " << setw(10) << left << Client.getPinCode();
        cout << "| " << setw(12) << left << Client.getAccountBalance();
    }

    static void ShowClientsList()
    {

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(15) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }

    static void PrintClientRecordBalancecLine(clsBankClient client)
    {
        cout << "| " << setw(15) << left << client.getAccountNumber();
        cout << "| " << setw(40) << left << client.FullName();
        cout << "| " << setw(12) << left << client.getAccountBalance();
    }
    static void ShowTotalBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
            for (clsBankClient &cli : vClients)
            {
                PrintClientRecordBalancecLine(cli);
                cout << endl;
            }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
        cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
        cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
    }
};