#pragma once
#include <iostream>
#include <iomanip>
#include "Header_Screen.h"
#include "Bank_User.h"

#include "1_Users_List_Screen.h"
#include "2_CLS_Add_User_Screen.h"
#include "3_Delete_User_Screen.h"
#include "4_Update_User_Screen.h"
#include "5_Find_User_Screen.h"

#include "cls_Input_Validate.h"

using namespace std;

class CLS_Manage_Users : protected CLS_Header_Screen
{
private:
	enum EN_Manage_Users { List_users = 1, Add_New_User = 2, Delete_User = 3, Update_User = 4, Find_User = 5, Main_Menu = 6 };
	
	static short _Read_Manage_Users_Option()
	{
		cout << setw(45) << left << "" << "Choose what do you want to do? [1 to 6]: ";
		short Operation = clsInputValidate::Read_Short_Number_Between(1, 6);
		return Operation;
	}
	static void _Go_Back_To_Manage_Users_Menu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menu...\n";
		system("pause>0");
		Show_Manage_Users_Screen();
	}

	static void _Show_List_Users_Screen()
	{
		CLS_List_Users_Screen::_Show_Users_List_Screen();
	}

	static void _Show_Add_User_Screen()
	{
		CLS_Add_New_User_Screen::Add_New_User();
	}

	static void _Show_Delete_User_Screen()
	{
		CLS_Delete_User_Screen::Delete_Client();
	}

	static void _Show_Update_user_Screen()
	{
		CLS_Update_User_Screen::Update_User();
	}
	
	static void _Show_Find_User_Screen()
	{
		CLS_Find_User::Update_Client();
	}


	static void _perform_Manage_Users_Option(EN_Manage_Users Operation)
	{
		switch (Operation)
		{
			case CLS_Manage_Users::List_users:
				system("cls");
				_Show_List_Users_Screen();
				_Go_Back_To_Manage_Users_Menu();
				break;

			case CLS_Manage_Users::Add_New_User:
				system("cls");
				_Show_Add_User_Screen();
				_Go_Back_To_Manage_Users_Menu();
				break;
			case CLS_Manage_Users::Delete_User:
				system("cls");
				_Show_Delete_User_Screen();
				_Go_Back_To_Manage_Users_Menu();
				break;
			case CLS_Manage_Users::Update_User:
				system("cls");
				_Show_Update_user_Screen();
				_Go_Back_To_Manage_Users_Menu();
				break;
			case CLS_Manage_Users::Find_User:
				system("cls");
				_Show_Find_User_Screen();
				_Go_Back_To_Manage_Users_Menu();
				break;
			case CLS_Manage_Users::Main_Menu:
				break;
		}
	}

public:
	static void Show_Manage_Users_Screen()
	{
		if (!Check_Access_Rights(CLS_Bank_User::EN_Permissions::Manage_Users))
		{
			cout << "\n\n\n";
			cout << setw(45) << left << "" << "Press any key to go back to Main Menu...\n";
			system("pause>0");
			return;
		}
		system("cls");
		_DrawScreenHeader("  Manage Users");
		cout << setw(45) << left << "" << "\t  [1] List Users.\n";
		cout << setw(45) << left << "" << "\t  [2] Add New User.\n";
		cout << setw(45) << left << "" << "\t  [3] Delete User.\n";
		cout << setw(45) << left << "" << "\t  [4] Update User.\n";
		cout << setw(45) << left << "" << "\t  [5] Find User.\n";
		cout << setw(45) << left << "" << "\t  [6] Main Menu.\n";
		cout << setw(45) << left << "" << "----------------------------------------\n";
		_perform_Manage_Users_Option( EN_Manage_Users(_Read_Manage_Users_Option() ) );
	}

};

