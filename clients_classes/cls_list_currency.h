#pragma once
#include"clsscreen.h"
#include"cls_curency.h"
#include<iostream>
class cls_list_currency:protected cls_screen
{
private:
	static void _print(cls_curency c)
	{
		cout << "|" << setw(30) << left << c.currency_country();
		cout << "|" << setw(10) << left << c.currency_code();
		cout << "|" << setw(30) << left << c.currency_name();
		cout << "|" << setw(17) << left << c.currency_rate();
		cout << endl;
	}
public:
	static void list_currencies()
	{
		vector<cls_curency> data = cls_curency::list_from_file();

		_headersscreen("list currencies screen",to_string(data.size()));
		
		cout << "|" << setw(30) << left << "Country";
		cout << "|" << setw(10) << left << "Code";
		cout << "|" << setw(30) << left << "Name";
		cout << "|" << setw(17) << left << "Rate(1$)";
		cout << "\n====================================================================================\n";
		cout << endl;
		for (cls_curency c : data)
		{
			_print(c);
		}
	}
};

