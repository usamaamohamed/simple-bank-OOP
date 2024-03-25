#pragma once
#include <iostream>
#include "Bank_User.h"
#include "Header_Screen.h"
#include "cls_Input_Validate.h"

class CLS_Update_User_Screen : protected CLS_Header_Screen
{
private:
    static void _Read_User_Info(CLS_Bank_User& User)
    {
        char Info_Update = 'n';
        char Permissions_Update = 'n';

        cout << "Do You Wnat To Update User Info? [y,n]:";
        cin >> Info_Update;

        if (Info_Update == 'y' || Info_Update == 'Y')
        {
            cout << "\nEnter First Name: ";
            User.First_Name = clsInputValidate::ReadString();

            cout << "\nEnter Last Name: ";
            User.Last_Name = clsInputValidate::ReadString();

            cout << "\nEnter Email: ";
            User.Email = clsInputValidate::ReadString();

            cout << "\nEnter Phone: ";
            User.Phone = clsInputValidate::ReadString();

            cout << "\nEnter Password: ";
            User.Password = clsInputValidate::ReadString();
        }

        cout << "Do You Wnat To Update User Permissions? [y,n]:";
        cin >> Permissions_Update;

        if (Permissions_Update == 'y' || Permissions_Update == 'Y')
        {
            cout << "\nEnter Permissions: ";
            User.Permissions = _Read_User_Permsissions();
        }
    }

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

    static int _Read_User_Permsissions()
    {
        int permissions = 0;
        char answer;
        cout << "Do You Want To Give This User Full Access? [y,n] \n";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            return -1;
        }

        cout << "Do You Want To Give This User Access To Show Clients List? [y,n] \n";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += CLS_Bank_User::EN_Permissions::List_Client;
        }

        cout << "Do You Want To Give This User Access To Add New Client? [y,n] \n";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += CLS_Bank_User::EN_Permissions::Add_New_Client;
        }

        cout << "Do You Want To Give This User Access To Delete Client? [y,n] \n";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += CLS_Bank_User::EN_Permissions::Delete_Client;
        }

        cout << "Do You Want To Give This User Access To Update Client Info? [y,n] \n";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += CLS_Bank_User::EN_Permissions::Update_Client;
        }

        cout << "Do You Want To Give This User Access To Find Client? [y,n] \n";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += CLS_Bank_User::EN_Permissions::Find_Client;
        }

        cout << "Do You Want To Give This User Access To Show Transactions? [y,n] \n";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += CLS_Bank_User::EN_Permissions::Transactions;
        }

        cout << "Do You Want To Give This User Access To Show Register Log In? [y,n] \n";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += CLS_Bank_User::EN_Permissions::Log_In_Register;
        }

        cout << "Do You Want To Give This User Access To Manage Users? [y,n] \n";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += CLS_Bank_User::EN_Permissions::Manage_Users;
        }
        return permissions;
    }

public:
    static void Update_User()
    {
        _DrawScreenHeader(" Update User");
        string User_Name = "";
        cout << "\nPlease Enter User Name: ";
        User_Name = clsInputValidate::ReadString();
        while (!CLS_Bank_User::Is_User_Exist(User_Name))
        {
            cout << "This User Name Is Not Exist ,Try Again: ";
            User_Name = clsInputValidate::ReadString();
        }
        CLS_Bank_User User = CLS_Bank_User::Find(User_Name);
        _Print_User_Info(User);

        _Read_User_Info(User);

        CLS_Bank_User::EN_Save_Results Save_Result;

        Save_Result = User.Save();

        switch (Save_Result)
        {
            case  CLS_Bank_User::EN_Save_Results::Saved_Successfully:
            {
                cout << "\nAccount Updated Successfully :-)\n";
                _Print_User_Info(User);
                break;
            }
            case CLS_Bank_User::EN_Save_Results::Failed_Empty_Object:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

        }
    }
};

