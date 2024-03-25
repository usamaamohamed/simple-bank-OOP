#pragma once
#include <iostream>
#include <iomanip>

#include "Header_Screen.h"

#include "01_Client_List_Screen.h"
#include "02_Add_New_Client_Screen.h"
#include "03_Delete_Client_Screen.h"
#include "04_Update_Client_Screen.h"
#include "05_Find_Client_Screen.h"
#include "06_Transactions_Menu_Screen.h"
#include "07_Manage_Users_Screen.h"
#include "08_Log_In_Registers.h"
#include "09_Log_Out.h"

#include "cls_Input_Validate.h"

using namespace std;


class CLS_Main_Screen : protected CLS_Header_Screen
{
private:
    enum EN_Operations { EN_List_Clients = 1, EN_Add_New_Client = 2, EN_Delete_Client = 3, EN_Update_Client = 4, EN_Find_Client = 5, EN_Show_Transactions_Menu = 6, EN_Manage_Users = 7, EN_Log_In_Registers = 8 , EN_Exit = 9 };
    
    static short _Read_Main_Menu_Option()
    {

        cout << setw(45) << left << "" << "Choose what do you want to do? [1 to 9]: ";
        short Operation = clsInputValidate::Read_Short_Number_Between(1, 9);
        return Operation;
    }

    static void _Go_back_To_Main_Menu(int jump = 0)
    {
        if(jump == 0)
        {
            cout << "\n\n\n";
            cout << setw(45) << left << "" << "Press any key to go back to Main Menu...\n";
            system("pause>0");
        }
        Show_Main_Menu();
    }

    static void _Show_All_Clients_Screen()
    {
        CLS_Client_List_Screen::Show_All_CLients_List();
    }

    static void _Show_Add_New_Client_Screen()
    {
        CLS_Add_New_Client_Screen::Add_New_Client();
    }

    static void _Show_Delete_Client_Screen()
    {
        CLS_Delete_Client_Screen::Delete_Client();
    }

    static void _Show_Update_Client_Screen()
    {
        CLS_Update_Client_Screen::Update_Client();
    }

    static void _Show_Find_Client_Screen()
    {
        CLS_Find_Client::Update_Client();
    }

    static void _Show_Transactions_Menu()
    {
        CLS_Transactions_Menu_Screen::Show_Transactions_Menu_Screen();
    }

    static void _Show_Manage_Users_Screen()
    {
        CLS_Manage_Users::Show_Manage_Users_Screen();
    }

    static void _Show_Log_In_Registers()
    {
        CLS_Registers_List_Screen::Show_All_Registerss_List();
    }

    static void _Show_Exit_Screen()
    {
        CLS_Log_Out::Log_Out();
    }
    
    static void _Perform_Main_Menu_Option(EN_Operations Operation)
    {
        switch (Operation)
        {
            case CLS_Main_Screen::EN_List_Clients:
                system("cls");
                _Show_All_Clients_Screen();
                _Go_back_To_Main_Menu();
                break;

            case CLS_Main_Screen::EN_Add_New_Client:
                system("cls");
                _Show_Add_New_Client_Screen();
                _Go_back_To_Main_Menu();
                break;

            case CLS_Main_Screen::EN_Delete_Client:
                system("cls");
                _Show_Delete_Client_Screen();
                _Go_back_To_Main_Menu();
                break;

            case CLS_Main_Screen::EN_Update_Client:
                system("cls");
                _Show_Update_Client_Screen();
                _Go_back_To_Main_Menu();
                break;

            case CLS_Main_Screen::EN_Find_Client:
                system("cls");
                _Show_Find_Client_Screen();
                _Go_back_To_Main_Menu();
                break;

            case CLS_Main_Screen::EN_Show_Transactions_Menu:
                system("cls");
                _Show_Transactions_Menu();
                _Go_back_To_Main_Menu(1);
                break;

            case CLS_Main_Screen::EN_Manage_Users:
                system("cls");
                _Show_Manage_Users_Screen();
                _Go_back_To_Main_Menu(1);
                break;

            case CLS_Main_Screen::EN_Log_In_Registers:
                system("cls");
                _Show_Log_In_Registers();
                _Go_back_To_Main_Menu();
                break;

            case CLS_Main_Screen::EN_Exit:
                system("cls");
                _Show_Exit_Screen();
                break;

        }
    }

public:
	static void Show_Main_Menu()
	{
        system("cls");
		_DrawScreenHeader();
        cout << setw(40) << left << "" << "\t   [1] Show Client List.\n";
        cout << setw(40) << left << "" << "\t   [2] Add New Client.\n";
        cout << setw(40) << left << "" << "\t   [3] Delete Client.\n";
        cout << setw(40) << left << "" << "\t   [4] Update Client Info.\n";
        cout << setw(40) << left << "" << "\t   [5] Find Client.\n";
        cout << setw(40) << left << "" << "\t   [6] Transactions.\n";
        cout << setw(40) << left << "" << "\t   [7] Manage Users.\n";
        cout << setw(40) << left << "" << "\t   [8] Log In Registers List.\n";
        cout << setw(40) << left << "" << "\t   [9] Logout.\n";
        cout << setw(45) << left << "" << "----------------------------------------\n";
        _Perform_Main_Menu_Option( EN_Operations(_Read_Main_Menu_Option()) );
	}

};

