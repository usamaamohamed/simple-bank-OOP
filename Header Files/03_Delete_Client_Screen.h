#pragma once
#include <iostream>
#include "Bank_Client.h"
#include "Header_Screen.h"

using namespace std;
class CLS_Delete_Client_Screen : protected CLS_Header_Screen
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
    static void Delete_Client()
    {
        if (!Check_Access_Rights(CLS_Bank_User::EN_Permissions::Delete_Client))
        {
            return;
        }
        _DrawScreenHeader(" Delete Client");
        string Account_Number = "";
        cout << "Please Enter Account Number: ";
        Account_Number = clsInputValidate::ReadString();
        while (!CLS_Bank_Client::Is_Client_Exist(Account_Number))
        {
            cout << "This Account Number Is Not Exist ,Try Again: ";
            Account_Number = clsInputValidate::ReadString();
        }
        CLS_Bank_Client Client = CLS_Bank_Client::Find(Account_Number);
        _Print_Client_Info(Client);

        char Answer = 'n';
        cout << "\nAre You Sure You Want To Delete This Client? (y/n)";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client.Delete())
            {
                cout << "Client Was Deleted Successfully.\n";
                _Print_Client_Info(Client);
            }
            else
            {
                cout << "Error ,Client Was Not Deleted.\n";
            }
        }
        else
        {
            cout << "Operation Terminated.\n";
        }
    }
};

