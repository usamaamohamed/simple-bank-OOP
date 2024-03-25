#include <iostream>
#include "Header Files\Log_In.h"

using namespace std;

int main()
{
	while (true)
	{
		if (!CLS_Log_In::Show_Log_In_Screen())
		{
			break;
		}
	}
	return 0;
}