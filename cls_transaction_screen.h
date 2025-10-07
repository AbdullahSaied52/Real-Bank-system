#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"cls_deposite.h"
#include"cls_withdraw.h"
#include "cls_total_balance.h"
#include"cls_transfare.h"
#include "cls_transfare_list.h"
using namespace std;
class cls_transaction_screen :protected cls_screen
{
private:
    enum enumtransaction {
        enum_deposit = 1, enum_withdraw = 2,
        enum_show_total_balance = 3, enum_transfare = 4,enum_trnasfare_list=5, enum_show_main_menue = 6
    };
    static short _read_transactions_menueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
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
    static void _ShowDepositScreen()
    {
        cls_deposite::deposite_screen();
    }
    static void _ShowWithdrawScreen()
    {
        cls_withdraw::withdraw_screen();
    }
    static void _ShowTotalBalancesScreen()
    {
        cls_total_balance::total_balnce();
    }
    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }
    static void _transfare()
    {
        cls_transfare::transfare();
    }

    static void _transfare_list()
    {
        cls_transfare_list::tranfare_register();
    }


    static void _PerformTransactionsMenueOption(enumtransaction TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enumtransaction::enum_deposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enumtransaction::enum_withdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enumtransaction::enum_show_total_balance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enum_transfare:
        {
            system("cls");
            _transfare();
            _GoBackToTransactionsMenue();
            break;
        }
        case enum_trnasfare_list:
        {
            system("cls");
            _transfare_list();
            _GoBackToTransactionsMenue();
            break;
        }
        case enumtransaction::enum_show_main_menue:
        {
            //do nothing here the main screen will handle it :-) ;
        }

        }


    }
public:
    static void ShowTransactionsMenue()
    {
        if (!check_user_screen(cls_bank_user::enpermission::en_transactions))
            return;
        system("cls");
        _headersscreen("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfare.\n";
        cout << setw(37) << left << "" << "\t[5] Transfare list.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enumtransaction)_read_transactions_menueOption());
    }
};

