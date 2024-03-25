#pragma once
#include "iostream"
#include "Bank_Client.h"
#include "Header_Screen.h"

using namespace std;


class CLS_Find_Client :CLS_Header_Screen
{
private:
    static void _Print_Client_Info(CLS_Bank_Client Client)
    {
        cout << "\nCLient Info:";
        cout << "\nFirstName      : " << Client.First_Name;
        cout << "\nLastName       : " << Client.Last_Name;
        cout << "\nFull Name      : " << Client.Get_Full_Name();
        cout << "\nEmail          : " << Client.Email;
        cout << "\nPhone          : " << Client.Phone;
        cout << "\nAccount Number : " << Client.Get_Account_Number();
        cout << "\nPassword       : " << Client.Pin_Code;
        cout << "\nBalance        : " << Client.Account_Balance;
        cout << "\n___________________\n";
    }
public:
    static void Update_Client()
    {
        if (!Check_Access_Rights(CLS_Bank_User::EN_Permissions::Find_Client))
        {
            return;
        }
        _DrawScreenHeader("  Find Client");
        string Account_Number = "";
        cout << "\nPlease Enter Account Number: ";
        Account_Number = clsInputValidate::ReadString();
        while (!CLS_Bank_Client::Is_Client_Exist(Account_Number))
        {
            cout << "This Account Number Is Not Exist ,Try Again: ";
            Account_Number = clsInputValidate::ReadString();
        }
        CLS_Bank_Client Client = CLS_Bank_Client::Find(Account_Number);
        if (!Client.IS_Empty() )
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }
        _Print_Client_Info(Client);

        
    }
};

