#pragma once
#include "iostream"
#include "Bank_Client.h"
#include "Header_Screen.h"

using namespace std;
class CLS_Total_Balances_Screen : protected CLS_Header_Screen
{
private:
    static void _Print_Client_Balance(CLS_Bank_Client& Client)
    {
        cout << setw(10) << left << "" << "| " << left << setw(15) << Client.Get_Account_Number();
        cout << "| " << left << setw(50) << Client.Get_Full_Name();
        cout << "| " << left << setw(12) << Client.Account_Balance;
    }
public:
    static void Show_Total_Balances()
    {
        vector <CLS_Bank_Client> _V_Clients = CLS_Bank_Client::Get_Clients_List();

        string Title = " Total Balances";
        string Subtitle = "(" + to_string(_V_Clients.size()) + ") Clients";
        _DrawScreenHeader(Title , Subtitle);

        cout << setw(10) << left << "" << "________________________________________________________________________________________________\n" << endl;
        cout << setw(10) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(50) << "Client Name";
        cout << "| " << left << setw(12) << "Balance" << endl;
        cout << setw(10) << left << "" << "________________________________________________________________________________________________\n" << endl;
        double Total_Balances = CLS_Bank_Client::Get_Total_Balances();
        if (_V_Clients.size() == 0)
        {
            cout << "\n\n\n                                                     No Clients Found                                        \n\n\n";
            cout << setw(10) << left << "" << "________________________________________________________________________________________________\n" << endl;
        }
        else
        {
            for (CLS_Bank_Client& Client : _V_Clients)
            {
                _Print_Client_Balance(Client);
                cout << endl;
            }
            cout << setw(10) << left << "" << "________________________________________________________________________________________________\n" << endl;
        }
        cout << setw(65) << right << "Total Balances = " << Total_Balances << endl;
    }
};

