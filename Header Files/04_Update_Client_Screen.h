#pragma once
#include <iostream>
#include "Header_Screen.h"
#include "Bank_Client.h"
#include "cls_Input_Validate.h"

class CLS_Update_Client_Screen : protected CLS_Header_Screen
{
private:
    static void Read_Client_Info(CLS_Bank_Client& Client)
    {
        cout << "\nEnter First Name: ";
        Client.First_Name = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        Client.Last_Name = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.Pin_Code = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.Account_Balance = clsInputValidate::Read_Float_Number();
    }
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
        if (!Check_Access_Rights(CLS_Bank_User::EN_Permissions::Update_Client))
        {
            return;
        }
        _DrawScreenHeader(" Update Client");
        string Account_Number = "";
        cout << "\nPlease Enter Account Number: ";
        Account_Number = clsInputValidate::ReadString();
        while (!CLS_Bank_Client::Is_Client_Exist(Account_Number))
        {
            cout << "This Account Number Is Not Exist ,Try Again: ";
            Account_Number = clsInputValidate::ReadString();
        }
        CLS_Bank_Client Client = CLS_Bank_Client::Find(Account_Number);
        _Print_Client_Info(Client);

        Read_Client_Info(Client);

        CLS_Bank_Client::EN_Save_Results Save_Result;

        Save_Result = Client.Save();

        switch (Save_Result)
        {
        case  CLS_Bank_Client::EN_Save_Results::Saved_Successfully:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _Print_Client_Info(Client);
            break;
        }
        case CLS_Bank_Client::EN_Save_Results::Failed_Empty_Object:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }

        }
    }
};

