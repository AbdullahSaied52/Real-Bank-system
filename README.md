Real Bank System 🏦
A comprehensive banking system built with C++ using Object-Oriented Programming (OOP) principles, designed to simulate real-world banking operations.

⚙️ Technologies Used

Language: C++ (99.9%)
Paradigm: Object-Oriented Programming (OOP)
IDE: Visual Studio
Storage: Text-based flat files (.txt)


🔑 Features & Functionality
Security & Authentication

Secure login system (cls_login.h) with login history tracking
User permissions and access management (users_classes)
Input validation layer (clsInputValidate.h)

Client Management

Add, update, and delete client records (clients_classes)
Full client listing stored persistently (clients.txt)

Banking Operations

Deposits and withdrawals (cls_transaction_screen.h)
Fund transfers between accounts (cls_transfare.h)
Transfer history log (cls_transfare_list.h)
Total balance calculation across all accounts (cls_total_balance.h)

Currency Exchange

Multi-currency support (cls_curency.h, Currencies.txt)
Currency conversion calculator (cls_currency_calculator.h)
Currency search (cls_find_currency.h)
Exchange rate updates (cls_update_rate.h)


🗂️ Project Structure
The project is well-organized with dedicated header files for each feature, maintaining a clean separation between client logic (clients_classes) and user management (users_classes) — reflecting solid understanding of OOP principles like Separation of Concerns and Encapsulation.

📝 Note
This is a learning-oriented project that demonstrates a strong grasp of C++ and real-world system design, featuring a rich set of classes and functionalities that bring it close to production-level banking software architecture.
