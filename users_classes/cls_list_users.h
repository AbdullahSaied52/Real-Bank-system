#pragma once
#include <iostream>
#include "clsscreen.h"
#include "cls_bank_user.h"
#include <iomanip>
using namespace std;
class cls_list_users : protected cls_screen
{
private:
    static void _print_user(cls_bank_user User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.username;
        cout << "| " << setw(25) << left << User.fullname();
        cout << "| " << setw(12) << left << User.phone;
        cout << "| " << setw(20) << left << User.email;
        cout << "| " << setw(10) << left << User.password;
        cout << "| " << setw(12) << left << User.permissions;

    }
public:

    static void list_users()
    {
        vector<cls_bank_user>u;
        u = cls_bank_user::get_users_list();
        _headersscreen("users list screen ");
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
        for (cls_bank_user n : u)
        {
            _print_user(n);
            cout << endl;
        }
    }
};

