#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "utils\clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsUser : public clsPerson
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;

    bool _MarkedForDelete = false;

    static clsUser _ConvertLinetoUserObject(string Line, string seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::SplitString(Line, seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
    }
    static string _ConvertUserObjectToLine(clsUser User, string seperator = "#//#")
    {
        string UserRecord = "";
        UserRecord += User.getFirstName() + seperator;
        UserRecord += User.getLastName() + seperator;
        UserRecord += User.getEmail() + seperator;
        UserRecord += User.getPhone() + seperator;
        UserRecord += User.getUserName() + seperator;
        UserRecord += User.getPassword() + seperator;
        UserRecord += to_string(User.getPermissions());

        return UserRecord;
    }

    static vector<clsUser> _LoadUsersDataFromFile()
    {
        vector<clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // read mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                vUsers.push_back(User);
            }
            MyFile.close();
        }
        return vUsers;
    }

    static void _SaveUsersDateToFile(vector<clsUser> vUsers)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out);

        string DataLine;
        if (MyFile.is_open())
        {
            for (clsUser &user : vUsers)
            {
                if (user.MarkedForDelete() == false)
                {
                    DataLine = _ConvertUserObjectToLine(user);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsUser> vUsers = _LoadUsersDataFromFile();

        for (clsUser &user : vUsers)
        {
            if (user.getUserName() == getUserName())
            {
                user = *this;
                break;
            }
        }
        _SaveUsersDateToFile(vUsers);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }
    void _AddDataLineToFile(string stDataline)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataline << endl;
            MyFile.close();
        }
    }
    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:
    enum enPermissons
    {
        eAll = -1,
        pListClients = 1,
        pAddNewClient = 2,
        pDeleteClient = 4,
        pUpdateClient = 8,
        pFindClient = 16,
        pTransactions = 32,
        pManageUsers = 64
    };

    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions) : clsPerson(FirstName, LastName, Email, Phone)
    {
        this->_Mode = Mode;
        this->_UserName = UserName;
        this->_Password = Password;
        this->_Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDelete()
    {
        return _MarkedForDelete;
    }

    string getUserName()
    {
        return this->_UserName;
    }
    void setUserName(string UserName)
    {
        this->_UserName = UserName;
    }
    string getPassword()
    {
        return this->_Password;
    }
    void setPassword(string Password)
    {
        this->_Password = Password;
    }

    int getPermissions()
    {
        return this->_Permissions;
    }
    void setPermissions(int Permissons)
    {
        this->_Permissions = Permissons;
    }

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // read mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.getUserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }
    static clsUser Find(string UserName, string Password)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser user = _ConvertLinetoUserObject(Line);
                if (user.getUserName() == UserName && user.getPassword() == Password)
                {
                    MyFile.close();
                    return user;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults
    {
        svFailedEmptyObject = 0,
        svSucceeded = 1,
        svFailedUserExists = 2
    };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            if (IsEmpty())
                return enSaveResults::svFailedEmptyObject;
            break;
        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;
            break;
        case enMode::AddNewMode:
            // it searches if the user in the list of users or not if not so it means that the user is new and should be added to the list so if it does exist so its in the list so no need to add it again
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFailedUserExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
            break;
        default:
            return enSaveResults::svFailedEmptyObject;
        }
        return enSaveResults::svFailedEmptyObject;
    }

    static bool IsUserExist(string UserName)
    {
        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector<clsUser> vUsers = _LoadUsersDataFromFile();
        for (clsUser &user : vUsers)
        {
            if (user.getUserName() == _UserName)
            {
                user._MarkedForDelete = true;
                break;
            }
        }
        _SaveUsersDateToFile(vUsers);
        *this = _GetEmptyUserObject();
        return true;
    }
    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector<clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    bool CheckAccessPermission(enPermissons Permission)
    {
        if (this->_Permissions == enPermissons::eAll)
            return true;
        if ((Permission & this->_Permissions) == Permission)
            return true;
        else
            return false;
    }
};