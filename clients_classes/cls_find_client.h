#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class cls_find_client :protected cls_screen
{
private:
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
    static void find_client()
    {
        if (!check_user_screen(cls_bank_user::enpermission::en_find_user))
            return;
        _headersscreen("find clinet screen");
        string accnumber;
        cout << "enter account number: ";
        cin >> accnumber;
        clsBankClient client1 = clsBankClient::find(accnumber);
        while (client1.is_empty())
        {
            cout << "enter correct account number: ";
            cin >> accnumber;
            client1 = clsBankClient::find(accnumber);
        }
        _printclient(client1);

    }
};

