#pragma once
#include <iostream>
#include <iomanip>
#include "fstream"
#include <string>

#include "Bank_Client.h"
#include "Header_Screen.h"

class CLS_Transfer_Log : protected CLS_Header_Screen
{
private:

    static void Print_Transfer_Data(CLS_Bank_Client::ST_Transfer_Data Transfer_Data)
    {
        cout << setw(10) << left << "" << "| " << left << setw(20) << Transfer_Data.Data_Time;
        cout << "| " << left << setw(15) << Transfer_Data.Source_Account;
        cout << "| " << left << setw(25) << Transfer_Data.Destination_Account;
        cout << "| " << left << setw(15) << Transfer_Data.Transfer_Amount;
        cout << "| " << left << setw(25) << Transfer_Data.Source_Balance;
        cout << "| " << left << setw(30) << Transfer_Data.Destination_Balance;
        cout << "| " << left << setw(10) << Transfer_Data.User_Name;
    }

public:

    static void Show_All_Transfers_List()
    {
        vector <CLS_Bank_Client::ST_Transfer_Data> _V_Transfers = CLS_Bank_Client::Get_Transfers_Data();
        string Title = "Transfer Log List";
        string SubTitle = "(" + to_string(_V_Transfers.size()) + ") Transfers";
        _DrawScreenHeader(Title , SubTitle);
        cout << setw(10) << left << "" << "________________________________________________________________________________________________________________________________________________________\n" << endl;
        cout << setw(10) << left << "" << "| " << left << setw(20) << "Date & Time";
        cout << "| " << left << setw(15) << "Source Account";
        cout << "| " << left << setw(25) << "Destination Account";
        cout << "| " << left << setw(15) << "Transfer Amount";
        cout << "| " << left << setw(25) << "Source Account Balance";
        cout << "| " << left << setw(30) << "Destination Account Balance";
        cout << "| " << left << setw(10) << "User" << endl;
        cout << setw(10) << left << "" << "________________________________________________________________________________________________________________________________________________________\n" << endl;

        if (_V_Transfers.size() == 0)
        {
            cout << "\n\n\n                                                     No Transfers Found                                        \n\n\n";
            cout << setw(10) << left << "" << "________________________________________________________________________________________________________________________________________________________\n" << endl;
        }
        else
        {
            for (CLS_Bank_Client::ST_Transfer_Data& Transfer : _V_Transfers)
            {
                Print_Transfer_Data(Transfer);
                cout << endl;
            }
            cout << setw(10) << left << "" << "________________________________________________________________________________________________________________________________________________________\n" << endl;
        }
    }
};

