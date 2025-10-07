#pragma once
#include "cls_curency.h"
#include"clsscreen.h"
class cls_currency_calculator:protected cls_screen
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
	static void currency_calculator()
	{
		cout << "enter currency code1: ";
		string c1;
		cin >> c1;
		
		cout << "enter currency code2: ";
		string c2;
		cin >> c2;

		cls_curency cur1 = cls_curency::find_by_code(c1);
		_print(cur1);
		cls_curency cur2 = cls_curency::find_by_code(c2);
		if (!(cur2.currency_code() == "USD"))
			_print(cur2);
		cout << "enter amount : ";
		float num;
		cin >> num;

		cout << num << " " << cur1.currency_code() << " = " << (num / cur1.currency_rate()) * cur2.currency_rate()<<" "<<cur2.currency_code() << endl;

	}
};

