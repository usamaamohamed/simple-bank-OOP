#pragma once
#include <iostream>
#include <iomanip>

#include "Bank_Client.h"
#include "Header_Screen.h"

#include "1_Deposite_Screen.h"
#include "2_Withdraw_Screen.h"
#include "3_Total_Balances_Screen.h"
#include "4_Transfers.h"
#include "5_Transfers_Log.h"

#include "cls_Input_Validate.h"
using namespace std;

class CLS_Transactions_Menu_Screen : protected CLS_Header_Screen
{
private:
	enum EN_Transaction_Option { Deposite = 1, Withdraw = 2, Total_Balances = 3, Transfers = 4 , Transfers_Log = 5 , Main_Menu = 6 };

	static short _Read_Transactions_Menu_Option()
	{
		cout << setw(45) << left << "" << "Choose what do you want to do? [1 to 6]: ";
		short Operation = clsInputValidate::Read_Short_Number_Between(1, 6);
		return Operation;
	}

	static void _Go_Back_To_Transactions_Menu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menu...\n";
		system("pause>0");
		Show_Transactions_Menu_Screen();
	}

	static void _Show_Deposite_Screen()
	{
		CLS_Deposite_Screen::Deposit_Operation();
	}
	static void _Show_Withdraw_Screen()
	{
		CLS_Withdraw_Screen::Withdraw_Operation();
	}
	static void _Show_Total_Balances_Screen()
	{
		CLS_Total_Balances_Screen::Show_Total_Balances();
	}
	static void _Show_Transfers_Screen()
	{
		CLS_Transfers::_Show_Transactions();
	}


	static void _Show_Transfers_Log_Screen()
	{
		CLS_Transfer_Log::Show_All_Transfers_List();
	}

	static void _Perform_Transaction_Option(EN_Transaction_Option Operation)
	{
		switch (Operation)
		{
			case CLS_Transactions_Menu_Screen::Deposite:
				system("cls");
				_Show_Deposite_Screen();
				_Go_Back_To_Transactions_Menu();
				break;
		
			case CLS_Transactions_Menu_Screen::Withdraw:
				system("cls");
				_Show_Withdraw_Screen();
				_Go_Back_To_Transactions_Menu();
				break;
		
			case CLS_Transactions_Menu_Screen::Total_Balances:
				system("cls");
				_Show_Total_Balances_Screen();
				_Go_Back_To_Transactions_Menu();
				break;
		
			case CLS_Transactions_Menu_Screen::Transfers:
				system("cls");
				_Show_Transfers_Screen();
				_Go_Back_To_Transactions_Menu();
				break;

			case CLS_Transactions_Menu_Screen::Transfers_Log:
				system("cls");
				_Show_Transfers_Log_Screen();
				_Go_Back_To_Transactions_Menu();
				break;

			case CLS_Transactions_Menu_Screen::Main_Menu:
				// -_-
			break;
		}
	}
public:
	static void Show_Transactions_Menu_Screen()
	{
		if (!Check_Access_Rights(CLS_Bank_User::EN_Permissions::Transactions))
		{
			cout << "\n\n\n";
			cout << setw(45) << left << "" << "Press any key to go back to Main Menu...\n";
			system("pause>0");
			return;
		}
		system("cls");
		_DrawScreenHeader("Transactions Menu");
        cout << setw(45) << left << "" << "\t  [1] Deposite.\n";
        cout << setw(45) << left << "" <<" \t  [2] Withdraw.\n";
        cout << setw(45) << left << "" << "\t  [3] Total Balances.\n";
		cout << setw(45) << left << "" << "\t  [4] Transfers.\n";
		cout << setw(45) << left << "" << "\t  [5] Transfers Log.\n";
        cout << setw(45) << left << "" << "\t  [6] Main Menu.\n";
		cout << setw(45) << left << "" << "----------------------------------------\n";
		_Perform_Transaction_Option( EN_Transaction_Option( _Read_Transactions_Menu_Option() ) );
	}

};

