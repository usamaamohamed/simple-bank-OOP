#pragma once
#include <iostream>
#include "Bank_User.h"
#include "Header_Screen.h"
#include "cls_Input_Validate.h"

using namespace std;

class CLS_Delete_User_Screen : protected CLS_Header_Screen
{
private:
    static void _Print_User_Info(CLS_Bank_User User)
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
    static void Delete_Client()
    {
        _DrawScreenHeader(" Delete User");
        string User_Name = "";
        cout << "Please Enter User Name: ";
        User_Name = clsInputValidate::ReadString();
        while (!CLS_Bank_User::Is_User_Exist(User_Name))
        {
            cout << "This User Name Is Not Exist ,Try Again: ";
            User_Name = clsInputValidate::ReadString();
        }
        CLS_Bank_User User = CLS_Bank_User::Find(User_Name);
        _Print_User_Info(User);

        char Answer = 'n';
        cout << "\nAre You Sure You Want To Delete This User? (y/n)";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (User.Delete())
            {
                cout << "User Was Deleted Successfully.\n";
                _Print_User_Info(User);
            }
            else
            {
                cout << "Error ,User Was Not Deleted.\n";
            }
        }
        else
        {
            cout << "Operation Terminated.\n";
        }
    }
};

