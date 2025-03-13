#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{
private:
    std::string _Value;

public:
    clsString()
    {
        _Value = "";
    }
    clsString(std::string Value)
    {
        _Value = Value;
    }

    void setValue(std::string value)
    {
        _Value = value;
    }
    std::string GetValue()
    {
        return _Value;
    }
    void PrintValue()
    {
        std::cout << _Value << std::endl;
    }
    //!------------#########------------#########------------#########------------#########------------#########
    static void PrintFirstLetter(std::string str)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirstLetter)
            {
                std::cout << str[i] << std::endl;
            }
            isFirstLetter = (str[i] == ' ' ? true : false);
        }
    }
    void PrintFirstLetter()
    {
        PrintFirstLetter(_Value);
    }
    static char InvertLetterCase(char Char1)
    {
        return isupper(Char1) ? tolower(Char1) : toupper(Char1);
    }
    static std::string ToUpperFirstLetter(std::string str)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirstLetter)
            {
                str[i] = (char)toupper(str[i]);
            }
            isFirstLetter = (str[i] == ' ' ? true : false);
        }
        return str;
    }
    std::string ToUpperFirstLetter()
    {
        return _Value = ToUpperFirstLetter(_Value);
    }

    static std::string ToLowerFirstLetter(std::string str)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && isFirstLetter)
            {
                str[i] = (char)tolower(str[i]);
            }
            isFirstLetter = (str[i] == ' ' ? true : false);
        }
        return str;
    }
    std::string ToLowerFirstLetter()
    {
        return _Value = ToLowerFirstLetter(_Value);
    }

    static std::string ToLowerString(std::string str)
    {
        for (short i = 0; i < str.length(); i++)
        {
            str[i] = (char)tolower(str[i]);
        }
        return str;
    }
    std::string ToLowerString()
    {
        return _Value = ToLowerString(_Value);
    }

    static std::string ToUpperString(std::string str)
    {
        for (short i = 0; i < str.length(); i++)
        {
            str[i] = (char)toupper(str[i]);
        }
        return str;
    }
    std::string ToUpperString()
    {
        return _Value = ToUpperString(_Value);
    }

    static std::string InvertString(std::string str)
    {
        // clsString instance;
        for (short i = 0; i < str.length(); i++)
        {
            str[i] = /*instance.*/ InvertLetterCase(str[i]);
        }
        return str;
    }
    std::string InvertString()
    {
        return _Value = InvertString(_Value);
    }
    static int CountCapitalLetters(std::string str)
    {
        int counter = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (isupper(str[i]))
                counter++;
        }
        return counter;
    }
    int CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }
    static int CountSmallLetters(std::string str)
    {
        int counter = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (islower(str[i]))
                counter++;
        }
        return counter;
    }

    int CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static int GetStringLength(std::string str)
    {
        return str.length();
    }

    int GetStringLength()
    {
        return GetStringLength(_Value);
    }

    static int CountSpecificLetter(std::string str, char letter, bool MatchCase = true)
    {
        int counter = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (MatchCase)
            {
                if (str[i] == letter)
                    counter++;
            }
            else
            {
                if (tolower(str[i]) == tolower(letter))
                    counter++;
            }
        }
        return counter;
    }
    int CountSpecificLetter(char letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, letter, MatchCase);
    }
    static bool isVowel(char a)
    {
        a = tolower(a);
        return ((a == 'a') || (a == 'e') || (a == 'i') || (a == 'o') || (a == 'u'));
    }

    static int CountVowelsInString(std::string str)
    {
        int counter = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (isVowel(str[i]))
                counter++;
        }
        return counter;
    }
    int CountVowelsInString()
    {
        return CountVowelsInString(_Value);
    }
    enum enWhatToCount
    {
        SmallLetters = 0,
        CapitalLetters = 1,
        All = 3
    };

    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {

        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;

            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;
        }

        return Counter;
    }

    static void PrintEachWordInString(std::string str, std::string Delimerter)
    {
        std::cout << "\nYour string words are:\n\n";
        std::string sWord = "";
        int pos = 0;
        while ((pos = str.find(Delimerter)) != std::string::npos)
        {
            sWord = str.substr(0, pos);
            if (sWord != "")
            {
                std::cout << sWord << std::endl;
            }
            str.erase(0, pos + Delimerter.length());
        }
        if (str != "")
        {
            std::cout << str << std::endl;
        }
    }
    void PrintEachWordInString(std::string Delimerter)
    {
        PrintEachWordInString(_Value, Delimerter);
    }
    static int CountWords(std::string str, std::string delimeter)
    {

        std::string sWord = "";
        int pos = 0;
        int counter = 0;
        while ((pos = str.find(delimeter)) != std::string::npos)
        {
            sWord = str.substr(0, pos);
            if (sWord != "")
            {
                counter++;
            }
            str.erase(0, pos + delimeter.length());
        }
        if (str != "")
        {
            counter++;
        }
        return counter;
    }
    int CountWords(std::string delimeter)
    {
        return CountWords(_Value, delimeter);
    }

    static std::vector<std::string> SplitString(std::string str, std::string delimeter)
    {
        std::vector<std::string> vString;
        std::string sWord;
        short Position = 0;

        while ((Position = str.find(delimeter)) != std::string::npos)
        {
            sWord = str.substr(0, Position);
            if (sWord != "")
            {
                vString.push_back(sWord);
            }
            str.erase(0, Position + delimeter.length());
        }
        if (str != "")
        {
            vString.push_back(str);
        }

        return vString;
    }
    std::vector<std::string> SplitString(std::string delimeter)
    {
        return SplitString(_Value, delimeter);
    }

    static std::string TrimLeft(std::string str, char delimeter)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != delimeter)
                return str.substr(i, str.length() - i);
        }
        return "";
    }
    std::string TrimLeft(char delimeter)
    {
        return TrimLeft(_Value, delimeter);
    }

    static std::string TrimRight(std::string str, char delimeter)
    {
        for (int i = str.length() - 1; i >= 0; i--)
        {
            if (str[i] != delimeter)
                return str.substr(0, i + 1);
        }
        return "";
    }
    std::string TrimRight(char delimeter)
    {
        return TrimRight(_Value, delimeter);
    }
    static std::string TrimAll(std::string str, char delimeter)
    {
        return TrimLeft(TrimRight(str, delimeter), delimeter);
    }
    std::string TrimAll(char delimeter)
    {
        return TrimAll(_Value, delimeter);
    }
    static std::string JOIN(std::vector<std::string> vString, std::string delimeter)
    {
        std::string strJoined = "";
        for (std::string &str : vString)
        {
            strJoined = strJoined + str + delimeter;
        }
        return strJoined.substr(0, strJoined.length() - delimeter.length());
    }
    //& it doesnt make any sense for now but i will leave it like that
    // std::string JOIN(std::string delimeter)
    // {
    //     std::vector<std::string> vString = SplitString(_Value, delimeter);
    //     return JOIN(vString, delimeter);
    // }

    static std::string JOIN(std::string AString[], int StrLen, std::string Delimeter)
    {
        std::string strJoined = "";
        for (short i = 0; i < StrLen; i++)
        {
            strJoined += AString[i];
            if (i < StrLen - 1) // Append delimiter only if not the last element
            {
                strJoined += Delimeter;
            }
        }
        return strJoined;
    }

    static std::string ReplaceWord(std::string str, std::string OldWord, std::string NewWord, std::string delimeter, bool MatchCase = true)
    {
        std::vector<std::string> vString = SplitString(str, delimeter);

        for (std::string &word : vString)
        {
            if (MatchCase)
            {
                if (word == OldWord)
                    word = NewWord;
            }
            else if (ToLowerString(word) == ToLowerString(OldWord))
                word = NewWord;
        }
        return JOIN(vString, delimeter);
    }

    std::string ReplaceWord(std::string OldWord, std::string NewWord, std::string delimeter, bool MatchCase = true)
    {
        return ReplaceWord(_Value, OldWord, NewWord, delimeter, MatchCase);
    }

    static std::string Reverse(std::string str, std::string delimeter)
    {
        std::vector<std::string> vString = SplitString(str, delimeter);
        std::string temp = "";
        std::vector<std::string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {
            --iter;
            if (!temp.empty())
            {
                temp += delimeter;
            }
            temp += *iter;
        }
        return temp;
    }
    std::string Reverse(std::string delimeter)
    {
        return Reverse(_Value, delimeter);
    }

    static std::string RemovePunctuation(std::string str)
    {
        std::string str2 = "";
        for (short i = 0; i < str.length(); i++)
        {
            if (!ispunct(str[i]))
                str2 += str[i];
        }
        return str2;
    }
    std::string RemovePunctuation()
    {
        return RemovePunctuation(_Value);
    }
};