#pragma once
#include <iostream>
#include "clsPerson.h"
#include "utils\clsString.h"
#include <vector>
#include <fstream>
#include "Global.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::SplitString(line, Seperator);
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static clsBankClient _GetEmptyClinetObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static vector<clsBankClient> _LoadClientsDataFromFile()
    {

        vector<clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // readMode
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }

    static string _ConvertClinetObjectToLine(clsBankClient cli, string delimeter = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += cli.getFirstName() + delimeter;
        stClientRecord += cli.getLastName() + delimeter;
        stClientRecord += cli.getEmail() + delimeter;
        stClientRecord += cli.getPhone() + delimeter;
        stClientRecord += cli.getAccountNumber() + delimeter;
        stClientRecord += cli.getPinCode() + delimeter;
        stClientRecord += to_string(cli.getAccountBalance());

        return stClientRecord;
    }
    static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out); // overwrite Mode

        string DataLine;
        if (MyFile.is_open())
        {
            for (clsBankClient &cli : vClients)
            {
                if (cli._MarkedForDelete == false)
                {
                    DataLine = _ConvertClinetObjectToLine(cli);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }
    void _Update()
    {
        vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();
        for (clsBankClient &cli : _vClients)
        {
            if (cli._AccountNumber == getAccountNumber())
            {
                cli = *this;
                break;
            }
        }
        _SaveClientsDataToFile(_vClients);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClinetObjectToLine(*this));
    }

    void _AddDataLineToFile(string stDataline)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDataline << endl;
            MyFile.close();
        }
    }
    string _convertClientTransfareToLine(double Amount, clsBankClient destinationClient, string delimeter = "#//#")
    {
        string TrLog = "";
        TrLog += clsDate::GetSystemDateTimeString() + delimeter;
        TrLog += getAccountNumber() + delimeter;
        TrLog += destinationClient.getAccountNumber() + delimeter;
        TrLog += to_string(Amount) + delimeter;
        TrLog += to_string(getAccountBalance()) + delimeter;
        TrLog += to_string(destinationClient.getAccountBalance()) + delimeter;
        TrLog += CurrentUser.getUserName();

        return TrLog;
    }

public:
    struct stLogTransferRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        double Amount;
        double SourceBalance;
        double DestinationBalance;
        string UserName;
    };

private:
    static stLogTransferRecord _ConvertTransferLogToRecord(string line, string delimeter = "#//#")
    {
        stLogTransferRecord TrLog;
        vector<string> logDataLine = clsString::SplitString(line, delimeter);
        TrLog.DateTime = logDataLine[0];
        TrLog.SourceAccountNumber = logDataLine[1];
        TrLog.DestinationAccountNumber = logDataLine[2];
        TrLog.Amount = stod(logDataLine[3]);
        TrLog.SourceBalance = stod(logDataLine[4]);
        TrLog.DestinationBalance = stod(logDataLine[5]);
        TrLog.UserName = logDataLine[6];

        return TrLog;
    }

public:
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
    {
        this->_Mode = Mode;
        this->_AccountNumber = AccountNumber;
        this->_PinCode = PinCode;
        this->_AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string getAccountNumber()
    {
        return _AccountNumber;
    }

    void setPinCode(string PinCode)
    {
        this->_PinCode = PinCode;
    }
    string getPinCode()
    {
        return _PinCode;
    }

    void setAccountBalance(float AccountBalance)
    {
        this->_AccountBalance = AccountBalance;
    }
    float getAccountBalance()
    {
        return _AccountBalance;
    }

    /*void Print()
    {
        cout << "\nClient Card:";
        cout << "\n____________________________________________";
        cout << "\nFirstName     : " << getFirstName();
        cout << "\nLastName      : " << getLastName();
        cout << "\nFullName      : " << FullName();
        cout << "\nEmail         : " << getEmail();
        cout << "\nPhone         : " << getPhone();
        cout << "\nAcc. Number   : " << getAccountNumber();
        cout << "\nPassword      : " << getPinCode();
        cout << "\nBalance       : " << getAccountBalance();
        cout << "\n____________________________________________\n";
    }*/

    bool Delete()
    {
        vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();
        for (clsBankClient &cli : _vClients)
        {
            if (cli.getAccountNumber() == _AccountNumber)
            {
                cli._MarkedForDelete = true;
                break;
            }
        }
        _SaveClientsDataToFile(_vClients);

        *this = _GetEmptyClinetObject();
        return true;
    }
    static clsBankClient Find(string AccountNumber)
    {
        // std::vector<clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // read Mode
        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(line);
                if (Client.getAccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClinetObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        vector<clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.getAccountNumber() == AccountNumber && Client.getPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
                // vClients.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyClinetObject();
    }

    static bool isClientExist(string AccountNumber)
    {
        clsBankClient Cli = clsBankClient::Find(AccountNumber);
        return (!Cli.IsEmpty());
    }

    enum enSaveResults
    {
        svFailedEmptyObject = 0,
        svSucceeded = 1,
        svFailedAccountNumberExists = 2
    };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            if (IsEmpty())
                return enSaveResults::svFailedEmptyObject;
        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;
        case enMode::AddNewMode:
            if (clsBankClient::isClientExist(_AccountNumber))
                return enSaveResults::svFailedAccountNumberExists;
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
        default:
            return enSaveResults::svFailedEmptyObject;
        }
        return enSaveResults::svFailedEmptyObject;
    }

    static clsBankClient GetAddNewClinetObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }
    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        double TotalBalances = 0;
        for (clsBankClient &cli : vClients)
        {
            TotalBalances += cli.getAccountBalance();
        }
        return TotalBalances;
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool WithDraw(double Amount)
    {
        if (Amount <= 0) // Prevent negative or zero withdrawal
            return false;

        if (Amount > _AccountBalance) // Check if balance is sufficient
            return false;

        _AccountBalance -= Amount;
        Save();

        return true; // Indicate successs
    }

    bool Transfer(float Amount, clsBankClient &DestinationClient)
    {
        if (Amount > getAccountBalance())
            return false;
        WithDraw(Amount);
        DestinationClient.Deposit(Amount);
        return true;
    }

    void TransferLog(double Amount, clsBankClient destinationClient)
    {
        fstream Myfile;
        Myfile.open("TransferLogs.txt", ios::out | ios::app);
        if (Myfile.is_open())
        {
            Myfile << _convertClientTransfareToLine(Amount, destinationClient) << endl;
            Myfile.close();
        }
    }
    static vector<stLogTransferRecord> GetLogTransferList()
    {
        vector<stLogTransferRecord> vTrLog;
        fstream Myfile;
        Myfile.open("TransferLogs.txt", ios::in);

        if (Myfile.is_open())
        {
            string line;
            stLogTransferRecord log;
            while (getline(Myfile, line))
            {
                log = _ConvertTransferLogToRecord(line);
                vTrLog.push_back(log);
            }
            Myfile.close();
        }
        return vTrLog;
    }
};