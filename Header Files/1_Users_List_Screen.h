#pragma once
#include <iostream>
#include "Bank_User.h"
#include "Header_Screen.h"
#include "cls_Input_Validate.h"
#include "cls_utli.h"

using namespace std;

class CLS_List_Users_Screen : protected CLS_Header_Screen
{
private:
    static void Print_Client_Data(CLS_Bank_User& User)
    {
        cout << setw(10) << left << "" << "| " << left << setw(15) << User.User_Name;
        cout << "| " << left << setw(30) << User.Get_Full_Name();
        cout << "| " << left << setw(12) << User.Phone;
        cout << "| " << left << setw(20) << User.Email;
        cout << "| " << left << setw(10) << cls_utli::decrypte_text(User.Password,100);
        cout << "| " << left << setw(12) << User.Permissions;
    }

public:
	static void _Show_Users_List_Screen()
	{
        vector <CLS_Bank_User> _V_Users = CLS_Bank_User::Get_Users_List();

        string Title = "  Users List";
        string SubTitle = "(" + to_string(_V_Users.size()) + ") Users";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(10) << left << "" << "__________________________________________________________________________________________________________________\n" << endl;
        cout << setw(10) << left << "" << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(30) << "Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions" << endl;
        cout << setw(10) << left << "" << "__________________________________________________________________________________________________________________\n" << endl;

        if (_V_Users.size() == 0)
        {
            cout << "\n\n\n                                                     No Clients Found                                        \n\n\n";
            cout << setw(10) << left << "" << "__________________________________________________________________________________________________________________\n" << endl;
        }
        else
        {
            for (CLS_Bank_User & Client : _V_Users)
            {
                Print_Client_Data(Client);
                cout << endl;
            }   
            cout << setw(10) << left << "" << "__________________________________________________________________________________________________________________\n" << endl;
        }

	}
};

