#pragma once
#include <iostream>
#include"cls_bank_user.h"
#include"clsDate.h"
#include"global.h"
#include<iomanip>
using namespace std;

class cls_screen
{
protected:
    static void _headersscreen(string title, string subtitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << title;
        if (subtitle != "")
        {
            cout << "\n\t\t\t\t\t  " << subtitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        if (!current_userr.is_empty())
        {
            cout << setw(37) << left << "" << "user name: " << current_userr.username << endl;
            clsDate d = clsDate::clsDate();
            cout << setw(37) << left << "" << "date :" << d.Day << "/" << d.Month << "/" << d.Year << endl;
        }
    }

    static bool check_user_screen(cls_bank_user::enpermission permsission)
    {
        if (!current_userr.check_user_permissions(permsission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
            return true;
    }
};

