#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "cls_bank_user.h"
#include "clsInputValidate.h"
using namespace std;
#include<iomanip>
class cls_delete_user :protected cls_screen
{
private:
    static void _print_user(cls_bank_user User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";

        cout << "\nFull Name   : " << User.fullname();
        cout << "\nEmail       : " << User.email;
        cout << "\nPhone       : " << User.phone;
        cout << "\nUser Name   : " << User.username;
        cout << "\nPassword    : " << User.password;
        cout << "\nPermissions : " << User.permissions;;
        cout << "\n___________________\n";

    }
public:
    static void delete_user()
    {
        _headersscreen("delete user screen ");
        string username;
        cout << "enter username: ";
        cin >> username;
        while (!cls_bank_user::is_user_exist(username))
        {
            cout << "not exist, enter anoter one" << endl;
            cin >> username;
        }
        cls_bank_user user = cls_bank_user::find(username);
        _print_user(user);
        cout << "do you sure to delete this user y/n? ";
        string ask;
        cin >> ask;
        if (ask == "y")
        {
            cout << "deleted ";
            user.delet();
        }
        else
            cout << "not deleted";
    }
};

