#pragma once
#include <iostream>
#include <string>
#include "utils\clsString.h"
#include "utils\clsUtil.h"
#include <vector>
#include <fstream>

class clsCurrency
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1
    };

    enMode _Mode;
    string _Country;
    string _Code;
    string _Name;
    double _Rate;

    static clsCurrency _ConvertLineToCurrencyObject(string line, string delimeter = "#//#")
    {
        vector<string> vCurrencyData = clsString::SplitString(line, delimeter);
        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
    }
    static string _ConverCurrencyObjectToLine(clsCurrency Currency, string delimeter = "#//#")
    {
        string stCurrencyRecord = "";
        stCurrencyRecord += Currency.Country() + delimeter;
        stCurrencyRecord += Currency.CurrencyCode() + delimeter;
        stCurrencyRecord += Currency.CurrencyName() + delimeter;
        stCurrencyRecord += to_string(Currency.Rate());

        return stCurrencyRecord;
    }

    static vector<clsCurrency> _LoadCurrencysDataFromFile()
    {
        vector<clsCurrency> vCurrency;

        fstream Myfile;
        Myfile.open("Currencies.txt", ios::in);
        if (Myfile.is_open())
        {
            string line;
            while (getline(Myfile, line))
            {
                clsCurrency curr = _ConvertLineToCurrencyObject(line);
                vCurrency.push_back(curr);
            }
            Myfile.close();
        }
        return vCurrency;
    }

    static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrency)
    {
        fstream myfile;
        myfile.open("Currencies.txt", ios::out);

        string DataLine;

        if (myfile.is_open())
        {
            for (clsCurrency c : vCurrency)
            {
                DataLine = _ConverCurrencyObjectToLine(c);
                myfile << DataLine << endl;
            }
            myfile.close();
        }
    }

    void _Update()
    {
        vector<clsCurrency> _vCurrency;
        _vCurrency = _LoadCurrencysDataFromFile();
        for (clsCurrency &c : _vCurrency)
        {
            if (c.CurrencyCode() == CurrencyCode())
            {
                c = *this;
                break;
            }
        }
        _SaveCurrencyDataToFile(_vCurrency);
    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

public:
    clsCurrency(enMode Mode, string Country, string Code, string Name, double Rate)
    {
        this->_Mode = Mode;
        this->_Country = Country;
        this->_Code = Code;
        this->_Name = Name;
        this->_Rate = Rate;
    }
    static vector<clsCurrency> GetAllUSDRates()
    {

        return _LoadCurrencysDataFromFile();
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string Country()
    {
        return _Country;
    }

    string CurrencyCode()
    {
        return _Code;
    }

    string CurrencyName()
    {
        return _Name;
    }

    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    float Rate()
    {
        return _Rate;
    }

    static clsCurrency FindByCode(string CurrencyCode)
    {
        CurrencyCode = clsString::ToUpperString(CurrencyCode);

        fstream myfile;
        myfile.open("Currencies.txt", ios::in);

        if (myfile.is_open())
        {
            string line;
            while (getline(myfile, line))
            {
                clsCurrency currency = _ConvertLineToCurrencyObject(line);
                if (currency.CurrencyCode() == CurrencyCode)
                {
                    myfile.close();
                    return currency;
                }
            }
            myfile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(string country)
    {
        country = clsString::ToUpperString(country);

        fstream myfile;
        myfile.open("Currencies.txt", ios::in);

        if (myfile.is_open())
        {
            string line;
            while (getline(myfile, line))
            {
                clsCurrency currency = _ConvertLineToCurrencyObject(line);
                if (clsString::ToUpperString(currency.Country()) == country)
                {
                    myfile.close();
                    return currency;
                }
            }
            myfile.close();
        }
        return _GetEmptyCurrencyObject();
    }
    static bool IsCurrencyExist(string code)
    {
        clsCurrency c = clsCurrency::FindByCode(code);
        return (!c.IsEmpty());
    }

    static vector<clsCurrency> GetCurrencisList()
    {
        return _LoadCurrencysDataFromFile();
    }
    float ConvertToUSD(float Amount)
    {
        return (float)(Amount / Rate());
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
    {
        float AmountInUSD = ConvertToUSD(Amount);

        if (Currency2.CurrencyCode() == "USD")
        {
            return AmountInUSD;
        }

        return (float)(AmountInUSD * Currency2.Rate());
    }
};