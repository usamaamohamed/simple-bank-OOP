#pragma once
#include "iostream"
#include "Bank_User.h"
#include "Header_Screen.h"

using namespace std;


class CLS_Find_User :CLS_Header_Screen
{
private:
    static void _Print_Client_Info(CLS_Bank_User User)
    {
        cout << "\nCLient Info:";
        cout << "\nFirstName      : " << User.First_Name;
        cout << "\nLastName       : " << User.Last_Name;
        cout << "\nFull Name      : " << User.Get_Full_Name();
        cout << "\nEmail          : " << User.Email;
        cout << "\nPhone          : " << User.Phone;
        cout << "\nUser Name      : " << User.User_Name;
        cout << "\nPassword       : " << User.Password;
        cout << "\nPermissions    : " << User.Permissions;
        cout << "\n___________________\n";
    }
public:
    static void Update_Client()
    {
        _DrawScreenHeader("  Find User");
        string User_Name = "";
        cout << "\nPlease Enter User Name: ";
        User_Name = clsInputValidate::ReadString();
        while (!CLS_Bank_User::Is_User_Exist(User_Name))
        {
            cout << "This Account Number Is Not Exist ,Try Again: ";
            User_Name = clsInputValidate::ReadString();
        }
        CLS_Bank_User User = CLS_Bank_User::Find(User_Name);
        if (!User.Is_Empty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }
        _Print_Client_Info(User);


    }
};

