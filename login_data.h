#pragma once
using namespace std;
#include "global.h"
#include "clsDate.h"
#include <fstream>
#include<string>
class login_data
{
public:
	static void login_file_data()
	{
		fstream file;
		file.open("login_dataa.txt",ios::app);
		string datee;
		string user;
		user = current_userr.username+"#//#"+current_userr.password+"#//#"+to_string(current_userr.permissions);
		clsDate d = clsDate::clsDate();
		datee = clsDate::DateToString(d);
		file << datee << user << endl;
	}
};

