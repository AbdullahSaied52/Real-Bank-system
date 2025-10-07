#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include<string>
#include "clsPerson.h"
#include "clsString.h"
#include"clsDate.h"
#include "clsInputValidate.h"
#include"clsscreen.h"

using namespace std;
class cls_bank_user :public clsPerson
{
private:
	enum enmode { emptymode = 0, updatemode = 1, addnewmode = 2 };
	enmode _enum_mode;
	string _username;
	string _password;
	int _permission;
	
	bool _delete_user = false;

	static cls_bank_user _convert_line_to_user_object(string line)
	{
		vector<string>vclient;
		vclient = clsString::Split(line, "#//#");
		return cls_bank_user(enmode::updatemode, vclient[0], vclient[1], vclient[2]
			, vclient[3], vclient[4], decrypt_password(vclient[5]), stoi(vclient[6]));
	}
	static string _convert_object_to_line(cls_bank_user obj)
	{
		string data = "";
		data += obj.firstname + "#//#";
		data += obj.lastname + "#//#";
		data += obj.email + "#//#";
		data += obj.phone + "#//#";
		data += obj._username + "#//#";
		data += _encrypt_password(obj._password) + "#//#";
		data += to_string(obj._permission);

		return data;
	}

	static vector<cls_bank_user> _users_from_file()
	{
		vector< cls_bank_user>users;
		fstream file;
		file.open("users.txt", ios::in);
		string data;
		while (getline(file, data))
		{
			users.push_back(_convert_line_to_user_object(data));
		}
		file.close();
		return users;
	}

	static cls_bank_user _get_empty_user_to_bject()
	{
		return cls_bank_user(emptymode, "", "", "", "", "", "", 0);
	}

	void _update()
	{
		vector <cls_bank_user> clientsdata;
		clientsdata = _users_from_file();

		for (cls_bank_user& client : clientsdata)
		{
			if (client._username == _username)
			{
				client = *this;
				break;
			}
		}
		_save_users_in_file(clientsdata);
	}

	void _save_users_in_file(vector <cls_bank_user> d)
	{
		fstream file;
		string h;
		file.open("users.txt", ios::out);

		for (cls_bank_user s : d)
		{
			if (s._delete_user == false)
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
		file.open("users.txt", ios::app);
		h = (data);
		file << h << endl;
		file.close();
	}

	static string _encrypt_password(string pass)
	{
		int key = 17;
		string enc="";
		for (char c : pass)
		{
			enc+= char(int(c) + key);
		}
		return enc;
	}
	
	string _prepare_data_to_login(string separater="#//#")
	{
		string date="";
		date += clsDate::get_time_string() + separater;
		date += username + separater;
		date += _encrypt_password(password) + separater;
		date += to_string(permissions);
		return date;
	}
public:
	enum enpermission {
		all = -1, en_list_users = 1, en_add_user = 2, en_delete_user = 4, en_update_user = 8, en_find_user = 16
		, en_transactions = 32, en_manage_users = 64, en_login_register=128
	};

	cls_bank_user(enmode mode, string firstname, string lastname, string email, string phone
		, string username, string pass, int permision)
		:clsPerson(firstname, lastname, email, phone)
	{
		_enum_mode = mode;
		_username = username;
		_permission = permision;
		_password = pass;
	}

	bool is_empty()
	{
		return (_enum_mode == enmode::emptymode);
	}

	string GetUserName()
	{
		return _username;
	}

	void SetUserName(string UserName)
	{
		_username = UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string username;

	void SetPassword(string Password)
	{
		_password = Password;
	}

	string GetPassword()
	{
		return _password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string password;

	void SetPermissions(int Permissions)
	{
		_permission = Permissions;
	}

	int GetPermissions()
	{
		return _permission;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int permissions;

	static cls_bank_user find(string username)
	{
		fstream file;
		file.open("users.txt", ios::in);
		string data;
		int i = 0;
		while (getline(file, data))
		{
			cls_bank_user user1 = cls_bank_user::_convert_line_to_user_object(data);
			if (user1._username == username)
			{
				file.close();
				return user1;
			}
		}
		file.close();
		return _get_empty_user_to_bject();
	}

	static cls_bank_user find(string usernamee, string pin)
	{
		fstream file;
		file.open("users.txt", ios::in);
		string data;
		while (getline(file, data))
		{
			cls_bank_user user1 = cls_bank_user::_convert_line_to_user_object(data);
			if (user1._username == usernamee && user1._password == pin)
			{
				file.close();
				return user1;
			}
		}
		file.close();
		return _get_empty_user_to_bject();
	}

	static bool is_user_exist(string usernamee)
	{
		vector< cls_bank_user>client;
		fstream file;
		file.open("users.txt", ios::in);
		string data;
		int i = 0;
		while (getline(file, data))
		{
			client.push_back(_convert_line_to_user_object(data));
			if (client[i]._username == usernamee)
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

	static cls_bank_user get_new_user(string username)
	{
		return cls_bank_user(enmode::addnewmode, "", "", "", "", username, "", 0);
	}

	void delet()
	{
		vector<cls_bank_user>users;
		users = _users_from_file();
		for (cls_bank_user& c : users)
		{
			if (c._username == _username)
			{
				c._delete_user = true;
			}
		}
		_save_users_in_file(users);
		*this = _get_empty_user_to_bject();
	}

	static vector<cls_bank_user> get_users_list()
	{
		return _users_from_file();
	}

	bool check_user_permissions(enpermission enmodee)
	{
		if (this->permissions == enpermission::all)
		{
			return true;
		}
		if ((this->permissions & enmodee) == enmodee)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void save_login_data_to_file()
	{
		string data = _prepare_data_to_login();
		fstream file;
		file.open("login_dataa.txt", ios::app);
		file << data << endl;
		file.close();
	}

	static string decrypt_password(string pass)
	{
		int key = 17;
		string enc = "";
		for (char c : pass)
		{
			enc += char(int(c) - key);
		}
		return enc;
	}


};

