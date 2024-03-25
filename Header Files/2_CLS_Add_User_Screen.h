#pragma once
#pragma once
#include <iostream>
#include "cls_Input_Validate.h"
#include "Bank_User.h"
#include "Header_Screen.h"

using namespace std;

class CLS_Add_New_User_Screen : protected CLS_Header_Screen
{
private:
    static void _Read_User_Info(CLS_Bank_User & User , string User_Name)
    {
        cout << "\nEnter First Name: ";
        User.First_Name = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        User.Last_Name = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        //cout << "\nEnter User Name: ";
        User.User_Name = User_Name;

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions: ";
        User.Permissions = _Read_User_Permsissions();
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
    static void Add_New_User()
    {
        _DrawScreenHeader(" Add New User");
        string User_Name = "";
        cout << "Please Enter User Name: ";
        User_Name = clsInputValidate::ReadString();
        while (CLS_Bank_User::Is_User_Exist(User_Name))
        {
            cout << "This User Already Exists ,Choose Another User Name: ";
            User_Name = clsInputValidate::ReadString();
        }
        CLS_Bank_User New_Client = CLS_Bank_User::Add_New_User_Object(User_Name);
        _Read_User_Info(New_Client , User_Name);
        CLS_Bank_User::EN_Save_Results Save_Results;
        Save_Results = New_Client.Save();
        switch (Save_Results)
        {
            case  CLS_Bank_User::EN_Save_Results::Saved_Successfully:
            {
                cout << "\nUser Addeded Successfully :-)\n";
                _Print_User_Info(New_Client);
                break;
            }
            case CLS_Bank_User::EN_Save_Results::Failed_Empty_Object:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }
            case CLS_Bank_User::EN_Save_Results::Failed_User_Exist:        {
                cout << "\nError User was not saved because User Name is used!\n";
                break;
            }
        }
    }
};


