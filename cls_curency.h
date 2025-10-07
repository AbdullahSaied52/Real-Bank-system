#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"clsString.h"
#include<fstream>
using namespace std;
class cls_curency
{
private:
	enum en_mode { en_empty = 0, en_update = 1 };
	en_mode _mode;

	string _country;
	string _currencyCode;
	string _currencyName;
	float _rate;

	static cls_curency _convert_line_to_object(string l)
	{
		vector<string> v;
		v = clsString::Split(l, "#//#");
		return cls_curency(en_mode::en_update, v[0], v[1], v[2], stof(v[3]));
	}

	static vector<cls_curency> _data_from_file()
	{
		fstream file;
		file.open("Currencies.txt", ios::in);
		vector< cls_curency>data;
		string h;

		while (getline(file, h))
		{
			data.push_back(_convert_line_to_object(h));
		}
		file.close();
		return data;
	}

	static string _convert_object_to_line(cls_curency c,string separater = "#//#")
	{
		string line="";
		line += c._country + separater;
		line += c._currencyCode + separater;
		line += c._currencyName + separater;
		line += to_string(c._rate);
		return line;
	}

	static void _save_data_to_file(vector<cls_curency> c)
	{
		fstream file;
		file.open("Currencies.txt", ios::out);
		
		
		for (cls_curency d : c)
		{
			file << _convert_object_to_line(d) << endl;
		}
	}

	void _update_curency(float num)
	{
		vector<cls_curency> data;
		data = _data_from_file();
		
		for (cls_curency &c : data)
		{
			if (c.currency_code() == _currencyCode)
			{
				c._rate = num;
				break;
			}
		}
		_save_data_to_file(data);
	}

	static cls_curency _get_empty_curency()
	{
		return cls_curency(en_mode::en_empty, "", "", "", 0);
	}


public:
	cls_curency(en_mode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_mode = Mode;
		_country = Country;
		_currencyCode = CurrencyCode;
		_currencyName = CurrencyName;
		_rate = Rate;
	}

	string currency_country()
	{
		return _country;
	}

	string currency_code()
	{
		return _currencyCode;
	}

	string currency_name()
	{
		return _currencyName;
	}

	float currency_rate()
	{
		return _rate;
	}

	bool is_empty()
	{
		return (_mode == en_mode::en_empty);
	}

	static cls_curency find_by_code(string code)
	{
		vector< cls_curency> data;
		data = _data_from_file();

		for (cls_curency c : data)
		{
			if (c.currency_code() == clsString::UpperAllString(code))
			{
				return c;
				break;
			}
		}
		return _get_empty_curency();
	}

	static cls_curency find_by_country(string country)
	{
		vector< cls_curency> data;
		data = _data_from_file();

		for (cls_curency c : data)
		{
			if (c.currency_country() == clsString::UpperFirstLetterOfEachWord(country))
			{
				return c;
				break;
			}
		}
		return _get_empty_curency();
	}

	static bool is_currency_exist(string code)
	{
		cls_curency c = find_by_code(code);
		return(!c.is_empty());
	}

	static vector<cls_curency> list_from_file()
	{
		return _data_from_file();
	}

	void update_rate(float num)
	{
		_update_curency(num);
	}

};

