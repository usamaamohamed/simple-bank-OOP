#pragma once
#include "iostream"
#include "iomanip"
#include "fstream"

#include "Global_User.h"

#include "Bank_Client.h"
#include "Header_Screen.h"

#include "clsDate.h"

#include "1_Deposite_Screen.h"
#include "2_Withdraw_Screen.h"

using namespace std;

class CLS_Transfers : protected CLS_Header_Screen
{
private:

    static void _Print_Client_Card(CLS_Bank_Client Client)
    {
        cout << endl;
        cout << setw(10) << left << "" << "Client Card.\n";
        cout << setw(10) << left << "" << "---------------------------------------\n";
        cout << setw(10) << left << "" << "Client's Name : " << Client.Get_Full_Name() << "\n";
        cout << setw(10) << left << "" << "Balance = " << Client.Account_Balance << "\n";
        cout << setw(10) << left << "" << "---------------------------------------\n\n";
    }

public:
    static void _Show_Transactions()
    {
        double Transfer_Amount = 0;
        string Account_Number1;
        string Account_Number2;
        _DrawScreenHeader("Transfers List");
        cout << "Enter First Account Number To Transfer From: ";
        cin >> Account_Number1;

        while (!CLS_Bank_Client::Is_Client_Exist(Account_Number1))
        {
            cout << "This Account Number Is Not Exist ,Try Again: ";
            Account_Number1 = clsInputValidate::ReadString();
        }
        CLS_Bank_Client Client1 = CLS_Bank_Client::Find(Account_Number1);
        _Print_Client_Card(Client1);

        cout << "Enter Second Account Number To Transfer To: ";
        cin >> Account_Number2;

        while (!CLS_Bank_Client::Is_Client_Exist(Account_Number2))
        {
            cout << "This Account Number Is Not Exist ,Try Again: ";
            Account_Number2 = clsInputValidate::ReadString();
        }
        CLS_Bank_Client Client2 = CLS_Bank_Client::Find(Account_Number2);
        _Print_Client_Card(Client2);

        cout << "Enter Amount Of Money You Want To Transfer: ";
        Transfer_Amount = clsInputValidate::Read_Double_Number();

        char answer = 'n';
        cout << "Are You Sure You Want To Complete This Transfer?? [y,n]: ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            int iterator = 0;
            while (iterator < 3)
            {
                if (Client1.Transfer(Transfer_Amount , Client2 , Current_User.User_Name))
                {
                    cout << "\nSuccessful Transaction. \n";
                    _Print_Client_Card(Client1);
                    _Print_Client_Card(Client2);
                    break;
                }

                cout << "Withdraw Amount Esceeds Account Balance\n";
                cout << "Total Balance = " << Client1.Account_Balance << "\n";
                cout << "Transfer Amount: ";
                Transfer_Amount = clsInputValidate::Read_Double_Number();
                iterator++;

                if (iterator == 3)
                {
                    cout << "Transaction Terminated.\n";
                }
            }
        }
        else
            cout <<"Transaction Terminated.\n\n";

    }
};

