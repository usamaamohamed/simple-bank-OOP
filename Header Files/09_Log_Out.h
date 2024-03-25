#pragma once
#include "Global_User.h"
#include "Bank_User.h"
class CLS_Log_Out
{
public:

	static void Log_Out()
	{
		Current_User = CLS_Bank_User::Find("", "");
	}
};

