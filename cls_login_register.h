#pragma once
#include"clsscreen.h"
#include "cls_bank_user.h"
#include "clsString.h"
class cls_login_register:protected cls_screen
{
private:
    string _time;
    string _username;
    string _permission;
    string _password;
    static void _print_user(cls_login_register User)
    {
        cout << setw(8) << left << "" << "| " << left << setw(20) << User._time;
        cout << setw(8) << left << "" << "| " << setw(12) << left << User._username;
        cout << "| " << setw(10) << left << User._password;
        cout << "| " << setw(12) << left << User._permission;
        cout << endl;

    }

    static cls_login_register convert_line_to_object(string l)
    {
        vector<string>v;
        v = clsString::Split(l,"#//#");
        return cls_login_register(v[0], v[1], cls_bank_user::decrypt_password(v[2]), v[3]);
    }
    static vector<cls_login_register> get_time_login_users()
    {
        fstream file;
        file.open("login_dataa.txt", ios::in);
        vector<cls_login_register>dates;

        string data;
        while (getline(file, data))
        {
            dates.push_back(convert_line_to_object(data));
        }

        return dates;
    }
public:
    cls_login_register(string time , string username, string pass, string  permission)
    {
        _username = username;
        _time = time;
        _password = pass;
        _permission = permission;
    }
    static void login_register_data()
    {
        if (!check_user_screen(cls_bank_user::enpermission::en_login_register))
            return;
        vector< cls_login_register> data;
        data = get_time_login_users();
        _headersscreen("login register "," "+ to_string(data.size()) + " records ");
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(20) << "time";
        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        for (cls_login_register u : data)
        {
            _print_user(u);
        }
	}
};

