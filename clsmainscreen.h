#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#include "clsscreen.h"
#include "clsInputValidate.h"
#include "clsclientlistscreen.h"
#include "clsaddnewclient.h"
#include"cls_delete_client.h"
#include "cls_update_client.h"
#include"cls_find_client.h"
#include"cls_transaction_screen.h"
#include"cls_total_balance.h"
#include "cls_manage_users.h"
#include"cls_login.h"
#include"global.h"
#include"cls_login_register.h"
#include "cls_currency_main_menu.h"
class clsmainscreen :protected cls_screen
{
private:
	enum enumselect {
		showclient = 1, addclient = 2, deleteclient = 3, updateclient = 4, findclient = 5
		, transaction = 6, manageusers = 7, login_register=8,curency=9,logout = 10
	};
	static void _showclientlist()
	{
		cls_client_list_screen::showclientlest();
	}
	static void _addnewclient()
	{
		clsaddnewclient::add_new_client();
	}
	static void _deleteclient()
	{
		cls_delete_client::deleteclient();
	}
	static void _updateclient()
	{
		cls_update_client::updateclient();
	}
	static void _findclient()
	{
		cls_find_client::find_client();
	}
	static void _Transaction()
	{
		cls_transaction_screen::ShowTransactionsMenue();
	}
	static void _ManageUsers()
	{
		cls_manage_users::manage_users_screen();
	}
	static void _Logout()
	{
		current_userr = cls_bank_user::find("", "");
	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}
	static short _readoption()
	{
		cout << "\t\t\t\t\tenter option from 1 ro 10 :";
		short num = clsInputValidate::ReadDblNumberBetween(1, 10);
		return num;
	}
	static void _login_data()
	{
		cls_login_register::login_register_data();
	}
	static void _curency_menu()
	{
		cls_currency_main_menu::currency_menu();
	}
	static void _performmainmenuoption(enumselect e)
	{
		switch (e)
		{
		case(enumselect::showclient):
			system("cls");
			_showclientlist();
			_GoBackToMainMenue();
			break;
		case(enumselect::addclient):
			system("cls");
			_addnewclient();
			_GoBackToMainMenue();
			break;
		case(enumselect::findclient):
			system("cls");
			_findclient();
			_GoBackToMainMenue();
			break;
		case(enumselect::deleteclient):
			system("cls");
			_deleteclient();
			_GoBackToMainMenue();
			break;
		case(enumselect::updateclient):
			system("cls");
			_updateclient();
			_GoBackToMainMenue();
			break;
		case(enumselect::manageusers):
			system("cls");
			_ManageUsers();
			_GoBackToMainMenue();
			break;
		case(enumselect::transaction):
			system("cls");
			_Transaction();
			_GoBackToMainMenue();
			break;
		case(enumselect::login_register):
			system("cls");
			_login_data();
			_GoBackToMainMenue();
			break;
		case curency:
			system("cls");
			_curency_menu();
			_GoBackToMainMenue();
			break;
		case(enumselect::logout):
			system("cls");
			_Logout();
			break;
		}

	}
public:
	static void ShowMainMenue()
	{
		system("cls");
		_headersscreen("\t\tmain menu");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] login register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency menu.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_performmainmenuoption((enumselect)_readoption());
	}
};

