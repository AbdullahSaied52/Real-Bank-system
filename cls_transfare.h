#pragma once
using namespace std;
#include "clsscreen.h"
#include"clsBankClient.h"
#include"cls_deposite.h"
#include"cls_withdraw.h"
#include"cls_find_user.h"
class cls_transfare:protected cls_screen
{
private:
    static void _print_client(clsBankClient client)
    {
        cout << "\nUser Card:";
        cout << "\n___________________" << endl;;

        cout << "Full Name   : " << client.fullname() << endl;
        cout << "Account balance   : " << client.accountbalance<<endl;
        cout << "Account number    : " << client.accountnumber();
        cout << "\n___________________\n";

    }
    static clsBankClient _find_client()
    {
        string account_num;
        cin >> account_num;
        while (!clsBankClient::is_client_exist(account_num))
        {
            cout << "not exist, enter anoter one" << endl;
            cin >> account_num;
        }
        clsBankClient client = clsBankClient::find(account_num);
        return client;
    }
    static void _transfare_amount(clsBankClient c1, clsBankClient c2, int amount)
    {
        c1.accountbalance -= amount;
        c2.accountbalance += amount;
        cout << "do you sure (y/n)? ";
        string ask;
        cin >> ask;
        if (ask == "y")
        {
            c1.save_results();
            c2.save_results();
            cout << "\nafter transfare \n";
            _print_client(c1);
            _print_client(c2);
            clsBankClient::transfare_list(c1, c2, amount);
        }
        else
            return;
    }
public:
    static void transfare()
    {
        _headersscreen("transfare screen ");
        cout << "enter account number to transfare from: ";
        clsBankClient client1 = _find_client();
        _print_client(client1);

        cout << "enter account number to transfare to: ";
        clsBankClient client2=_find_client();
        _print_client(client2);
        int amount;
        do
        {
            cout << "enter amount to transfare: ";
            cin >> amount;
            if (client1.accountbalance < amount)
            {
                cout << "enter again this amount is large \n";
            }
        }
        while (client1.accountbalance < amount);

        _transfare_amount(client1, client2, amount);

    }

};

