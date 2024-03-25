#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include <limits>
using namespace std;

class clsInputValidate
{
public:

    static bool Is_Number_Between(int Number, int From, int To)
    {
        if (Number >= From && Number <= To)
        {
            return true;
        }
        else if (Number >= To && Number <= From)
        {
            return true;
        }
        else return false;
    }

    static bool Is_Number_Between(double Number, double From, double To)
    {
        if (Number >= From && Number <= To)
        {
            return true;
        }
        else if (Number >= To && Number <= From)
        {
            return true;
        }
        else return false;
    }

    static bool Is_Date_between(clsDate Date, clsDate From, clsDate To)
    {
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) && (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }
        else if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) && (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
        {
            return true;
        }
        else return false;
    }
    
    static short Read_Short_Number(string ErrorMessage = "\nInvalid Input, Enter again: ")
    {
        short Number = 0;
        cin >> Number;
        while (cin.fail()) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
            cin >> Number;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Number;
    }

    static int Read_Short_Number_Between(short From, short To, string Error_Message = "\nNumber is not within range, Enter again: ")
    {
        short Number = Read_Short_Number();
        while (!Is_Number_Between(Number, From, To))
        {
            cout << Error_Message << endl;
            Number = Read_Short_Number();
        }
        return Number;
    }

    static int Read_Int_Number(string Error_Message = "\nInvalid Input, Enter again: ")
    {
        int Number = 0;
        cin >> Number;
        while (cin.fail())
        {
            // user didn't input a number    
            cin.clear();
            cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
            cout << Error_Message << endl;
            cin >> Number;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Number;
    }

    static int Read_Int_Number_Between(int From, int To, string Error_Message = "\nNumber is not within range, Enter again: ")
    {
        int Number = Read_Int_Number();
        while (!Is_Number_Between(Number, From, To))
        {
            cout << Error_Message << endl;
            Number = Read_Int_Number();
        }
        return Number;
    }

    static double Read_Float_Number(string Error_Message = "\nInvalid Input, Enter again: ")
    {
        float Number = 0;
        cin >> Number;
        while (cin.fail())
        {
            // user didn't input a number    
            cin.clear();
            cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
            cout << Error_Message << endl;
            cin >> Number;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Number;
    }

    static double Read_Float_Number_Between(double From, double To, string Error_Message = "\nNumber is not within range, Enter again: ")
    {
        float Number = Read_Float_Number();
        while (!Is_Number_Between(Number, From, To))
        {
            cout << Error_Message << endl;
            Number = Read_Float_Number();
        }
        return Number;
    }

    static double Read_Double_Number(string Error_Message = "\nInvalid Input, Enter again: ")
    {
        double Number = 0;
        cin >> Number;
        while (cin.fail())
        {
            // user didn't input a number    
            cin.clear();
            cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
            cout << Error_Message << endl;
            cin >> Number;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Number;
    }

    static double Read_Double_Number_Between(double From, double To, string Error_Message = "\nNumber is not within range, Enter again: ")
    {
        double Number = Read_Double_Number();
        while (!Is_Number_Between(Number, From, To))
        {
            cout << Error_Message << endl;
            Number = Read_Double_Number();
        }
        return Number;
    }

    static bool is_valid_date(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    static string ReadString()
    {
        string  S1 = "";
        // Usage of std::ws will extract allthe whitespace character
        getline(cin >> ws, S1);
        return S1;
    }
};
