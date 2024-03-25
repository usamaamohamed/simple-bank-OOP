#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "CLS_Person.h"
#include "clsString.h"
#include "clsDate.h"
#include "cls_utli.h"

using namespace std;

class CLS_Bank_User : public CLS_Person
{
private:
	enum EN_Mode { Empty_Mode = 0, Update_Mode = 1, Add_New_Mode = 2, Delete_Mode = 3 };
	EN_Mode _Mode;
	string _User_Name;
	string _Password;
	int _Permissions;
	bool _Mark_For_Delete = false;



	static CLS_Bank_User _Convert_Line_To_User_Object(string Line , string Seperator = "#//#")
	{
		vector <string> _V_Users_Date;
		_V_Users_Date = clsString::Split(Line , Seperator);
		return ( CLS_Bank_User(EN_Mode::Update_Mode , _V_Users_Date[0] , _V_Users_Date[1] ,_V_Users_Date[2], _V_Users_Date[3], _V_Users_Date[4], _V_Users_Date[5] , stoi(_V_Users_Date[6]) ) );
	}

	static CLS_Bank_User _Get_Empty_User()
	{
		return CLS_Bank_User(EN_Mode::Empty_Mode , "" , "" , "" , "" , "" , "", 0);
	}

	static string _Convert_User_Data_To_Line(CLS_Bank_User User , string Seperator = "#//#")
	{
		string User_Data_Line = "";
		User_Data_Line += User.First_Name + Seperator;
		User_Data_Line += User.Last_Name  + Seperator;
		User_Data_Line += User.Email + Seperator;
		User_Data_Line += User.Phone + Seperator;
		User_Data_Line += User.User_Name + Seperator;
		User_Data_Line += cls_utli::encrypte_text(User.Password, 100) + Seperator;
		User_Data_Line += to_string(User.Permissions);
		return User_Data_Line;
	}

	static vector <CLS_Bank_User> _Load_Users_Data_From_File()
	{
		vector <CLS_Bank_User> _V_Users;
		fstream My_File;
		string Line;
		My_File.open("Users.txt", ios::in); //read mode
		if (My_File.is_open())
		{
			while (getline(My_File , Line))
			{
				CLS_Bank_User User = _Convert_Line_To_User_Object(Line);
				_V_Users.push_back(User);
			}
			My_File.close();
		}
		return _V_Users;
	}



	static void _Save_Vector_Data_To_File(vector <CLS_Bank_User> _V_Users)
	{
		string _User_Data_Line = "";
		fstream My_File;
		My_File.open("Users.txt", ios::out); //overwite mode
		if (My_File.is_open())
		{
			for (CLS_Bank_User & C : _V_Users)
			{
				if (C._Mark_For_Delete == false)
				{
					_User_Data_Line = _Convert_User_Data_To_Line(C);
					My_File << _User_Data_Line << endl;
				}
			}
			My_File.close();
		}
	}

	void _Update()
	{
		vector <CLS_Bank_User> _V_Users = _Load_Users_Data_From_File();
		for ( CLS_Bank_User & Updated_User : _V_Users)
		{
			if( Updated_User.User_Name == Get_User_Name() )
			{
				Updated_User = *this;
				break;
			}
		}
		_Save_Vector_Data_To_File(_V_Users);
	}

	void _Add_Data_Line_To_File(string New_User_Data_Line)
	{
		fstream My_File;
		My_File.open("Users.txt", ios::app);
		if (My_File.is_open())
		{
			My_File << New_User_Data_Line << endl;
			My_File.close();
		}
	}

	void _Add_New_User()
	{
		_Add_Data_Line_To_File(_Convert_User_Data_To_Line(*this));
	}

	string _Prepare_Log_In_Data_Line(string Seperator = " \\\\ ")
	{
		string Line = "";
		Line += clsDate::GetSystemDateTimeString() + Seperator;
		Line += User_Name + Seperator;
		Line += Get_Full_Name() + Seperator;
		Line += Password + Seperator;
		Line += to_string(Permissions);
		return Line;
	}

public:
	CLS_Bank_User(EN_Mode Mode , string First_Name , string Last_Name , string Email , string Phone , string User_Name, string Password , int Permissions) 
		: CLS_Person (First_Name , Last_Name , Email , Phone)
	{
		_Mode = Mode;
		_User_Name = User_Name;
		_Password = Password;
		_Permissions = Permissions;
	}
	

	struct ST_Register
	{
		string Date_Time;
		string User_Name;
		string Full_Name;
		string Password;
		int Permissions;
	};
private:
	static ST_Register _Convert_Line_To_Register(string Line, string Seperator)
	{
		vector <string> _V_Registers = clsString::Split(Line, Seperator);
		ST_Register Register;
		Register.Date_Time = _V_Registers[0];
		Register.User_Name = _V_Registers[1];
		Register.Full_Name = _V_Registers[2];
		Register.Password = _V_Registers[3];
		Register.Permissions = stoi(_V_Registers[4]);
		return Register;
	}

	static vector <ST_Register> _Load_Registers_Data_From_File()
	{
		vector <ST_Register> _V_Registers;
		fstream My_File;
		string Line;
		My_File.open("LogIn_Register.txt", ios::in); //read mode
		if (My_File.is_open())
		{
			while (getline(My_File, Line))
			{
				ST_Register Register = _Convert_Line_To_Register(Line, " \\\\ ");
				_V_Registers.push_back(Register);
			}
			My_File.close();
		}
		return _V_Registers;
	}

public:
	enum EN_Permissions {All = -1 , List_Client = 1 , Add_New_Client = 2 , Delete_Client = 4 , Update_Client = 8 , Find_Client = 16 , Transactions = 32 , Manage_Users = 64 , Log_In_Register = 124};

	bool Is_Empty()
	{
		return (_Mode ==_Mark_For_Delete);
	}

	bool Marked_For_Delete()
	{
		return _Mark_For_Delete;
	}
	//--------------------------------------------------------------------
	void Set_User_Name(string User_name)
	{
		_User_Name = User_name;
	}
	string Get_User_Name()
	{
		return _User_Name;
	}
	__declspec(property(get = Get_User_Name, put = Set_User_Name)) string User_Name;
	//--------------------------------------------------------------------
	void Set_Password(string Password)
	{
		_Password = Password;
	}
	string Get_Password()
	{
		return _Password;
	}
	__declspec(property(get = Get_Password, put = Set_Password)) string Password;
	//--------------------------------------------------------------------
	void Set_Permissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int Get_Permissions()
	{
		return _Permissions;
	}
	__declspec(property(get = Get_Permissions, put = Set_Permissions)) int Permissions;
	//--------------------------------------------------------------------
	
	static CLS_Bank_User Find(string User_Name)
	{
		fstream My_File;
		My_File.open("Users.txt" , ios::in); // read mode
		if (My_File.is_open())
		{
			string Line;
			while (getline(My_File , Line))
			{
				CLS_Bank_User User = _Convert_Line_To_User_Object(Line);
				if (User.User_Name == User_Name)
				{
					My_File.close();
					return User;
				}
			}
			My_File.close();
		}
		return _Get_Empty_User();
	}

	static CLS_Bank_User Find(string User_Name , string Password)
	{
		fstream My_File;
		My_File.open("Users.txt", ios::in); // read mode
		if (My_File.is_open())
		{
			string Line;
			while (getline(My_File, Line))
			{
				CLS_Bank_User User = _Convert_Line_To_User_Object(Line);
				if (User.User_Name == User_Name && User.Password == Password)
				{
					My_File.close();
					return User;
				}
			}
			My_File.close();
		}
		return _Get_Empty_User();
	}
	
	//--------------------------------------------------------------------
	static bool Is_User_Exist(string User_Name)
	{
		CLS_Bank_User User = CLS_Bank_User::Find(User_Name);
		return(!User.Is_Empty());
	}
	//--------------------------------------------------------------------
	enum EN_Save_Results { Failed_Empty_Object = 0, Saved_Successfully = 1, Failed_User_Exist = 2 };
	EN_Save_Results Save()
	{
		switch (_Mode)
		{
			case CLS_Bank_User::Empty_Mode:
				return EN_Save_Results::Failed_Empty_Object;

			case CLS_Bank_User::Update_Mode:
				_Update();
				return EN_Save_Results::Saved_Successfully;
			
			case CLS_Bank_User::Add_New_Mode:
				if( CLS_Bank_User::Is_User_Exist(_User_Name) )
				{
					return EN_Save_Results::Failed_User_Exist;
				}
				else
				{
					_Add_New_User();
					return EN_Save_Results::Saved_Successfully;
				}
			case CLS_Bank_User::Delete_Mode:
				return EN_Save_Results::Saved_Successfully;
		}
	}
	//--------------------------------------------------------------------
	bool Delete()
	{
		vector <CLS_Bank_User> _V_Users = _Load_Users_Data_From_File();
		for (CLS_Bank_User& C : _V_Users)
		{
			if (C.User_Name == Get_User_Name() )
			{
				C._Mark_For_Delete = true; 
				break;
			}
		}
		_Save_Vector_Data_To_File(_V_Users);
		*this = _Get_Empty_User();
		return true;
	}
	//--------------------------------------------------------------------
	static CLS_Bank_User Add_New_User_Object(string User_Name)
	{
		return CLS_Bank_User(EN_Mode::Add_New_Mode, "", "", "", "", User_Name, "", 0);
	}
	//--------------------------------------------------------------------
	static vector <CLS_Bank_User> Get_Users_List()
	{
		return _Load_Users_Data_From_File();
	}

	static vector <ST_Register> Get_Registers_List()
	{
		return _Load_Registers_Data_From_File();
	}
	//--------------------------------------------------------------------
	bool Check_Permission(EN_Permissions Permsission)
	{
		if (this->Permissions == EN_Permissions::All)
		{
			return true;
		}
		else if ( (this->Permissions & Permsission) == Permsission)
		{
			return true;
		}
		else
			return false;
	}
	//--------------------------------------------------------------------
	void Register_Log_IN()
	{
		string Log_in_Data_Line = _Prepare_Log_In_Data_Line();
		fstream My_File;
		My_File.open("LogIn_Register.txt" , ios::app);
		if (My_File.is_open())
		{
			My_File << Log_in_Data_Line << "\n";
			My_File.close();
		}
	}
};

