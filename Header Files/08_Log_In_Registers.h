#pragma once
#include <iostream>
#include <iomanip>
#include "Bank_Client.h"
#include "Bank_User.h"
#include "Header_Screen.h"

class CLS_Registers_List_Screen : protected CLS_Header_Screen
{
private:

    static void Print_Registers_Data(CLS_Bank_User::ST_Register & User)
    {
        cout << setw(10) << left << "" << "| " << left << setw(30) << User.Date_Time;
        cout << "| " << left << setw(12) << User.User_Name;
        cout << "| " << left << setw(15) << User.Full_Name;
        cout << "| " << left << setw(10) << User.Password;
        cout << "| " << left << setw(10) << User.Permissions;
    }

public:

    static void Show_All_Registerss_List()
    {
        if (!Check_Access_Rights(CLS_Bank_User::EN_Permissions::Log_In_Register))
        {
            return;
        }
        vector <CLS_Bank_User::ST_Register> _V_Registers = CLS_Bank_User::Get_Registers_List();

        string Title = "Log In Registers List";
        string SubTitle = "(" + to_string(_V_Registers.size()) + ") Log Ins";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(10) << left << "" << "________________________________________________________________________________________________\n" << endl;
        cout << setw(10) << left << "" << "| " << left << setw(30) << "Date & Time";
        cout << "| " << left << setw(12) << "User Name";
        cout << "| " << left << setw(15) << "Full Name";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(10) << "Permissions" << endl;
        cout << setw(10) << left << "" << "________________________________________________________________________________________________\n" << endl;

        if (_V_Registers.size() == 0)
        {
            cout << "\n\n\n                                                     No Registers Found                                        \n\n\n";
            cout << setw(10) << left << "" << "________________________________________________________________________________________________\n" << endl;
        }
        else
        {
            for (CLS_Bank_User::ST_Register & User : _V_Registers)
            {
                Print_Registers_Data(User);
                cout << endl;
            }
            cout << setw(10) << left << "" << "________________________________________________________________________________________________\n" << endl;
        }
    }
};

