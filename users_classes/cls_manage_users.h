#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"cls_list_users.h"
#include"cls_add_user.h"
#include"cls_delete_user.h"
#include"cls_update_user.h"
#include"cls_find_user.h"
using namespace std;
class cls_manage_users :protected cls_screen
{
private:
	enum enum_users {
		en_list = 1, en_find = 5, en_add = 2,
		en_delete = 3, en_update = 4, en_main = 6
	};
	static short _read_choice()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		int c;
		c = clsInputValidate::ReadIntNumberBetween(1, 6);
		return c;
	}
	static void list_users()
	{
		cls_list_users::list_users();
	}
	static void find_user()
	{
		cls_find_user::find_user();
	}
	static void add_user()
	{
		cls_add_user::add_userr();
	}
	static void delete_user()
	{
		cls_delete_user::delete_user();
	}
	static void update_user()
	{
		cls_update_user::update_user();
	}
	static void _perform_option(enum_users eu)
	{
		switch (eu)
		{
		case en_add:
		{
			system("cls");
			add_user();
			_GoBackToManageUsersMenue();
			break;
		}
		case en_delete:
		{
			system("cls");
			delete_user();
			_GoBackToManageUsersMenue();
			break;
		}
		case en_find:
		{
			system("cls");
			find_user();
			_GoBackToManageUsersMenue();
			break;
		}
		case en_update:
		{
			system("cls");
			update_user();
			_GoBackToManageUsersMenue();
			break;
		}
		case en_list:
		{
			system("cls");
			list_users();
			_GoBackToManageUsersMenue();
			break;
		}
		case en_main:
		{

		}
		}
	}
	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system("pause>0");
		manage_users_screen();
	}
public:
	static void manage_users_screen()
	{
		if (!check_user_screen(cls_bank_user::enpermission::en_manage_users))
			return;
		system("cls");
		_headersscreen("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_perform_option((enum_users)_read_choice());
	}
};

