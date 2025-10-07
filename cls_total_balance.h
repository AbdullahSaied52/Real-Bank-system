#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsBankClient.h"
using namespace std;

class cls_total_balance :protected cls_screen
{
private:
    static void _printClientRecordLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.accountnumber();
        cout << "| " << setw(20) << left << Client.fullname();
        cout << "| " << setw(12) << left << Client.accountbalance;

    }
public:
    static void total_balnce()
    {
        _headersscreen(" totla balance screen ");
        vector<clsBankClient> clients;
        clients = clsBankClient::get_clients_list();
        cout << "\n\t\t\t\t\tClient List (" << clients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
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

