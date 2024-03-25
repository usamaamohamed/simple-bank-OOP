#pragma once
#include "iostream"
#include "Bank_Client.h"
#include "Header_Screen.h"
#include "cls_Input_Validate.h"
using namespace std;
class CLS_Withdraw_Screen : protected CLS_Header_Screen
{
    static void _Print(CLS_Bank_Client  Client)
    {
        cout << "           ..................................................\n";
        cout << "              Total Balace = " << Client.Account_Balance << "\n";
        cout << "           ..................................................\n";
    }
public:

    static void Withdraw_Operation()
    {
        _DrawScreenHeader("   Withdraw");
        string Account_Number = "";
        cout << "\nPlease Enter Account Number: ";
        Account_Number = clsInputValidate::ReadString();
        while (!CLS_Bank_Client::Is_Client_Exist(Account_Number))
        {
            cout << "This Account Number Is Not Exist ,Try Again: ";
            Account_Number = clsInputValidate::ReadString();
        }
        CLS_Bank_Client Client = CLS_Bank_Client::Find(Account_Number);
        _Print(Client);
        char insurance = 'n';
        cout << "Please Enter Withdraw Amount: ";
        double Withdraw_Amount = clsInputValidate::Read_Double_Number();

        cout << "Are You Sure You Want To Withdraw This Amount? [y,n]\n";
        cin >> insurance;

        if (insurance == 'y' || insurance == 'Y')
        {
            int iterator = 1;
            while ( iterator < 3)
            {
                if (Client.Withdraw(Withdraw_Amount))
                {
                    cout << "Successful Transaction. \n";
                    _Print(Client);
                    CLS_Bank_Client::EN_Save_Results Save_Result;
                    Save_Result = Client.Save();
                    break;
                }

                cout << "Withdraw Amount Esceeds Account Balance\n";
                cout << "Total Balance = " << Client.Account_Balance << "\n";
                Withdraw_Amount = clsInputValidate::Read_Double_Number();
                iterator++;
                
                if (iterator == 3)
                {
                    cout << "\nTransaction Terminated.\n";
                }
            }
        }
        else
        {
            cout << "\nTransaction Terminated.\n";
        }

    }
};

