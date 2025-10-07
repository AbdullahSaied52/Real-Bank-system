#pragma once
#include"clsscreen.h"
#include "clsBankClient.h"
#include "clsString.h"
#include<fstream>
#include "clsString.h"
class cls_transfare_list:protected cls_screen
{
private:
	string _client1;
	string _client2;
	string _time;
	string _amount;
	string _balance1;
	string _balance2;
	string _current_userr;
	static void _print(cls_transfare_list general)
	{
		cout << setw(8) << left << "" << "| " << left << setw(17) << general._time;
		cout << setw(8) << left << "" << "| " << setw(9) << left << general._client1;
		cout << setw(8) << left << "" << "| " << setw(9) << left << general._client2;
		cout << setw(8) << left << "" << "| " << setw(9) << left << general._amount;
		cout << setw(8) << left << "" << "| " << setw(9) << left << general._balance1;
		cout << setw(8) << left << "" << "| " << setw(9) << left << general._balance2;
		cout << setw(8) << left << "" << "| " << setw(9) << left <<general._current_userr;

	}
	static vector<cls_transfare_list> vector_list()
	{
		vector<cls_transfare_list>data;
		string h;
		fstream file;
		file.open("transfare list.txt", ios::in);
		while (getline(file, h))
		{
			data.push_back(_convert_lint_to_object(h));
		}
		file.close();
		return data;
	}
	static cls_transfare_list _convert_lint_to_object(string h)
	{
		vector<string> v;
		v = clsString::Split(h,"#//#");
		return cls_transfare_list(v[0], v[1], v[2], v[3], v[4], v[5],v[6]);
	}
public:

	cls_transfare_list(string time, string u1, string u2, string amount, string balance1, string balance2,string current)
	{
		_client1 = u1;
		_client2 = u2;
		_time = time;
		_balance1 = balance1;
		_balance2 = balance2;
		_amount = amount;
		_current_userr = current;
	}
	
	static void tranfare_register()
	{
		
		vector<cls_transfare_list> d;
		d = vector_list();
		_headersscreen(" transfare register ", to_string(d.size())+" tranfares ");
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(17) << "time";
		cout << setw(8) << left << "" << "| " << left << setw(9) << "username s";
		cout << setw(8) << left << "" << "| " << left << setw(9) << "username d";
		cout << setw(8) << left << "" << "| " << left << setw(9) << "amount";
		cout << setw(8) << left << "" << "| " << left << setw(9) << "balance s";
		cout << setw(8) << left << "" << "| " << left << setw(9) << "balance d";
		cout << setw(8) << left << "" << "| " << left << setw(9) << "User";
		cout << endl;
		for(cls_transfare_list s:d)
			_print(s);
	}
};

