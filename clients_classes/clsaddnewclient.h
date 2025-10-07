#pragma once
#include <iostream>
#include "clsscreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
class clsaddnewclient :protected cls_screen
{
private:
    static void _readclientinfo(clsBankClient& client)
    {
        cout << "\nEnter FirstName: ";
        client.firstname = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        client.lastname = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        client.email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        client.phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        client.pincode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        client.accountbalance = clsInputValidate::ReadFloatNumber();
    }

    static void _printclient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.firstname;
        cout << "\nLastName    : " << Client.lastname;
        cout << "\nFull Name   : " << Client.fullname();
        cout << "\nEmail       : " << Client.email;
        cout << "\nPhone       : " << Client.phone;
        cout << "\nAcc. Number : " << Client.accountnumber();
        cout << "\nPassword    : " << Client.pincode;
        cout << "\nBalance     : " << Client.accountbalance;
        cout << "\n___________________\n";
    }

public:
    static void add_new_client()
    {
        if (!check_user_screen(cls_bank_user::enpermission::en_add_user))
            return;

        _headersscreen("Add new client screen");
        cout << "enter account number: ";
        string accnum;
        cin >> accnum;
        while (clsBankClient::is_client_exist(accnum))
        {
            cout << "enter another account number ,as he's exist: ";
            cin >> accnum;
        }
        clsBankClient client1 = clsBankClient::get_new_client(accnum);
        _readclientinfo(client1);

        clsBankClient::enumsavemode save;
        save = client1.save_results();
        if (save == clsBankClient::enumsavemode::savesuccess)
        {
            cout << "\n save success \n";
        }
        else if (save == clsBankClient::enumsavemode::savefailed)
        {
            cout << "\n save failed\n";
        }
        _printclient(client1);
    }
};

