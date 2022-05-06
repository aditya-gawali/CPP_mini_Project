#include <bits/stdc++.h>
#include "login.cpp"
#include "register.cpp"
using namespace std;
int logp_choice;

void login_page_option();
void login_page_main();

void login_page_options()
{
    cout << "\n\n";
    tab_print(5);
    cout << " 1. Register";
    tab_print(4);
    cout << " 2. Login";
    cout << "\n\n";
    tab_print(3);
    cout << "Please enter your choice :";
    cin >> logp_choice;
    cin.ignore();
    int success_id = 1;
    switch (logp_choice)
    {
    case 1:
        if (Register() == success_id)
        {
            login();
        }
        else
        {
            login_page_main();
        }
        break;
    case 2:
        login();
        break;
    default:
        cout << "\n\n";
        tab_print(3);
        cout << "Please enter valid choice....";
        cin.ignore();
        cin.get();
        login_page_main();
        break;
    }
}

void login_page_main()
{
    system("cls");
    system("color F0");
    page_heading("Login Page");
    login_page_options();
}