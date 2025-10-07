#pragma once
#include "clsscreen.h"
#include "cls_curency.h"
class cls_update_rate:protected cls_screen
{
private:
	static void _print(cls_curency c)
	{
		cout << "\n------------------------\n";
		cout << "Country : " << c.currency_country() << endl;
		cout << "Code : " << c.currency_code() << endl;
		cout << "Name : " << c.currency_name() << endl;
		cout << "Rate(1$): " << c.currency_rate();
		cout << "\n------------------------\n";
	}
public:
	static void update_rate()
	{
		_headersscreen("update currency screen ");

		string code;
		cout << "enter code of currency: ";
		cin >> code;
		cls_curency c = cls_curency::find_by_code(code);
		if (!c.is_empty())
		{
			_print(c);
			float num;
			cout << "\nenter new currency rate : ";
			cin >> num;

			string ask;
			cout << "are you sure (y/n)? ";
			cin >> ask;
			if (ask == "y")
			{
				c.update_rate(num);
			}
			else
				return;
		}
		else
			cout << "\nnot found \n";


	}
};

