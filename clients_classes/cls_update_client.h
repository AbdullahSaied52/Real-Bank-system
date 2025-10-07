#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class cls_update_client :protected cls_screen
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
public:
    static void updateclient()
    {
        if (!check_user_screen(cls_bank_user::enpermission::en_update_user))
            return;
        _headersscreen("update screen ");
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
        client1.print();
        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";
        _readclientinfo(client1);
        clsBankClient::enumsavemode saveresults1;
        saveresults1 = client1.save_results();
    }
};

