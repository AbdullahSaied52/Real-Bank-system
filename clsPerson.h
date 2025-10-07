#pragma once
#include<iostream>
#include <string>
using namespace std;

class clsPerson
{
private:
	string _firstname, _lastname, _email, _phone;
public:
	clsPerson(string fn, string ln, string email, string ph)
	{
		_firstname = fn;
		_lastname = ln;
		_email = email;
		_phone = ph;
	}
	// property set
	void setfirstname(string fn)
	{
		_firstname = fn;
	}
	void setlastname(string ln)
	{
		_lastname = ln;
	}
	void setemail(string e)
	{
		_email = e;
	}
	void setphone(string ph)
	{
		_phone = ph;
	}
	//property get
	string getfirstname()
	{
		return _firstname;
	}
	string getlastname()
	{
		return _lastname;
	}
	string getemail()
	{
		return _email;
	}
	string getphone()
	{
		return _phone;
	}
	//summary property
	__declspec(property(get = getfirstname, put = setfirstname)) string firstname;
	__declspec(property(get = getlastname, put = setlastname)) string lastname;
	__declspec(property(get = getemail, put = setemail)) string email;
	__declspec(property(get = getphone, put = setphone)) string phone;
	string fullname()
	{
		return _firstname + " " + _lastname;
	}
	void print()
	{
		cout << "\n-----------------" << endl;
		cout << "first name : " << _firstname << endl;
		cout << "last name : " << _lastname << endl;
		cout << "full name : " << fullname();
		cout << "email : " << _email << endl;
		cout << "phone : " << _phone << endl;
	}
};

