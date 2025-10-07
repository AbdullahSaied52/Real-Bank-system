#pragma once
using namespace std;
#include"clsscreen.h"
#include "global.h"
#include "clsmainscreen.h"
#include"login_data.h"
class cls_login :protected cls_screen
{
private:
	static void _login_user()
	{
		bool loginfailed = false;
		string username, password;
		int trys = 3;
		while (trys >= 1)
		{
			if (loginfailed&&trys>0)
			{
				cout << "incorrect try again" << endl;
			
				cout << "you have " << trys<<endl;
			}  
			if (trys > 0)
			{
				cout << "Enter Username? ";
				cin >> username;
				cout << "Enter Password? ";
				cin >> password;

				current_userr = cls_bank_user::find(username, password);
				loginfailed = current_userr.is_empty();
			}

			if (!loginfailed||trys==1)
				break;

			trys--;
		} 
		if (!loginfailed)
		{
			current_userr.save_login_data_to_file();
			clsmainscreen::ShowMainMenue();
		}
		else
		{
			stop = true;
			return;
		}
			
	}
public:
	static void login()
	{
		system("cls");
		_headersscreen("login screen ");
		_login_user();
	}
};

