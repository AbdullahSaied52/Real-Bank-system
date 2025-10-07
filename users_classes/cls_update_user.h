#pragma once
#include <iostream>
#include "clsscreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "cls_bank_user.h"

using namespace std;
class cls_update_user :protected cls_screen
{
private:
    static void _read_user_info(cls_bank_user& user)
    {
        cout << "\nEnter FirstName: ";
        user.firstname = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        user.lastname = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        user.email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        user.phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        user.password = clsInputValidate::ReadString();

        user.permissions = read_permissions();
    }
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
    static int read_permissions()
    {
        int permissions = 0;
        char ans = 'n';
        cout << "do you want to give full permissionsy/n? ";
        cin >> ans;
        if (ans == 'y')
        {
            return -1;
        }
        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> ans;
        if (ans == 'y')
            permissions += cls_bank_user::enpermission::en_list_users;
        cout << "\nAdd New Client? y/n? ";
        cin >> ans;
        if (ans == 'y')
            permissions += cls_bank_user::enpermission::en_add_user;
        cout << "\n Delete client y/n? ";
        cin >> ans;
        if (ans == 'y')
            permissions += cls_bank_user::enpermission::en_delete_user;
        cout << "Update client y/n? ";
        cin >> ans;
        if (ans == 'y')
            permissions += cls_bank_user::enpermission::en_update_user;
        cout << "Find client y/n? ";
        cin >> ans;
        if (ans == 'y')
            permissions += cls_bank_user::enpermission::en_find_user;
        cout << "Transactions y / n ? ";
        cin >> ans;
        if (ans == 'y')
            permissions += cls_bank_user::enpermission::en_transactions;
        cout << "Manage users y/n? ";
        cin >> ans;
        if (ans == 'y')
            permissions += cls_bank_user::enpermission::en_manage_users;
        cout << "login register users y/n? ";
        cin >> ans;
        if (ans == 'y')
            permissions += cls_bank_user::enpermission::en_login_register;
        return permissions;
    }
public:
    static void update_user()
    {
        _headersscreen("update user screen ");
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
        cout << "do you want to update this user y/n?";
        string ask;
        cin >> ask;
        if (ask == "y")
            _read_user_info(user);
        _print_user(user);

        cls_bank_user::enumsavemode save;
        save = user.save_results();
        if (save == clsBankClient::enumsavemode::savesuccess)
        {
            cout << "\n save success \n";
            _print_user(user);
        }
        else if (save == clsBankClient::enumsavemode::savefailed)
        {
            cout << "\n save failed\n";
        }
    }

};

