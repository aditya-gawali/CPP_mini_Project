#include <bits/stdc++.h>
using namespace std;

class payment
{
    int random_otp = 12345 + (rand() % 123456);
    char account_number[50];
    char account_holder[50];
    char card_cvv[10];
    int otp;

public:
    void getdata();
};

void payment::getdata()
{
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Account Number : ";
    cin.getline(account_number, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Account Holder Name : ";
    cin.getline(account_holder, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Card CVV number : ";
    cin.getline(card_cvv, 10);
    cin.ignore();
    cout << "\n\n";
    tab_print(6);
    cout << "OTP :-" << random_otp;
    cin.get();
    cin.ignore();
pabc:
    cout << "\n\n";
    tab_print(3);
    cout << "Enter OTP : ";
    cin >> otp;
    if (otp == random_otp)
    {
        cout << "\n\n";
        tab_print(3);
        cout << "Payment Successfully completed...";
        cin.get();
        cin.ignore();
    }
    else
    {
        cout << "\n\n";
        tab_print(3);
        cout << "please enter correct OTP...";
        cin.get();
        goto pabc;
    }
}

void payment_page()
{
    system("cls");
    system("color F0");
    page_heading("Transaction");
    payment p1;
    p1.getdata();
};