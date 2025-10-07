#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include<string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
using namespace std;
class clsBankClient : public clsPerson
{
private:
	enum enmode { emptymode = 0, updatemode = 1, addnewmode = 2 };
	enmode _enum_mode;
	string _account_number;
	string _pin_code;
	float _account_balance;
	bool _delete_client = false;

	static clsBankClient _convert_line_to_client_object(string line)
	{
		vector<string>vclient;
		vclient = clsString::Split(line, "#//#");
		return clsBankClient(enmode::updatemode, vclient[0], vclient[1], vclient[2]
			, vclient[3], vclient[4], vclient[5], stof(vclient[6]));
	}
	static string _convert_object_to_line(clsBankClient obj)
	{
		string data = "";
		data += obj.firstname + "#//#";
		data += obj.lastname + "#//#";
		data += obj.email + "#//#";
		data += obj.phone + "#//#";
		data += obj._account_number + "#//#";
		data += obj.pincode + "#//#";
		data += to_string(obj._account_balance);

		return data;
	}
	static vector<clsBankClient> _clients_from_file()
	{
		vector< clsBankClient>clients;
		fstream file;
		file.open("clients.txt", ios::in);
		string data;
		while (getline(file, data))
		{
			clients.push_back(_convert_line_to_client_object(data));
		}
		file.close();
		return clients;
	}
	static clsBankClient _get_empty_client_to_bject()
	{
		return clsBankClient(emptymode, "", "", "", "", "", "", 0);
	}

	void _update()
	{
		vector <clsBankClient> clientsdata;
		clientsdata = _clients_from_file();
		for (clsBankClient& client : clientsdata)
		{
			if (client._account_number == _account_number)
			{
				client = *this;
				break;
			}
		}
		_save_clients_in_file(clientsdata);
	}
	void _save_clients_in_file(vector <clsBankClient> d)
	{
		fstream file;
		string h;
		file.open("clients.txt", ios::out);
		for (clsBankClient s : d)
		{
			if (s._delete_client == false)
			{
				h = _convert_object_to_line(s);
				file << h << endl;
			}
		}
		file.close();
	}

	void _add_new()
	{
		_add_data_line_to_file(_convert_object_to_line(*this));
	}
	void _add_data_line_to_file(string data)
	{
		fstream file;
		string h;
		file.open("clients.txt", ios::app);
		h = (data);
		file << h << endl;
		file.close();
	}
	static string _prepare_data_to_transfare(clsBankClient c1,clsBankClient c2 ,int amount,string separater = "#//#")
	{
		string date = "";
		date += clsDate::get_time_string() + separater;
		date += c1.accountnumber() + separater;
		date += c2.accountnumber() + separater;
		date += to_string(amount) + separater;
		date += to_string(c1.accountbalance) + separater;
		date += to_string(c1.accountbalance)+separater;
		date += current_userr.username;
		return date;
	}
	static void _save_clients_transfare_list_in_file(clsBankClient c1, clsBankClient c2, int amount)
	{
		fstream file;
		string h;
		file.open("transfare list.txt", ios::app);
		h = _prepare_data_to_transfare(c1, c2, amount);
		file << h << endl;

		file.close();
	}
public:
	clsBankClient(enmode mode, string firstname, string lastname, string email, string phone
		, string accnumber, string pincode, float accbalance)
		:clsPerson(firstname, lastname, email, phone)
	{
		_enum_mode = mode;
		_account_number = accnumber;
		_account_balance = accbalance;
		_pin_code = pincode;
	}

	bool is_empty()
	{
		return (_enum_mode == enmode::emptymode);
	}
	// property set 
	void setpincode(string pin)
	{
		_pin_code = pin;
	}
	void setaccountbalance(float balance)
	{
		_account_balance = balance;
	}
	//property get
	string getpincode()
	{
		return _pin_code;
	}
	string accountnumber()
	{
		return _account_number;
	}
	float getaccountbalance()
	{
		return _account_balance;
	}

	__declspec(property(get = getpincode, put = setpincode)) string pincode;
	__declspec(property(get = getaccountbalance, put = setaccountbalance)) float accountbalance;
	static clsBankClient find(string accnumber)
	{
		vector< clsBankClient>client;
		fstream file;
		file.open("clients.txt", ios::in);
		string data;
		int i = 0;
		while (getline(file, data))
		{
			client.push_back(_convert_line_to_client_object(data));
			if (client[i]._account_number == accnumber)
			{
				file.close();
				return client[i];
			}
			i++;
		}
		file.close();
		return _get_empty_client_to_bject();
	}
	static clsBankClient find(string accnumber, string pin)
	{
		vector< clsBankClient>client;
		fstream file;
		file.open("clients.txt", ios::in);
		string data;
		while (getline(file, data))
		{
			client.push_back(_convert_line_to_client_object(data));
			if (client[0]._account_number == accnumber && client[0]._pin_code == pin)
			{
				file.close();
				return client[0];
			}
		}
		file.close();
		return _get_empty_client_to_bject();
	}
	static bool is_client_exist(string accnum)
	{
		vector< clsBankClient>client;
		fstream file;
		file.open("clients.txt", ios::in);
		string data;
		int i = 0;
		while (getline(file, data))
		{
			client.push_back(_convert_line_to_client_object(data));
			if (client[i]._account_number == accnum)
			{
				file.close();
				return true;
			}
			i++;
		}
		file.close();
		return false;
	}
	enum enumsavemode { savesuccess, savefailed, savefailedaccountexist };

	enumsavemode save_results()
	{
		if (_enum_mode == updatemode)
		{
			_update();
			return savesuccess;
		}
		else if (_enum_mode == emptymode)
		{
			return savefailed;
		}
		else if (_enum_mode == addnewmode)
		{
			_add_new();
			return savesuccess;
		}
	}

	static clsBankClient get_new_client(string accnumber)
	{
		return clsBankClient(enmode::addnewmode, "", "", "", "", accnumber, "", 0);
	}

	void delet()
	{
		vector<clsBankClient>clients;
		clients = _clients_from_file();
		for (clsBankClient& c : clients)
		{
			if (c._account_number == _account_number)
			{
				c._delete_client = true;
			}
		}
		_save_clients_in_file(clients);
		*this = _get_empty_client_to_bject();
	}

	static vector<clsBankClient> get_clients_list()
	{
		return _clients_from_file();
	}

	static double total_balance()
	{
		vector<clsBankClient> clients;
		clients = get_clients_list();
		double total = 0;
		for (clsBankClient c : clients)
		{
			total += c.accountbalance;
		}
		return total;
	}
	void deposite()
	{
		cout << "enter deposite amount: ";
		float amount;
		cin >> amount;
		cout << endl;
		cout << "do you want to perform deposite(y/n) ";
		string ask;
		cin >> ask;
		if (ask == "y")
		{
			cout << "\n successful operation \n";
			_account_balance += amount;
			save_results();
		}
		else
		{
			cout << "\nfailed operation \n";
		}
	}
	void withdraw()
	{
		cout << "enter deposite amount: ";
		float amount;
		cin >> amount;
		cout << "do you want to perform withdraw(y/n) ";
		string ask;
		cin >> ask;
		if (ask == "y")
		{
			cout << "\n successful operation \n";
			_account_balance -= amount;
			save_results();
		}
		else
		{
			cout << "\nfailed operation \n";
		}
	}

	static void transfare_list(clsBankClient c1, clsBankClient c2, int amount)
	{
		_save_clients_transfare_list_in_file(c1, c2, amount);
	}

	void print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << firstname;
		cout << "\nLastName    : " << lastname;
		cout << "\nFull Name   : " << fullname();
		cout << "\nEmail       : " << email;
		cout << "\nPhone       : " << phone;
		cout << "\nAcc. Number : " << _account_number;
		cout << "\nPassword    : " << _pin_code;
		cout << "\nBalance     : " << _account_balance;
		cout << "\n___________________\n";

	}
};

