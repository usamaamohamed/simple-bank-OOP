#pragma once

#include <iostream>
#include <string>

using namespace std;

class CLS_Person
{
private:

	string _First_Name;
	string _Last_Name;
	string _Email;
	string _Phone;

public:

	CLS_Person(string First_Name, string Last_Name, string Email, string Phone)
	{
		_First_Name = First_Name;
		_Last_Name = Last_Name;
		_Email = Email;
		_Phone = Phone;
	}
	//--------------------------------------------------------------------
	void Set_First_Name(string First_Name)
	{
		_First_Name = First_Name;
	}

	string Get_First_Name()
	{
		return _First_Name;
	}
	__declspec(property (get = Get_First_Name, put = Set_First_Name)) string First_Name;
	//--------------------------------------------------------------------
	void Set_Last_Name(string Last_Name)
	{
		_Last_Name = Last_Name;
	}

	string Get_Last_Name()
	{
		return _Last_Name;
	}
	__declspec(property (get = Get_Last_Name, put = Set_Last_Name)) string Last_Name;
	//--------------------------------------------------------------------
	string Get_Full_Name()
	{
		return _First_Name + " " + _Last_Name;
	}
	//--------------------------------------------------------------------
	void Set_Email(string Email)
	{
		_Email = Email;
	}

	string Get_Email()
	{
		return _Email;
	}
	__declspec(property(get = Get_Email, put = Set_Email)) string Email;
	//--------------------------------------------------------------------
	void Set_Phone(string Phone)
	{
		_Phone = Phone;
	}

	string Get_Phone()
	{
		return _Phone;
	}
	__declspec(property(get = Get_Phone, put = Set_Phone)) string Phone;
	//--------------------------------------------------------------------
	void Print()
	{
		cout << "INFO:\n____________________________\n";
		cout << "First Name: " << _First_Name << "\n";
		cout << "Last Name: " << _Last_Name << "\n";
		cout << "Email: " << _Email << "\n";
		cout << "Phone: " << _Phone << "\n";

	}

};

