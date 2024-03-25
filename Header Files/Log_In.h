#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Bank_User.h"
#include "Header_Screen.h"
#include "Main_Screen.h"
#include "Global_User.h"

#include "cls_utli.h"

using namespace std;

class CLS_Log_In : protected CLS_Header_Screen
{
private:
	static bool _Log_In()
	{
		bool Log_In = false;
		string User_name;
		string Password;
		int Log_In_Failer_Iterator = 0;
		while (Log_In == false)
		{
			cout << setw(45) << left << "" << "Enter User Name: ";
			cout << setw(45) << left;
			cin >> User_name;

			cout << setw(45) << left << "" << "Enter Password: ";
			cout << setw(45) << left;
			cin >> Password;

			Current_User = CLS_Bank_User::Find(User_name, cls_utli::encrypte_text(Password , 100) );

			if (Current_User.Is_Empty())
			{
				Log_In_Failer_Iterator++;
				if (Log_In_Failer_Iterator == 3)
				{
					cout << endl << setw(45) << left << "" << "You Are Locked Contact Your Admin...\n\n\n";
					return false;
				}

				cout << endl;
				cout << setw(45) << left << "" << "Invalid User Name Or Password...\n";
				cout << setw(45) << left << "" << "You Have " << 3 - Log_In_Failer_Iterator << " Times To Try\n\n";
			}
			else
			{
				Log_In_Failer_Iterator = 0;
				Log_In = true;
			}
		}
		

		if (Log_In == true ) 
		{
			Current_User.Register_Log_IN();
			CLS_Main_Screen::Show_Main_Menu();
			return true;
		}
	}

public:
	static bool Show_Log_In_Screen()
	{
		system("cls");
		_DrawScreenHeader("    Log In");
		return _Log_In();
	}

};

