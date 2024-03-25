#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "CLS_Person.h"
#include "clsString.h"

using namespace std;

class CLS_Bank_Client : public CLS_Person
{
private:
	enum EN_Mode { Empty_Mode = 0 , Update_Mode = 1 , Add_New_Mode = 2 , Delete_Mode = 3 };
	EN_Mode _Mode;

	string _Account_Number;
	string _Pin_Code;
	float _Account_Balance;
	bool _Mark_For_Delete = false;

	static CLS_Bank_Client _Convert_Line_To_Client_Object(string Line , string Seperator = "#//#")
	{
		vector <string> V_Clients_Data;
		V_Clients_Data = clsString::Split(Line , Seperator);
		return CLS_Bank_Client(EN_Mode::Update_Mode , V_Clients_Data[0] , V_Clients_Data[1] , V_Clients_Data[2] , V_Clients_Data[3] , V_Clients_Data[4], 
													  V_Clients_Data[5] , stod(V_Clients_Data[6]));
	}
	
	static CLS_Bank_Client _Get_Empty_Client()
	{
		return CLS_Bank_Client(EN_Mode::Empty_Mode, "", "", "", "", "", "", 0);
	}

	static vector <CLS_Bank_Client> _Load_Clients_Data_From_File()
	{
		vector <CLS_Bank_Client> _V_CLients;

		fstream My_File;
		My_File.open("Clients.txt" , ios::in); //read mode
		if (My_File.is_open())
		{
			string Line;
			while (getline(My_File , Line))
			{
				CLS_Bank_Client Client = _Convert_Line_To_Client_Object(Line);
				_V_CLients.push_back(Client);
			}
			My_File.close();
		}
		return _V_CLients;
	}

	static string _Convert_CLient_Data_To_Line(CLS_Bank_Client Client , string seperator = "#//#")
	{
		string _Client_Data_Line = "";
		_Client_Data_Line += Client.First_Name + seperator;
		_Client_Data_Line += Client.Last_Name + seperator;
		_Client_Data_Line += Client.Email + seperator;
		_Client_Data_Line += Client.Phone + seperator;
		_Client_Data_Line += Client.Get_Account_Number() + seperator;
		_Client_Data_Line += Client.Pin_Code + seperator;
		_Client_Data_Line += to_string(Client.Account_Balance);
		return _Client_Data_Line;
	}

	static void _Save_Vector_Data_To_File(vector <CLS_Bank_Client> _V_CLients)
	{
		string _Client_Data_Line = "";
		fstream My_File;
		My_File.open("Clients.txt" , ios::out); //overwite mode
		if (My_File.is_open())
		{
			for(CLS_Bank_Client & C : _V_CLients)
			{
				if (C._Mark_For_Delete == false)
				{
					_Client_Data_Line = _Convert_CLient_Data_To_Line(C);
					My_File << _Client_Data_Line << endl;
				}
			}
			My_File.close();
		}
	}

	void _Update()
	{
		vector <CLS_Bank_Client> _V_CLients = _Load_Clients_Data_From_File();
		for (CLS_Bank_Client & Updated_Client : _V_CLients)
		{
			if(Updated_Client.Get_Account_Number() == Get_Account_Number() )
			{
				Updated_Client = *this;
				break;
			}
		}
		_Save_Vector_Data_To_File(_V_CLients);
	}

	void _Add_Data_Line_To_File(string New_Client_Data_Line)
	{
		fstream My_File;
		My_File.open("Clients.txt", ios::app);
		if (My_File.is_open())
		{
			My_File << New_Client_Data_Line << endl;
			My_File.close();
		}
	}

	void _Add_New_Client()
	{
		_Add_Data_Line_To_File(_Convert_CLient_Data_To_Line(*this));
	}
	
	string _Prepare_Trasfer_Log_Line( CLS_Bank_Client Client2, double Transfer_Amount, string User_Name ,string Seperator = "#//#")
	{
		string Line1, Line2, Line3, Line4, Line5;
		Line1 += clsDate::GetSystemDateTimeString() + Seperator;
		Line2 += Get_Account_Number() + Seperator;
		Line2 += Client2.Get_Account_Number() + Seperator;
		Line3 += to_string(Transfer_Amount) + Seperator;
		Line4 += to_string(Account_Balance) + Seperator;
		Line4 += to_string(Client2.Account_Balance) + Seperator;
		Line5 += User_Name;
		return (Line1 + Line2 + Line3 + Line4 + Line5);
	}

	void _Save_Transfers_Log( CLS_Bank_Client Destenation_Client, double Transfer_Amount , string User_Name)
	{
		//string Line = _Prepare_Trasfer_Log_Line(Client1 , Client2 , Transfer_Amount );
		fstream My_File;
		My_File.open("Transfers_Log.txt", ios::app);
		if (My_File.is_open())
		{
			My_File << _Prepare_Trasfer_Log_Line(Destenation_Client, Transfer_Amount , User_Name) << endl;
			My_File.close();
		}
	}
public:

	CLS_Bank_Client(EN_Mode Mode , string First_Name , string Last_Name , string Email , string Phone , string Account_Number , string Pin_Code , float Account_Balance) 
								: CLS_Person (First_Name , Last_Name , Email , Phone)
	{
		_Mode = Mode;
		_Account_Number = Account_Number;
		_Pin_Code = Pin_Code;
		_Account_Balance = Account_Balance;

	}
	
	struct ST_Transfer_Data
	{
		string Data_Time;
		double Source_Balance;
		string Source_Account;
		string Destination_Account;
		double Destination_Balance;
		double Transfer_Amount;
		string User_Name;
	};
private:
	static ST_Transfer_Data _Convert_Line_To_Transfer_Object(string Line, string Seperator = "#//#")
	{
		ST_Transfer_Data Transfer_Data;
		vector <string> Line_Data = clsString::Split(Line, Seperator);
		Transfer_Data.Data_Time = Line_Data[0];
		Transfer_Data.Source_Account = Line_Data[1];
		Transfer_Data.Destination_Account = Line_Data[2];
		Transfer_Data.Transfer_Amount = stod(Line_Data[3]);
		Transfer_Data.Source_Balance = stod(Line_Data[4]);
		Transfer_Data.Destination_Balance = stod(Line_Data[5]);
		Transfer_Data.User_Name = Line_Data[6];
		return Transfer_Data;
	}

	static vector <ST_Transfer_Data> _Load_Transfers_Data_From_File()
	{
		vector <ST_Transfer_Data> Transfers_Log_Data;
		string Line;
		fstream My_File;
		My_File.open("Transfers_Log.txt", ios::in); //read mode
		if (My_File.is_open())
		{
			while (getline(My_File, Line))
			{
				ST_Transfer_Data Transfer_Data = _Convert_Line_To_Transfer_Object(Line);
				Transfers_Log_Data.push_back(Transfer_Data);
			}
			My_File.close();
		}
		return Transfers_Log_Data;
	}
public:
	bool IS_Empty()
	{
		return (_Mode == EN_Mode::Empty_Mode);
	}
	//--------------------------------------------------------------------
	string Get_Account_Number()
	{
		return _Account_Number;
	}
	//--------------------------------------------------------------------
	void Set_Pin_Code(string Pin_Code)
	{
		_Pin_Code = Pin_Code;
	}
	string Get_Pin_Code()
	{
		return _Pin_Code;
	}
	__declspec(property(get = Get_Pin_Code, put = Set_Pin_Code)) string Pin_Code;
	//--------------------------------------------------------------------
	void Set_Account_Balance(float Account_Balance)
	{
		_Account_Balance = Account_Balance;
	}
	float Get_Account_Balance()
	{
		return _Account_Balance;
	}
	__declspec(property(get = Get_Account_Balance, put = Set_Account_Balance)) float Account_Balance;
	//--------------------------------------------------------------------
	//void Print()
	//{
	//	cout << "\nCLient Info:";
	//	cout << "\nFirstName      : " << First_Name;
	//	cout << "\nLastName       : " << Last_Name;
	//	cout << "\nFull Name      : " << Get_Full_Name();
	//	cout << "\nEmail          : " << Email;
	//	cout << "\nPhone          : " << Phone;
	//	cout << "\nAccount Number : " << _Account_Number;
	//	cout << "\nPassword       : " << _Pin_Code;
	//	cout << "\nBalance        : " << _Account_Balance;
	//	cout << "\n___________________\n";
	//}
	//--------------------------------------------------------------------
	static CLS_Bank_Client Find(string Account_Number)
	{
		fstream My_File;
		My_File.open("Clients.txt", ios::in);//read mode
		if (My_File.is_open())
		{
			string Line;
			while (getline(My_File , Line))
			{
				CLS_Bank_Client Client = _Convert_Line_To_Client_Object(Line);
				if (Client.Get_Account_Number() == Account_Number)
				{
					My_File.close();
					return Client;
				}
			}
			My_File.close();
		}
		return _Get_Empty_Client();
	}
	//--------------------------------------------------------------------
	static CLS_Bank_Client Find(string Account_Number , string Pin_Code)
	{
		vector <CLS_Bank_Client> V_Clients;
		fstream My_File;
		My_File.open("Clients.txt", ios::in);//read mode
		if (My_File.is_open())
		{
			string Line;
			while (getline(My_File, Line))
			{
				CLS_Bank_Client Client = _Convert_Line_To_Client_Object(Line);
				if (Client.Get_Account_Number() == Account_Number && Client.Get_Pin_Code() == Pin_Code)
				{
					My_File.close();
					return Client;
				}
			}
			My_File.close();
		}
		return _Get_Empty_Client();
	}
	//--------------------------------------------------------------------
	static bool Is_Client_Exist(string Account_Number)
	{
		CLS_Bank_Client Client = CLS_Bank_Client::Find(Account_Number);
		return (!Client.IS_Empty());
	}
	//--------------------------------------------------------------------
	enum EN_Save_Results {Failed_Empty_Object = 0 , Saved_Successfully = 1 , Failed_Account_Number_Exist = 2};
	EN_Save_Results Save()
	{
		switch (_Mode)
		{
			case EN_Mode::Empty_Mode:
				return EN_Save_Results::Failed_Empty_Object;

			case EN_Mode::Update_Mode:
				_Update();
				return EN_Save_Results::Saved_Successfully;
			
			case EN_Mode::Add_New_Mode:
				if (CLS_Bank_Client::Is_Client_Exist(_Account_Number))
				{
					return EN_Save_Results::Failed_Account_Number_Exist;
				}
				else
				{
					_Add_New_Client();
					return EN_Save_Results::Saved_Successfully;
				}
			case EN_Mode::Delete_Mode:
				return EN_Save_Results::Saved_Successfully;
		}
	}
	//--------------------------------------------------------------------
	static CLS_Bank_Client Add_New_Object(string Account_Number)
	{
		return CLS_Bank_Client(EN_Mode::Add_New_Mode ,"","","","", Account_Number ,"",0);
	}
	//--------------------------------------------------------------------
	bool Delete()
	{
		_Mode = EN_Mode::Delete_Mode;
		vector <CLS_Bank_Client> _V_Clients = _Load_Clients_Data_From_File();
		for (CLS_Bank_Client & C : _V_Clients)
		{
			if(C.Get_Account_Number() == _Account_Number)
			{
				C._Mark_For_Delete = true;
				break;
			}
		}
		_Save_Vector_Data_To_File(_V_Clients);
		*this = _Get_Empty_Client();
		return true;
	}
	//--------------------------------------------------------------------
	static vector <CLS_Bank_Client> Get_Clients_List()
	{
		return _Load_Clients_Data_From_File();
	}
	//--------------------------------------------------------------------
	static double Get_Total_Balances()
	{
		vector <CLS_Bank_Client> _V_Clients = _Load_Clients_Data_From_File();
		double Total_Balances = 0;
		for (CLS_Bank_Client & C : _V_Clients)
		{
			Total_Balances += C.Account_Balance;
		}
		return Total_Balances;
	}
	//--------------------------------------------------------------------
	void Deposit(double Amount)
	{
		_Account_Balance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _Account_Balance)
		{
			return false;
		}
		else
		{
			_Account_Balance -= Amount;
			Save();		
		}
		return true;
	}
	//--------------------------------------------------------------------
	bool Transfer(double Transfer_Amount , CLS_Bank_Client & Destenation_Client , string User_Name)
	{
		if (Transfer_Amount > _Account_Balance)
		{
			return false;
		}
		else
		{
			Withdraw(Transfer_Amount);
			Destenation_Client.Deposit(Transfer_Amount);
			_Save_Transfers_Log(Destenation_Client, Transfer_Amount , User_Name);
		}
	}
	//--------------------------------------------------------------------
	static vector <ST_Transfer_Data> Get_Transfers_Data()
	{
		return _Load_Transfers_Data_From_File();
	}
};