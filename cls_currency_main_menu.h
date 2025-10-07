#pragma once
#include"clsscreen.h"
#include"cls_list_currency.h"
#include"cls_find_currency.h"
#include"clsInputValidate.h"
#include"cls_update_rate.h"
#include"cls_currency_calculator.h"
class cls_currency_main_menu: protected cls_screen
{
private:
	enum en_select { en_list = 1, en_find = 2,en_update=3,en_currency=4,en_main=5 };

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		currency_menu();
	}

	static void _perform_option()
	{
		cout << "\t\t\t\t\tenter option from 1 ro 5 :";
		short num = clsInputValidate::ReadDblNumberBetween(1, 5);
		
		switch (num)
		{
		case en_list:
			system("cls");
			_list_currency();
			_GoBackToMainMenue();
			break;
		case en_find:
			system("cls");
			_find_currency();
			_GoBackToMainMenue();
			break;
		case en_update:
			system("cls");
			_update_currency();
			_GoBackToMainMenue();
			break;
		case en_currency:
			system("cls");
			_currency_calculator();
			_GoBackToMainMenue();
			break;
		case en_main:
		{

		}
		}
	}

	static void _list_currency()
	{
		cls_list_currency::list_currencies();
	}

	static void _find_currency()
	{
		cls_find_currency::find_currency();
	}

	static void _update_currency()
	{
		cls_update_rate::update_rate();
	}

	static void _currency_calculator()
	{
		cls_currency_calculator::currency_calculator();
	}


public:
	static void currency_menu()
	{
		system("cls");
		_headersscreen("\t\tCurency menu ");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurency menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find currency. \n";
		cout << setw(37) << left << "" << "\t[3] Update currency. \n";
		cout << setw(37) << left << "" << "\t[4] Currency calculator \n";
		cout << setw(37) << left << "" << "\t[5] Main menu. \n";
		cout << setw(37) << left << "" << "===========================================\n";
		_perform_option();
	}
};

