#pragma once
#include <iostream>
#include <iomanip>
#include "Global_User.h"
#include "Bank_User.h"
#include <ctime>

#include "clsDate.h"

using namespace std;

class CLS_Header_Screen
{
protected:

    static void _DrawScreenHeader(string Title = "  Main Screen", string SubTitle = "" )
    {
        cout << setw(1) << left << "" << "User: " << Current_User.User_Name << "\n";
        cout << setw(1) << left << "" << "Name: " << Current_User.Get_Full_Name() << "\n";
        cout << setw(1) << left << "" << "Time: " << clsDate::DateToString(clsDate()) << "\n";
        cout << setw(60) << right << "" << "Bank System.\n";
        cout << setw(45) << right << "" << "----------------------------------------" << endl;
        cout << setw(58) << right << "" << Title << "\n";
        if (SubTitle != "")
        {
            cout << setw(60) << right << "" << SubTitle << "\n";
        }

        cout << setw(45) << right << "" << "----------------------------------------" << endl;
    }
    static bool Check_Access_Rights(CLS_Bank_User::EN_Permissions Permission)
    {
        if (!Current_User.Check_Permission(Permission))
        {
            system("cls");
            cout << setw(1) << left << "" << "User: " << Current_User.User_Name << "\n";
            cout << setw(1) << left << "" << "Name: " << Current_User.Get_Full_Name() << "\n";
            cout << setw(1) << left << "" << "Time: " << clsDate::DateToString(clsDate()) << "\n";
            cout << setw(60) << right << "" << "Bank System.\n";
            cout << setw(45) << right << "" << "----------------------------------------\n\n" << endl;
            cout << setw(57) << right << "" << "Access Denied!!!!\n";
            cout << setw(53) << right << "" <<  "Please Contact Your Admin" << "\n";
            return false;
        }
        else
        {
            return true;
        }

    }

};

