#pragma once
#include "iostream"
#include "Bank_Client.h"
#include "Header_Screen.h"
#include "cls_Input_Validate.h"
using namespace std;
class CLS_Deposite_Screen : protected CLS_Header_Screen
{
private:
    static void _Print(CLS_Bank_Client  Client)
    {
        cout << "           ..................................................\n";
        cout << "              Total Balace = " << Client.Account_Balance << "\n";
        cout << "           ..................................................\n";
    }
public:

    static void Deposit_Operation()
    {
        _DrawScreenHeader("   Deposite");
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
        cout << "Please Enter Deposite Amount: ";
        double Deposite_Amount = clsInputValidate::Read_Double_Number() ;

        cout << "Are You Sure You Want To Deposite This Amount? [y,n]\n";
        cin >> insurance;
        
        if (insurance == 'y' || insurance == 'Y')
        {
            Client.Deposit(Deposite_Amount);
            cout << "Successful Transaction. \n";
            _Print(Client);
            CLS_Bank_Client::EN_Save_Results Save_Result;
            Save_Result = Client.Save();
        }
        else
        {
            cout << "\nTransaction Terminated.\n";
        }

    }
};

