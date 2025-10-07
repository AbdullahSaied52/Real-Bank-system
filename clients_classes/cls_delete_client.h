#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class cls_delete_client :protected cls_screen
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
    static void deleteclient()
    {
        if (!check_user_screen(cls_bank_user::enpermission::en_delete_user))
            return;

        _headersscreen("delete screen ");
        string accnum;
        cout << "enter account number: ";
        cin >> accnum;
        while (!clsBankClient::is_client_exist(accnum))
        {
            cout << "incorrect enter again: ";
            cin >> accnum;
        }
        clsBankClient client1 = clsBankClient::find(accnum);
        _printclient(client1);
        cout << "do you want to delete(y/n): ";
        string ask;
        cin >> ask;
        if (ask == "y")
        {
            client1.delet();
            cout << "\ndeleted " << endl;
        }
        _printclient(client1);
    }
};
