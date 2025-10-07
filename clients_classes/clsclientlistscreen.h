#pragma once
#include <iostream>
#include "clsscreen.h"
#include "clsBankClient.h"
#include <iomanip>

class cls_client_list_screen :protected cls_screen
{
private:

    static void _printClientRecordLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.accountnumber();
        cout << "| " << setw(20) << left << Client.fullname();
        cout << "| " << setw(12) << left << Client.phone;
        cout << "| " << setw(20) << left << Client.email;
        cout << "| " << setw(10) << left << Client.pincode;
        cout << "| " << setw(12) << left << Client.accountbalance;

    }
public:
    static void showclientlest()
    {
        if (!check_user_screen(cls_bank_user::enpermission::en_list_users))
            return;

        vector<clsBankClient> clients;
        clients = clsBankClient::get_clients_list();
        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(clients.size()) + ") Client(s).";
        _headersscreen(Title, SubTitle);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        for (clsBankClient client : clients)
        {
            _printClientRecordLine(client);
            cout << endl;
        }
    }
};

