#pragma once
#include <iostream>
#include <iomanip>
#include "Bank_Client.h"
#include "Bank_User.h"
#include "Header_Screen.h"

class CLS_Client_List_Screen : protected CLS_Header_Screen
{
private:

    static void Print_Client_Data(CLS_Bank_Client& Client)
    {
        cout << setw(10) << left << "" << "| " << left << setw(15) << Client.Get_Account_Number();
        cout << "| " << left << setw(20) << Client.Get_Full_Name();
        cout << "| " << left << setw(12) << Client.Phone;
        cout << "| " << left << setw(20) << Client.Email;
        cout << "| " << left << setw(10) << Client.Pin_Code;
        cout << "| " << left << setw(12) << Client.Account_Balance;
    }

public:
    static void Show_All_CLients_List()
    {
        if (!Check_Access_Rights(CLS_Bank_User::EN_Permissions::List_Client))
        {
            return;
        }
        vector <CLS_Bank_Client> _V_Clients = CLS_Bank_Client::Get_Clients_List();

        string Title = "  Client List";
        string SubTitle = "(" + to_string(_V_Clients.size()) + ") Clients";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(10) << left << "" << "________________________________________________________________________________________________\n" << endl;
        cout << setw(10) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance" << endl;
        cout << setw(10) << left << "" << "________________________________________________________________________________________________\n" << endl;

        if (_V_Clients.size() == 0)
        {
            cout << "\n\n\n                                                     No Clients Found                                        \n\n\n";
            cout << setw(10) << left << "" << "________________________________________________________________________________________________\n" << endl;
        }
        else
        {
            for (CLS_Bank_Client& Client : _V_Clients)
            {
                Print_Client_Data(Client);
                cout << endl;
            }
            cout << setw(10) << left << "" << "________________________________________________________________________________________________\n" << endl;
        }
    }
};

