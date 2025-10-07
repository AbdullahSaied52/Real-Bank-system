#pragma once
#include"clsscreen.h"
#include"cls_curency.h"
class cls_find_currency:protected cls_screen
{
private :
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
	static void find_currency()
	{
		_headersscreen("find currency scree");
		string type;
		int ask;

		cout << "\ndo you want to find by [1]code or [2]country ? ";
		ask=clsInputValidate::ReadDblNumberBetween(1, 2);
		

		if (ask == 1)
		{
			cout << "\nenter code: ";
			cin >> type;
			cls_curency c = cls_curency::find_by_code(type);
			
			if (!c.is_empty())
				_print(c);
			else
				cout << "\nnot found\n";
		}
		else
		{
			cout << "\nenter country: ";
			cin >> type;
			cls_curency c = cls_curency::find_by_country(type);
			
			if (!c.is_empty())
				_print(c);
			else
				cout << "\nnot found\n";
		}

	}
};

